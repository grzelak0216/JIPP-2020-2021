#include "libs.hpp"
#include <sqlite3.h>

class Macierz
{
protected:
private:
    double **macierz;
    int kol;
    int wier;

public:
    //Konstruktory
    Macierz(int ilkol, int ilwier) //Konstruktor macierzy prostokatnej
    {
        kol = ilkol;
        wier = ilwier;
        macierz = new double *[ilwier];
        for (int j = 0; j < ilwier; j++)
        {
            macierz[j] = new double[ilkol];

            for (int i = 0; i < ilkol; i++)
            {
                macierz[j][i] = 0;
            }
        }
    }

    Macierz(int wymiar) //Konstruktor macierzy kwadratowej
    {
        kol = wymiar;
        wier = wymiar;
        macierz = new double *[wymiar];
        for (int j = 0; j < wymiar; j++)
        {
            macierz[j] = new double[wymiar];

            for (int i = 0; i < wymiar; i++)
            {
                macierz[j][i] = 0;
            }
        }
    }

    Macierz(string filename, string path) //Konstruktor macierzy pobranej z pliku
    {
        fstream plik;
        plik.open(path + filename, ios::in);
        if (plik.good() == false)
        {
            cout << "\n Plik ERROR \n";
            exit(0);
        }
        else
        {
            plik >> Macierz::kol;
            cout << kol << " ";
            plik >> Macierz::wier;
            cout << wier << " \n";

            macierz = new double *[kol];
            for (int j = 0; j < kol; j++)
            {
                macierz[j] = new double[wier];

                for (int i = 0; i < wier; i++)
                {
                    plik >> Macierz::macierz[j][i];
                }
            }
        }
        plik.close();
    }

    ~Macierz() //Destruktor
    {
        for (int j = 0; j < wier; j++)
        {
            delete[] macierz[j];
        }
        delete[] macierz;
        cout << " destruktor \n";
    }

    void set(int x, int y, double wart) //Ustawianie wartosci w macierzy
    {
        macierz[x][y] = wart;
    }

    void get(int x, int y) //Pobieranie wartosci z macierzy
    {
        cout << "\n wartosc: [ " << macierz[x][y] << " ] - ( " << x << " )( " << y << " ) \n";
    }

    void print() //Wyswietlanie macierzy
    {
        for (int j = 0; j < wier; j++)
        {
            for (int i = 0; i < kol; i++)
            {
                cout << "[ " << macierz[j][i] << " ] ";
            }
            cout << "\n";
        }
    }

    void add(Macierz &Macierz2) //Dodawanie macierzy
    {
        for (int j = 0; j < wier; j++)
        {
            for (int i = 0; i < kol; i++)
            {
                Macierz2.set(j, i, (macierz[j][i] + Macierz2.macierz[j][i]));
            }
            cout << "\n";
        }
    }

    void subtract(Macierz &Macierz2) //Odejmowanie macierzy
    {
        for (int j = 0; j < wier; j++)
        {
            for (int i = 0; i < kol; i++)
            {
                Macierz2.set(j, i, (macierz[j][i] - Macierz2.macierz[j][i]));
            }
            cout << "\n";
        }
    }

    void multiply(Macierz &Macierz2) //Mnozenie dwoch macierzy
    {
        double wart;
        if (kol == Macierz2.wier) //Warunek mnozenia macierzy
        {
            for (int j = 0; j < wier; j++)
            {
                for (int i = 0; i < kol; i++)
                {
                    wart = 0;
                    for (int o = 0; o < kol; o++)
                    {
                        wart += macierz[j][o] * Macierz2.macierz[o][i];
                    }
                    Macierz2.set(j, i, wart);
                }
            }
        }
        else
        {
            cout << "\n bledna liczba kolumn lub wierszy \n";
        }
    }

    void cols() //Wyswietlanie liczby kolum macierz
    {
        cout << "\n liczba kolumn macierzy: " << kol << endl;
    }

    void rows() //Wyswietlanie liczby wierszy macierz
    {
        cout << "\n liczba wierszy macierzy: " << wier << endl;
    }

    void store(string filename, string path) //Zapis macierzy do pliku
    {
        sqlite3 *db;          // struktura bazy danych
        int test;             // zwracany status po wyknaniu każdego polecenia
        char *error;          // komunikat zwrotny w przypadku wystapienia bledu
        string dane;          // dane do drugiej kwerendy
        unsigned char *bajty; // zamiana elementow macierzy na postac binarną
        stringstream strumien;
        char bajt[3];

        test = sqlite3_open((path + "/" + filename).c_str(), &db);

        if (test != SQLITE_OK)
        {
            cout << "Nie udalo sie otworzyc pliku \"" << path << "\"!" << endl;
            return;
        }

        const char *kwerenda_1 =
            "CREATE TABLE IF NOT EXISTS macierze ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "cols INTEGER NOT NULL, "
            "rows INTEGER NOT NULL, "
            "cells BLOB NOT NULL"
            ");";

        const char *kwerenda_2 =
            "INSERT INTO macierze "
            "(cols, rows, cells) "
            "VALUES ";

        // utworzenie tabeli w bazie danych
        cout << "Wykonujemy kwerende: " << kwerenda_1 << endl;
        test = sqlite3_exec(db, kwerenda_1, NULL, NULL, &error);

        if (test != SQLITE_OK)
        {
            sqlite3_close(db);

            cout << "Nie udalo sie dodac tabeli do bazy danych!" << endl;
            cout << "Komunkat: " << error << endl;

            return;
        }

        // musimy zamienic dane z tej macierzy na tekst
        strumien << kwerenda_2 << "(" << kol << ", " << wier << ", x'";

        // zamieniamy tablice DOUBLE na strumien bajtow
        cout << "Zamiana elementow na strumien bajtow" << endl;

        for (int i = 0; i < wier; i++)
        {
            for (int j = 0; j < kol; j++)
            {
                bajty = (unsigned char *)&(macierz[i][j]);

                for (int k = 0; k < sizeof(double); k++)
                {
                    sprintf(bajt, "%02X", bajty[k]);
                    strumien << bajt;
                }
            }
        }

        strumien << "');";

        // dodanie macierzy do tabeli
        cout << "Wykonujemy kwerende: " << strumien.str() << endl;
        test = sqlite3_exec(db, strumien.str().c_str(), NULL, NULL, &error);

        if (test != SQLITE_OK)
        {
            sqlite3_close(db);

            cout << "Nie udalo sie dodac rekordu do tabeli w bazie danych!" << endl;
            cout << "Komunikat: " << error << endl;

            return;
        }

        // zamykamy plik z bazą danych
        sqlite3_close(db);
    }
};

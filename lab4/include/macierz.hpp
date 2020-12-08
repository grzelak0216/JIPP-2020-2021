#include "libs.hpp"

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
        macierz = new double *[ilkol];
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
        fstream plik;
        plik.open(path + filename, ios::out);
        if (plik.good() == false)
        {
            cout << "\n Plik ERROR \n";
            exit(0);
        }
        else
        {
            plik << kol << " " << wier << "\n";
            for (int j = 0; j < wier; j++)
            {
                for (int i = 0; i < kol; i++)
                {
                    plik << macierz[j][i] << " ";
                }
                plik << "\n";
            }
        }
        plik.close();
    }
};

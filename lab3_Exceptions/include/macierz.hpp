#include "libs.hpp"

struct MatrixDimensionsException : public std::exception
{
    const char *what() throw()
    {
        return "Matrix_dimensions_exception \n";
    }
};

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
        try
        {
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
        catch (const std::bad_array_new_length &e)
        {
            std::cerr << e.what() << '\n';
            exit(1);
        }
        catch (const std::bad_alloc &e)
        {
            std::cerr << e.what() << '\n';
            exit(1);
        }
    }

    Macierz(int wymiar) //Konstruktor macierzy kwadratowej
    {
        kol = wymiar;
        wier = wymiar;

        try
        {
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
        catch (const std::bad_array_new_length &e)
        {
            std::cerr << e.what() << '\n';
            exit(1);
        }
        catch (const std::bad_alloc &e)
        {
            std::cerr << e.what() << '\n';
            exit(1);
        }
    }

    Macierz(string filename, string path) //Konstruktor macierzy pobranej z pliku
    {
        fstream plik;

        try
        {
            plik.open(path + filename, ios::in);
            plik >> Macierz::kol;
            cout << kol << " ";
            plik >> Macierz::wier;
            cout << wier << " \n";

            macierz = new double *[wier];
            for (int j = 0; j < wier; j++)
            {
                macierz[j] = new double[kol];

                for (int i = 0; i < kol; i++)
                {
                    plik >> Macierz::macierz[j][i];
                    // cout << " " << macierz[j][i] << " ";
                }
                //cout << endl;
            }
            plik.close();
        }
        catch (const fstream::failure &e)
        {
            std::cerr << e.what() << '\n';
        }
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

    Macierz &operator=(const Macierz &Macierz2)
    {
        int i, j;

        cout << "Operator przypisania macierzy." << endl;

        // 1. Skasowanie wskaźników z obecnego obiektu

        for (j = 0; j < wier; j++)
        {
            delete[](macierz[j]);
        }

        delete[](macierz);

        macierz = nullptr;

        // 2. Przypisanie danych z nowego obiektu
        // - najbezpieczniej stworzyć nowe wskaźniki

        wier = Macierz2.wier;
        kol = Macierz2.kol;

        try
        {
            macierz = new double *[wier];

            for (j = 0; j < wier; j++)
            {
                macierz[j] = nullptr;
            }

            for (j = 0; j < wier; j++)
            {
                macierz[j] = new double[kol];

                for (i = 0; i < kol; i++)
                {
                    macierz[j][i] = Macierz2.macierz[j][i];
                }
            }
        }
        catch (const std::bad_alloc &e)
        {
            std::cerr << e.what() << endl;
        }

        // 3. Koniec przypisywania - należy zwrócić odnośnik do
        // właśnie przypisanego obiektu - używamy operatora gwiazdki
        // na słowie kluczowym "this", które jest adresem tego obiektu

        return *this;
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
        if (Macierz2.kol != kol || Macierz2.wier != wier)
        {
            throw MatrixDimensionsException();
        }

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
        if (Macierz2.kol != kol || Macierz2.wier != wier)
        {
            throw MatrixDimensionsException();
        }

        for (int j = 0; j < wier; j++)
        {
            for (int i = 0; i < kol; i++)
            {
                Macierz2.set(j, i, (macierz[j][i] - Macierz2.macierz[j][i]));
            }
            cout << "\n";
        }
    }

    Macierz multiply(const Macierz &Macierz2) //Mnozenie dwoch macierzy
    {

        if (kol != Macierz2.wier)
        {
            throw MatrixDimensionsException();
        }

        Macierz wynik(wier, Macierz2.kol);

        double wart;
        for (int j = 0; j < wier; j++)
        {
            for (int i = 0; i < Macierz2.kol; i++)
            {
                wart = 0;
                for (int o = 0; o < kol; o++)
                {
                    wart += macierz[j][o] * Macierz2.macierz[o][i];
                }
                //cout << "\n " << wart;
                wynik.set(j, i, wart);
            }
        }
        return wynik;
    }

    void
    cols() //Wyswietlanie liczby kolum macierz
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
        try
        {
            plik.open(path + filename, ios::out);

            plik << kol << " " << wier << "\n";

            for (int j = 0; j < wier; j++)
            {
                for (int i = 0; i < kol; i++)
                {
                    plik << macierz[j][i] << " ";
                }
                plik << "\n";
            }
            plik.close();
        }
        catch (const fstream::failure &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
};

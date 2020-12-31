#include <iostream>
#include <fstream>

using namespace std;

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

    // Macierz(string filename, string path) //Konstruktor macierzy pobranej z pliku
    // {
    //     fstream plik;
    //     plik.open(path + filename, ios::in);
    //     if (plik.good() == false)
    //     {
    //         cout << "\n Plik ERROR \n";
    //         exit(0);
    //     }
    //     else
    //     {
    //         plik >> Macierz::kol;
    //         cout << kol << " ";
    //         plik >> Macierz::wier;
    //         cout << wier << " \n";

    //         macierz = new double *[kol];
    //         for (int j = 0; j < kol; j++)
    //         {
    //             macierz[j] = new double[wier];

    //             for (int i = 0; i < wier; i++)
    //             {
    //                 plik >> Macierz::macierz[j][i];
    //                 cout << " " << macierz[j][i] << " ";
    //             }
    //             cout << endl;
    //         }
    //     }
    //     plik.close();
    // }

    void destroy() //Destruktor
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

    int raws()
    {
        return kol;
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
    /*////////////////////////////////////////*/
    Macierz operator+(const Macierz Macierz2) const
    {
        Macierz Wynik(Macierz2.kol, Macierz2.wier);

        for (int j = 0; j < wier; j++)
        {
            for (int i = 0; i < kol; i++)
            {
                Wynik.set(j, i, (macierz[j][i] + Macierz2.macierz[j][i]));
            }
            cout << "\n";
        }
        return Wynik;
    }

    Macierz operator-(const Macierz Macierz2) const
    {
        Macierz Wynik(Macierz2.kol, Macierz2.wier);

        for (int j = 0; j < wier; j++)
        {
            for (int i = 0; i < kol; i++)
            {
                Wynik.set(j, i, (macierz[j][i] - Macierz2.macierz[j][i]));
            }
            cout << "\n";
        }
        return Wynik;
    }

    Macierz operator*(const Macierz Macierz2) const
    {
        Macierz Wynik(Macierz2.kol, wier);

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
                Wynik.set(j, i, wart);
            }
        }
        return Wynik;
    }

    friend void operator<<(std::ofstream &file, const Macierz &Macierz_save)
    {
        int i, j;
        file << Macierz_save.kol << " " << Macierz_save.wier << endl;

        for (j = 0; j < Macierz_save.wier; j++)
        {
            for (i = 0; i < Macierz_save.kol; i++)
            {
                file << Macierz_save.macierz[j][i] << " ";
            }

            file << endl;
        }
    }

    void operator==(Macierz Macierz2) const
    {
        int val = 1;
        if (kol == Macierz2.kol && wier == Macierz2.wier)
        {
            for (int j = 0; j < wier; j++)
            {
                for (int i = 0; i < kol; i++)
                {
                    if (macierz[j][i] != Macierz2.macierz[j][i])
                    {
                        val = 0;
                    }
                }
            }
        }
        else
        {
            val = 0;
        }

        if (val == 1)
        {
            cout << "\n Macierze sa takie same \n";
        }
        else
        {
            cout << "\n Macierze nie sa takie same \n";
        }
    }

    const double *operator[](int n) const
    {

        if ((n < 0) || (n > wier))
        {
            if (n < 0)
            {
                n = 0;
            }
            else
            {
                n = wier;
            }
        }
        return macierz[n];
    }
};

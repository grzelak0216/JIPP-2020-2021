#include <iostream>
#include <time.h>
#include "../include/header.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    // srand(time(NULL));
    int k, w;
    double pom;

    k = 3;
    w = 2;

    Macierz Macierz1(k, w);

    for (int j = 0; j < w; j++)
    {
        for (int i = 0; i < k; i++)
        {
            pom = rand() % 10;
            //pom = i + j;
            //cout << pom << " ";
            Macierz1.set(j, i, pom);
        }
        //cout << "\n";
    }

    Macierz Macierz2(k, w);

    for (int j = 0; j < w; j++)
    {
        for (int i = 0; i < k; i++)
        {
            pom = rand() % 10;
            //pom = i + j;
            //cout << pom << " ";
            Macierz2.set(j, i, pom);
        }
        //cout << "\n";
    }

    cout << "\n macierz1: \n";
    Macierz1.print(); //Wyswietlanie zawatrosci macierzy
    cout << "\n macierz2: \n";
    Macierz2.print(); //Wyswietlanie zawatrosci macierzy

    cout << "\n poruwnywanie\n"
         << endl;
    Macierz1 == Macierz2;

    Macierz Macierz3(k, w);

    Macierz3.print(); //Wyswietlanie zawatrosci macierzy
    cout << endl;

    cout << "\n dodawanie\n"
         << endl;

    Macierz3 = Macierz1 + Macierz2;

    cout << "\n wynik :\n";
    Macierz3.print(); //Wyswietlanie zawatrosci macierzy
    cout << endl;

    for (int j = 0; j < w; j++)
    {
        for (int i = 0; i < k; i++)
        {
            pom = rand() % 10;
            //pom = i + j;
            //cout << pom << " ";
            Macierz1.set(j, i, pom);
        }
        //cout << "\n";
    }

    for (int j = 0; j < w; j++)
    {
        for (int i = 0; i < k; i++)
        {
            pom = rand() % 10;
            //pom = i + j;
            //cout << pom << " ";
            Macierz2.set(j, i, pom);
        }
        //cout << "\n";
    }

    cout << "\n odejmowanie \n macierz1: \n";
    Macierz1.print();
    cout << "\n macierz1: \n";
    Macierz2.print();

    Macierz3 = (Macierz1 - Macierz2);

    cout << "\n wynik :\n";
    Macierz3.print(); //Wyswietlanie zawatrosci macierzy
    cout << endl;

    cout << "\n poruwnywanie\n"
         << endl;
    Macierz1 == Macierz2;

    Macierz Multiply1(k, k);

    for (int j = 0; j < k; j++)
    {
        for (int i = 0; i < k; i++)
        {
            pom = rand() % 10;
            //pom = i + j;
            //cout << pom << " ";
            Multiply1.set(j, i, pom);
        }
        //cout << "\n";
    }

    Macierz Multiply2(k, k);

    for (int j = 0; j < k; j++)
    {
        for (int i = 0; i < k; i++)
        {
            pom = rand() % 10;
            //pom = i + j;
            //cout << pom << " ";
            Multiply2.set(j, i, pom);
        }
        //cout << "\n";
    }

    cout << "\n mnorzenie \n macierz1: \n";
    Multiply1.print(); //Wyswietlanie zawatrosci macierzy
    cout << "\n macierz2: \n";
    Multiply2.print(); //Wyswietlanie zawatrosci macierzy

    Macierz3 = Multiply1 * Multiply2;

    cout << "\n wynik :\n";
    Macierz3.print();
    cout << "\n";

    ofstream file;
    file.open("matrix.txt");
    file << Macierz3;
    file.close();

    Macierz Macierz4(4, 4);

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            pom = i + j;
            Macierz4.set(j, i, pom);
        }
        //cout << "\n";
    }

    Macierz4.print();

    int n = Macierz4.raws();

    const double *tab = Macierz4[1];

    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;

    Macierz Macierz5(4, 4);

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            pom = i + j;
            Macierz5.set(j, i, pom);
        }
        //cout << "\n";
    }

    Macierz Macierz6(4, 4);

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            pom = i + j;
            Macierz6.set(j, i, pom);
        }
        //cout << "\n";
    }
    //wybrać 3 operatory i je przeładować
    cout << "\n\n dodatkowe\n";
    Macierz5.print();
    Macierz5 &(0);
    Macierz5();
    Macierz5 >> Macierz6;
    Macierz5();
    Macierz6();

    Macierz5.destroy();
    Macierz6.destroy();
    Macierz4.destroy();
    Macierz3.destroy();
    Multiply1.destroy();
    Multiply2.destroy();
    Macierz2.destroy();
    Macierz1.destroy();

    //koniec
    return 0;
}
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int macierz1[2][3], macierz2[2][3], macierz3[2][3];

    for (int i = 0; i < 2; i++)  //uzupelnianie macierzy liczbami losowymi (od 0 do 99)
    {
        for (int j = 0; j < 3; j++)
        {
            macierz1[i][j] = rand() % 100;
            macierz2[i][j] = rand() % 100;
        }
    }

    cout << "\n macierz nr 1: \n";  //wyswietlanie zawartosci macierzy
    for (int i = 0; i < 2; i++)  
    {
        for (int j = 0; j < 3; j++)
        {
            cout << macierz1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n macierz nr 2: \n";  //wyswietlanie zawartosci macierzy
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << macierz2[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 2; i++)  //dodawanie macierzy
    {
        for (int j = 0; j < 3; j++)
        {
            macierz3[i][j] = macierz2[i][j] + macierz1[i][j];
        }
    }

    cout << "\n macierz wynikowa: \n";  //wyswietlanie zawartosci macierzy
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << macierz3[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

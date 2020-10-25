#include <iostream>
#include <math.h>

using namespace std;

int suma(int liczba) // Funkcja zliczajaca dzialniki danej liczby
{
    int wartosc = 0;
    int i = 1;
    while (i < liczba)
    {
        if (liczba % i == 0)
        {
            wartosc += i;
        }
        i++;
    }

    return wartosc;
}

int main(int argc, char *argv[])
{
    int a, b;
    int suma_a, suma_b;
    cout << "Podaj dwie liczby " << endl;
    cin >> a;
    cin >> b;

    suma_a = suma(a);
    suma_b = suma(b);

    cout << "\n suma a = " << suma_a << "\n suma b = " << suma_b << endl;

    if (suma_a == b + 1 && suma_b == a + 1) //Warunek na skojarzenie liczb
        cout << " liczby sa skojarzone" << endl;
    else
    {
        cout << " liczby nie sa skojarzone" << endl;
    }

    return 0;
}

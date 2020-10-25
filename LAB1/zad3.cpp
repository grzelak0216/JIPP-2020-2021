#include <iostream>
#include <cmath>

using namespace std;

// Zakresy wartoœci BMI:
// mniej ni¿ 16 - wyg³odzenie
// 16 - 16.99 - wychudzenie

// 17 - 18.49 - niedowaga
// 18.5 - 24.99 - wartoœæ prawid³owa

// 25 - 29.99 - nadwaga
// 30 - 34.99 - I stopieñ oty³oœci

// 35 - 39.99 - II stopieñ oty³oœci
// powy¿ej 40 - oty³oœæ skrajna

int main(int argc, char *argv[])
{
    cout << "Kalkulator BMI " << endl;

    double BMI;
    float waga, wzrost;

    cout << " \n podaj swoja wage[kg] i wzrost[cm]: \n";
    cin >> waga;
    cin >> wzrost;

    wzrost = wzrost / 100; // Zmiana jednostki wzrostu

    BMI = waga / pow(wzrost, 2); // Wzór na BMI

    if (BMI < 25) //max 3 porówania na dzia³anie programu
    {
        if (BMI < 17)
        {
            if (BMI < 16)
            {
                cout << BMI << " wyglodzenie " << endl;
            }
            else
            {
                cout << BMI << " wychudzenie " << endl;
            }
        }
        else
        {
            if (BMI < 18.5)
            {
                cout << BMI << " niedowaga " << endl;
            }
            else
            {
                cout << BMI << " wartosc prawidlowa " << endl;
            }
        }
    }
    else
    {
        if (BMI < 35)
        {
            if (BMI < 30)
            {
                cout << BMI << " nadwaga " << endl;
            }
            else
            {
                cout << BMI << " I stopien osylosci " << endl;
            }
        }
        else
        {
            if (BMI < 40)
            {
                cout << BMI << " II stopien osylosci " << endl;
            }
            else
            {
                cout << BMI << " skarja otylosc " << endl;
            }
        }
    }

    cout << endl
         << " Koniec programu " << endl;

    return 0;
}

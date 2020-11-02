#include <iostream>
#include <conio.h>

using namespace std;

void zamiana(int *a, int *b)
{
    int pom;
    if (*a > *b)
    {
        pom = *a;
        *a = *b;
        *b = pom;
    }
}

int main(int argc, char *argv[])
{
    int *liczba1 = NULL;
    int *liczba2 = NULL;
    int pom1, pom2;

    cout << " podaj 2 liczby: \n";
    cin >> pom1;
    liczba1 = &pom1;
    cin >> pom2;
    liczba2 = &pom2;

    zamiana(liczba1, liczba2);

    cout << *liczba1 << endl;
    cout << *liczba2 << endl;

    return 0;
}
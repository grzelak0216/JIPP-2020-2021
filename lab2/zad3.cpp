#include <iostream>
#include <conio.h>
using namespace std;

void refer_funk(int &a, int &b, int *c)
{
    int pom;
    pom = a;
    a = b;
    b = *c;
    *c = pom;
}

int main(int argc, char *argv[])
{
    int liczba1 = NULL, liczba2 = NULL;
    int pom;
    int *liczba3 = NULL;

    cout << " podaj 3 liczby: \n";
    cin >> liczba1;
    cin >> liczba2;
    cin >> pom;

    liczba3 = &pom;

    refer_funk(liczba1, liczba2, liczba3);

    cout << liczba1 << endl;
    cout << liczba2 << endl;
    cout << *liczba3 << endl;

    return 0;
}
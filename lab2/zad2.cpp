#include <iostream>
#include <conio.h>
using namespace std;

void referencja(int &a, int &b)
{
    int pom;
    pom = a;
    a = b;
    b = pom;
}

int main(int argc, char *argv[])
{
    int liczba1 = NULL;
    int liczba2 = NULL;

    cout << " podaj 2 liczby: \n";
    cin >> liczba1;
    cin >> liczba2;

    referencja(liczba1, liczba2);

    cout << liczba1 << endl;
    cout << liczba2 << endl;

    return 0;
}
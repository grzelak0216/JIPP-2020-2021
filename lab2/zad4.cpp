#include <iostream>
#include <conio.h>
using namespace std;

void operacje_matematyczne(int *a, int *b)
{
    int l1 = *a;
    int l2 = *b;
    *a = l1 + l2;
    *b = l1 * l2;
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

    operacje_matematyczne(liczba1, liczba2);

    cout << "suma:" << *liczba1 << endl;
    cout << "iloczyn:" << *liczba2 << endl;

    return 0;
}
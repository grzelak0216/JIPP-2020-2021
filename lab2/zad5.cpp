#include <iostream>
#include <conio.h>
using namespace std;

void test(int &a, int &b)
{
    int pom;
    pom = a;
    a = b;
    b = pom;
}

void zmiana(int &a, int &b)
{
    swap(a, b);
}

int main(int argc, char *argv[])
{
    int liczba1;
    int liczba2;

    int l_test1;
    int l_test2;

    cout << " podaj 2 liczby: \n";
    cin >> liczba1;
    cin >> liczba2;

    l_test1 = liczba1;
    l_test2 = liczba2;

    system("cls");

    cout << " \n       " << liczba1 << " " << liczba2 << endl;

    zmiana(liczba1, liczba2);

    cout << " \n wynik:" << liczba1 << " " << liczba2 << endl;

    cout << "\n test1: " << l_test2 << " " << l_test1 << endl;

    test(l_test1, l_test2);

    cout << "\n test2: " << l_test1 << " " << l_test2 << endl;
    return 0;
}
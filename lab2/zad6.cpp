#include <iostream>
#include <new>

#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
void swap(T &a, T &b, int i)
{
    b = (a + b) - (a = b);
    cout << "test \n";
}

int main(int argc, char *argv[])
{
    char liczba1, liczba2;
    int i = 0;

    cout << " podaj 2 liczby: \n";
    cin >> liczba1;
    cin >> liczba2;

    // liczba1 = (int)liczba1;
    // liczba2 = (int)liczba2;

    swap(liczba1, liczba2, i);

    cout << liczba1 << endl;
    cout << liczba2 << endl;

    return 0;
}
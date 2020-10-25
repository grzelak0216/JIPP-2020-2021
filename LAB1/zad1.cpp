#include <iostream>
#include <conio.h>
using namespace std;

int main(int argc, char *argv[])
{
    char koniec = 0;

    cout << " wprowadz ciag licz (koniec ciagu - ESC)" << endl;

    int i = 0;
    int tab[100];
    int liczba;

    while (koniec != 27) // Pentla uzupelniajaca tablice
    {
        cin >> liczba;
        tab[i] = liczba;
        cout << "\n koniec? (ESC/ENTER) -> "; // Przerwanie pentli
        koniec = getch();
        if (koniec != 27)
            i++;

        cin.clear();
    }

    int j = 0;
    int ind;

    for (j = 0; j < i; j++)
        cout << " " << tab[j] << " ";

    int k = i;

    cout << "\n Kolejne zamiany liczb wg. indeksow komorek \n "; // Kontrolne wyświetlenie
    for (j = 0; j < 25 - 1; j++)
    {
        ind = j; // Indeks kolejnej najmniejszej

        for (i = j + 1; i < k; i++) // Przeszukiwanie tablicy
            if (tab[i] < tab[ind])
                ind = i;        // Znaleziona kolejna najmniejsza
        swap(tab[ind], tab[j]); // Wstawienie kolejnej najmniejszej

        cout << "\n " << ind << " > " << j; // Kontrolne wyświetlenie kolejnych indeksów
    }

    for (j = 0; j < k; j++)
        cout << " " << tab[j] << " ";

    return 0;
}

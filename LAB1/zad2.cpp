#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main(int argc, char *argv[])
{
    string tekst;
    cout << "Wprowadz tekst do sprawdzenia: ";
    getline(cin, tekst);

    cout << tekst << endl;

    int rozmiar = tekst.length();
    int k = rozmiar - 1; //Zmienna pomocnicza przyjmujaca numer ostarniej komurki w tablicy 
    
    cout << rozmiar / 2 <<" "<< k << endl;

    for (int i = 0; i < rozmiar / 2;)  //Sprawdzanie czy podany tekst jes palindromem
    {
       
        if (tekst[i] == 32) // Pomijanie spacji 
        {
            i++;
		}
		
        if (tekst[k] == 32)
        {
            k--;
        }
        
       	
       	cout << tekst[i] <<" "<< tekst[k] << endl;
        if (tekst[i] != tekst[k]) //Zakonczenie pentli w przypadku gdy tekst nie jest palindromem 
        {
            k = -1; 
            break;
        }
        else
        {
            k--;
            i++;
        }
        
    }

    if (k == -1)
        cout << tekst << " nie jest palindromem ";
    else
        cout << tekst << " jest palindromem ";

    cout << endl
         << " Koniec programu " << endl;

    return 0;
}

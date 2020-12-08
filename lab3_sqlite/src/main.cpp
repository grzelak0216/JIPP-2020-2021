#include <libs.hpp>
#include <macierz.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    int k, w;
    double pom;
    k = 3;
    w = 2;
    Macierz Macierz1(k, w); //Test konstruktora macierzy prostokatnej
    //#####################################

    pom = 1.0;
    for (int j = 0; j < w; j++)
    {
        for (int i = 0; i < k; i++)
        {
            Macierz1.set(j, i, pom);
            pom++;
        }
        cout << "\n";
    }

    Macierz1.print();
    //#####################################

    Macierz1.store("macierz.db", "./"); //Test metody zapisujacej macierz do pliku
    //#####################################

    //koniec
    return 0;
}
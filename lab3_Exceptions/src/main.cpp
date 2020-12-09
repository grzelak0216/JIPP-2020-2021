#include "../include/libs.hpp"
#include "../include/macierz.hpp"

using namespace std;

void test()
{
    int k, w;
    double pom;
    k = 3;
    w = 2;

    Macierz Macierz1(k, w); //Test konstruktora macierzy prostokatnej
    //#####################################
    Macierz Macierz2(k); //Test konstruktora macierzy kwadratowej
    //#####################################

    Macierz1.cols(); //Test wyswietlania ilosci kolumn macierzy
    //#####################################
    Macierz1.rows(); //Test wyswietlania ilosci wierszy macierzy
    //#####################################

    Macierz1.print(); //Wyswietlanie zawatrosci macierzy
    cout << "\n";
    Macierz2.print(); //Wyswietlanie zawatrosci macierzy

    Macierz1.set(1, 1, 9.3); //Test metody set
    //#####################################
    Macierz1.get(1, 1); //Test metody get
    //#####################################

    cout << "\n macierz po set \n";
    Macierz1.print(); //Wyswietlanie zawatrosci macierzy
    cout << endl;

    cout << "\n dodawanie macierzy \n "; //Test metody dodawania macierzy
    cout << "\n wprowadz liczbe kolumn: ";
    cin >> k;
    cout << "\n wprowadz liczbe wierszy: ";
    cin >> w;

    Macierz MacierzAdd(k, w);

    cout << " \n uzupelnianie: \n";
    for (int j = 0; j < w; j++)
    {
        for (int i = 0; i < k; i++)
        {
            pom = i + j;
            cout << " " << pom;
            MacierzAdd.set(j, i, pom);
        }
        cout << "\n";
    }
    try
    {
        Macierz1.add(MacierzAdd);
    }
    catch (MatrixDimensionsException &e)
    {
        cout << e.what() << '\n';
        exit(1);
    }

    MacierzAdd.print();
    //#####################################

    cout << "\n odejmowanie macierzy \n "; //Test metody odejmowana macierzy
    cout << "\n wprowadz liczbe kolumn: ";
    cin >> k;
    cout << "\n wprowadz liczbe wierszy: ";
    cin >> w;

    Macierz MacierzSubtract(k, w);

    cout << " \n uzupelnianie: \n";
    for (int j = 0; j < w; j++)
    {
        for (int i = 0; i < k; i++)
        {
            pom = i + j;
            cout << " " << pom;
            MacierzSubtract.set(j, i, pom);
        }
        cout << "\n";
    }

    try
    {
        Macierz1.subtract(MacierzSubtract);
    }
    catch (MatrixDimensionsException &e)
    {
        cout << e.what() << '\n';
        exit(1);
    }

    MacierzSubtract.print();
    //#####################################

    cout << "\n mnozenie macierzy \n "; //Test metody mnozena macierzy
    cout << "\n wprowadz liczbe kolumn pierwszej macierzy: ";
    cin >> k;
    cout << "\n wprowadz liczbe wierszy pierwszej macierzy: ";
    cin >> w;
    Macierz multiply1(k, w);

    cout << " \n uzupelninie: \n";
    for (int j = 0; j < w; j++)
    {
        for (int i = 0; i < k; i++)
        {
            pom = i + j;
            cout << " " << pom;
            multiply1.set(j, i, pom);
        }
        cout << "\n";
    }

    cout << "\n wprowadz liczbe kolumn drugiej macierzy: ";
    cin >> k;
    cout << "\n wprowadz liczbe wierszy drugiej macierzy: ";
    cin >> w;
    Macierz multiply2(k, w);

    cout << " \n uzupelnianie: \n";
    for (int j = 0; j < w; j++)
    {
        for (int i = 0; i < k; i++)
        {
            pom = i + j;
            cout << " " << pom;
            multiply2.set(j, i, pom);
        }
        cout << "\n";
    }

    try
    {
        multiply2 = multiply1.multiply(multiply2);
    }
    catch (MatrixDimensionsException &e)
    {
        cout << e.what() << '\n';
        exit(1);
    }

    multiply2.print();
    //#####################################

    multiply2.store("macierz.txt", "./"); //Test metody zapisujacej macierz do pliku
    //#####################################

    cout << "\n macierz z pliku \n"; //Test metody pobierajacej macierz do pliku

    Macierz macierzplik("macierz.txt", "C:\\Users\\grzel\\projects\\helloworld\\jipp\\lab3_Exceptions\\build\\");

    macierzplik.print();
    //#####################################

    //koniec
}

int main(int argc, char *argv[])
{

    test();
    return 0;
}
#include "./header.h"

int main()
{
    int tab[lfilo] = {0, 1, 2, 3, 4};
    cout << "Problem pieciu filozowfow (wersja z kelnerem)\n";

    struct sigaction sa;
    sa.sa_sigaction = sighandler;
    sigaction(SIGINT, &sa, NULL);

    utworz_semafor();
    ustaw_semafor(semafor_id);

    thread filo1(stolfilozof, tab[0]);
    thread filo2(stolfilozof, tab[1]);
    thread filo3(stolfilozof, tab[2]);
    thread filo4(stolfilozof, tab[3]);
    thread filo5(stolfilozof, tab[4]);

    if (filo1.joinable())
    {
        filo1.join();
    }
    else
    {
        cout << "thread error";
        pthread_exit(0);
        exit(1);
    }

    if (filo2.joinable())
    {
        filo2.join();
    }
    else
    {
        cout << "thread error";
        pthread_exit(0);
        exit(1);
    }

    if (filo3.joinable())
    {
        filo3.join();
    }
    else
    {
        cout << "thread error";
        pthread_exit(0);
        exit(1);
    }

    if (filo4.joinable())
    {
        filo4.join();
    }
    else
    {
        cout << "thread error";
        pthread_exit(0);
        exit(1);
    }

    if (filo5.joinable())
    {
        filo5.join();
    }
    else
    {
        cout << "thread error";
        pthread_exit(0);
        exit(1);
    }

    while (1)
        ;
}
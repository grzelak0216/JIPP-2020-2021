#include <iostream>
#include <stdio.h>
#include <thread>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#define stol 5

#define lfilo 5

using namespace std;

string nazwisko[5] = {"Platon", "Arytosteles", "Sokrates", "Aureliusz", "Cyceron"};

int semafor_id;
int new_thread;
int join_thread;
int kelner;
pthread_t thread_id;

typedef struct wskaznik
{
    int number;
} wskaznik;

void rozmyslanie(int id)
{
    cout << "[ " << nazwisko[id] << " id: " << id << "] Stan: rozmysla (Tid filozofa: " << pthread_self() << " )"
         << "\n";
}

void sporzywanie(int id)
{
    cout << "[ " << nazwisko[id] << " id: " << id << "] Stan: sporzywa (Tid filozofa: " << pthread_self() << " )"
         << "\n";
}

void utworz_semafor()
{
    key_t key = ftok(".", 5);
    semafor_id = semget(key, 5, IPC_CREAT | 0600);
    if (semafor_id == -1)
    {
        perror("Semget ERROR");
        cout << "[Program glowny] ERROR: utworzenie semaformow\n";
        exit(3);
    }
}

static void ustaw_semafor(int semafor)
{
    int ustaw_sem;
    for (int i = 0; i < 5; i++)
    {
        ustaw_sem = semctl(semafor, i, SETVAL, 1);
        if (ustaw_sem == -1)
        {
            cout << "[Program glowny] ERROR: ustawienie semafora\n";
            exit(EXIT_FAILURE);
        }
        else
        {
            cout << "[Program glowny] SEMAFOR: ustawiony-> " << i << "\n";
        }
    }
}

static void usun_semafor(int k)
{
    int sem;
    sem = semctl(k, 0, IPC_RMID);
    if (sem == -1)
    {
        cout << "[Program glowny] ERROR: usuniecie semafora \n";
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "[Program glowny] Semafory usuniete -> " << sem << "\n";
    }
}

void sighandler(int signum, siginfo_t *info, void *ptr)
{
    if (signum == 2)
    {
        cout << "[Program glowny] Sygnal SIGINT!\n";
        usun_semafor(semafor_id);
        exit(0);
    }
}

static void semafor_p(int nr)
{
    int zmien_sem;
    struct sembuf bufor_sem;
    bufor_sem.sem_num = nr;
    bufor_sem.sem_op = -1;
    bufor_sem.sem_flg = SEM_UNDO;
    zmien_sem = semop(semafor_id, &bufor_sem, 1);
    if (zmien_sem == -1)
    {
        if (errno == EINTR)
        {
            semafor_p(nr);
            errno = 0;
        }
        else
        {
            perror("Semop ERROR");
            cout << "[Filozof] ERROR: zamykanie semafora\n";
            exit(EXIT_FAILURE);
        }
    }
}

static void semafor_v(int nr)
{
    int zmien_sem;
    struct sembuf bufor_sem;
    bufor_sem.sem_num = nr;
    bufor_sem.sem_op = 1;
    bufor_sem.sem_flg = SEM_UNDO;
    zmien_sem = semop(semafor_id, &bufor_sem, 1);
    if (zmien_sem == -1)
    {
        if (errno == EINTR)
        {
            semafor_v(nr);
            errno = 0;
        }
        else
        {
            perror("Semop ERROR");
            cout << "[Filozof] ERROR: otwieranie semafora\n";
            exit(EXIT_FAILURE);
        }
    }
}

void stolfilozof(int id)
{
    srand(time(0));
	int z = 0;

    while (1)
    {
        thread_id = semctl(semafor_id, kelner, GETVAL);
        if (thread_id >= 0 && z == 0)
        {
            cout << "koniec miejsca dla " << nazwisko[id] << "\n";
			z == 1;
			usleep(10);
        }
        if (thread_id > 0)
        {
			z = 0;
			usleep(5);
            rozmyslanie(id);
            semafor_p(id);
            semafor_p((id + 1) % 5);
			usleep(5);
            sporzywanie(id);
            semafor_v(id);
            semafor_v((id + 1) % 5);
        }
    }

    pthread_exit(0);
}

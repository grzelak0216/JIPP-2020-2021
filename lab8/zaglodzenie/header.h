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
int ljedz[5] = {0,0,0,0,0};

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
    cout << "[ " << nazwisko[id] << " id: " << id << "] Stan: rozmysla (Tid filozofa: " << pthread_self() << " )" << "\n";
}

void sporzywanie(int id)
{
    cout << "[ " << nazwisko[id] << " id: " << id << "] Stan: sporzywa (Tid filozofa: " << pthread_self() << " )" << "\n";
	ljedz[id]++;
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
		cout << "Rozpiska ile razy filozof jadl:\n";
		
		for(int il = 0; il < 5; il++)
		{
			cout << nazwisko[il] << ": " <<ljedz[il]<<"\n";
		}
        usun_semafor(semafor_id);
        exit(0);
    }
}

static void semafor_p(int nr1, int nr2)
{
    int zmien_sem;
    struct sembuf bufor_sem[2];
    bufor_sem[0].sem_num = nr1;
    bufor_sem[0].sem_op = -1;
    bufor_sem[0].sem_flg = SEM_UNDO;
    bufor_sem[1].sem_num = nr2;
    bufor_sem[1].sem_op = -1;
    bufor_sem[1].sem_flg = SEM_UNDO;
    zmien_sem = semop(semafor_id, bufor_sem, 2);
    if (zmien_sem == -1)
    {
        if (errno == EINTR)
        {
            semafor_p(nr1, nr2);
            errno = 0;
        }
        else
        {
            perror("Semop ERROR");
            printf("[Filozof] ERROR: zamykanie semafora\n");
            exit(EXIT_FAILURE);
        }
    }
}

static void semafor_v(int nr1, int nr2)
{
    int zmien_sem;
    struct sembuf bufor_sem[2];
    bufor_sem[0].sem_num = nr1;
    bufor_sem[0].sem_op = 1;
    bufor_sem[0].sem_flg = SEM_UNDO;
    bufor_sem[1].sem_num = nr2;
    bufor_sem[1].sem_op = 1;
    bufor_sem[1].sem_flg = SEM_UNDO;
    zmien_sem = semop(semafor_id, bufor_sem, 2);
    if (zmien_sem == -1)
    {
        if (errno == EINTR)
        {
            semafor_v(nr1, nr2);
            errno = 0;
        }
        else
        {
            perror("Semop ERROR");
            printf("[Filozof] ERROR: otwieranie semafora\n");
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
			z = 1;
			usleep(10);
        }
        if (thread_id > 0)
        {
			z = 0;
			usleep(5);
            rozmyslanie(id);
            semafor_p(id, (id + 1) % 5);
			usleep(5);
            sporzywanie(id);
            if (id == 1 || id == 3)
            {
                usleep(rand() % 500);
                //sleep(1 + rand() % 3);
            }
            semafor_v(id, (id + 1) % 5);
        }
    }

    pthread_exit(0);
}

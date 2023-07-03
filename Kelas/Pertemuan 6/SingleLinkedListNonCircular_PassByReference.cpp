#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Mahasiswa
{
    int nim;
    Mahasiswa *next;
};

void init(Mahasiswa **p)
{
    *p = NULL;
}

Mahasiswa *alokasi(int nim)
{
    Mahasiswa *P;
    P = (Mahasiswa *)malloc(sizeof(Mahasiswa));
    if (P != NULL)
    {
        P->next = NULL;
        P->nim = nim;
    }
    return P;
}

void Add(Mahasiswa **p, int nim)
{
    *p = alokasi(nim);
    printf("%d\n", (*p)->nim);
}
int main()
{
    Mahasiswa *head;
    init(&head);
    for (int i = 1; i <= 5; i++)
        Add(&head, i * 10);
    getch();
}
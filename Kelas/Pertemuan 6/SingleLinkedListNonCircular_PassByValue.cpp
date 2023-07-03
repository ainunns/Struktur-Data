#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Mahasiswa
{
    int nim;
    Mahasiswa *next;
};

Mahasiswa *init(Mahasiswa *p)
{
    p = NULL;
    return p;
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

Mahasiswa *Add(Mahasiswa *p, int nim)
{
    p = alokasi(nim);
    printf("%d\n", (p)->nim);
    return p;
}
int main()
{
    Mahasiswa *head;
    head = init(head);
    for (int i = 1; i <= 5; i++)
        head = Add(head, i * 10);
    getch();
}
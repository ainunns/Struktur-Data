#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void showMenu()
{
    printf("===================================================\n");
    printf("MENU PROGRAM\n");
    printf("1. Cek bilangan prima\n");
    printf("2. Cetak bilangan prima dari a sampai b (a <= b)\n");
    printf("3. Exit\n");
    printf("===================================================\n");
}

bool prima(long long n)
{
    if (n == 1)
        return false;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void checkPrime()
{
    char responses = 'y';
    do
    {
        system("cls");
        printf("===================================================\n");
        printf("Masukkan bilangan yang ingin dicek keprimaannya: ");
        long long p;
        scanf("%lld", &p);
        printf("Bilangan %lld adalah ", p);
        if (!prima(p))
            printf("bukan ");
        printf("bilangan prima\n");
        printf("===================================================\n");
        printf("Apakah Anda ingin kembali ke menu utama (y/n) ? ");
        scanf("\n%c", &responses);
    } while (responses == 'n');
}

void printPrime()
{
    char responses = 'y';
    do
    {
        system("cls");
        printf("===================================================\n");
        printf("Cetak bilangan prima antara a sampai b (inklusif).\nMasukkan nilai a: ");
        long long a;
        scanf("%lld", &a);
        printf("Masukkan nilai b: ");
        long long b;
        scanf("%lld", &b);
        printf("Bilangan prima antara %lld dan %lld adalah: ", a, b);
        for (long long i = a; i <= b; i++)
        {
            if (prima(i))
                printf("%lld ", i);
        }
        printf("\n");
        printf("===================================================\n");
        printf("Apakah Anda ingin kembali ke menu utama (y/n) ? ");
        scanf("\n%c", &responses);
    } while (responses == 'n');
}
int main()
{
    while (1)
    {
        system("cls");
        showMenu();
        printf("Pilih menu yang Anda inginkan: ");
        int selectedMenu;
        scanf("%d", &selectedMenu);
        switch (selectedMenu)
        {
        case 1:
        {
            checkPrime();
            break;
        }
        case 2:
        {

            printPrime();
            break;
        }
        case 3:
        {

            return 0;
        }
        default:
        {
            system("cls");
            printf("Menu yang Anda pilih tidak valid, silahkan memilih menu kembali\n");
        }
        }
    }
}
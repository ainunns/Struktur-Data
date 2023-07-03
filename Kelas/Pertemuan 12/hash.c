/*
    Tugas 10 - Hash Table
    Author: Ainun Nadhifah Syamsiyah
    NRP: 5025221053
*/

#include <stdio.h>
#include <stdlib.h>

#define size 7

int arr[size];

void init()
{
    int i;
    for (i = 0; i < size; i++)
        arr[i] = -1;
}

void insert(int value)
{
    int key = value % size;
    if (arr[key] == -1)
    {
        arr[key] = value;
        printf("%d masuk pada arr[%d]\n", value, key);
    }
    else
    {
        printf("Terjadi Collision : arr[%d] element %d sudah ada \n", key, arr[key]);
        printf("Insert dibatalkan  %d\n", value);
    }
}

void del(int value)
{
    int key = value % size;
    if (arr[key] == value)
        arr[key] = -1;
    else
        printf("%d tidak ada dalam hash table\n", value);
}

void search(int value)
{
    int key = value % size;
    if (arr[key] == value)
        printf("Data berhasil ditemukan\n");
    else
        printf("Data tidak berhasil ditemukan\n");
}

void print()
{
    int i;
    for (i = 0; i < size; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
}

void showMenu()
{
    printf("Menu Hash Table\n");
    printf("1. Insert Data\n");
    printf("2. Delete Data\n");
    printf("3. Search Data\n");
    printf("4. Print Data\n");
    printf("5. Exit\n\n");
    printf("Silahkan pilih menu yang Anda inginkan: ");
}

int main()
{
    init();
    while (1)
    {
        showMenu();
        int response;
        scanf("%d", &response);
        switch (response)
        {
        case 1:
        {
            printf("Masukkan data yang ingin Anda tambahkan: ");
            int x;
            scanf("%d", &x);
            insert(x);
            break;
        }
        case 2:
        {
            printf("Masukkan data yang ingin Anda hapus: ");
            int x;
            scanf("%d", &x);
            del(x);
            break;
        }
        case 3:
        {
            printf("Masukkan data yang ingin Anda cari: ");
            int x;
            scanf("%d", &x);
            search(x);
            break;
        }
        case 4:
        {
            print();
            break;
        }
        case 5:
        {
            return 0;
        }
        default:
        {
            printf("Input tidak valid\n");
            break;
        }
        }
        system("pause");
        system("cls");
    }

    return 0;
}
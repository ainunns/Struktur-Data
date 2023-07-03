/*
    Tugas 9 - Tree
    Author: Ainun Nadhifah Syamsiyah
    NRP: 5025221053
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct mhs
{
    char nrp[10], nama[30];
    int nilai;
    struct mhs *left, *right;
};
struct mhs *input()
{
    struct mhs *a = (struct mhs *)malloc(sizeof(struct mhs));
    printf("NRP : ");
    scanf("%s", &a->nrp);
    // printf("Nama : "); scanf("%s", &a->nama);
    // printf("Nilai : "); scanf("%d", &a->nilai);
    a->left = NULL;
    a->right = NULL;
    return a;
}

void output(struct mhs *a)
{
    printf("NRP : %s\n", a->nrp);
    // printf("Nama : %s\n", a->nama);
    // printf("Nilai : %d\n", a->nilai);
}

void printPreorder(struct mhs *a)
{
    if (a == NULL)
        return;
    output(a);
    printPreorder(a->left);
    printPreorder(a->right);
}

int main()
{
    struct mhs *data = NULL;
    data = input();
    data->left = input();
    data->right = input();
    data->left->left = input();
    data->left->right = input();
    printPreorder(data);
    system("pause");
    return 0;
}
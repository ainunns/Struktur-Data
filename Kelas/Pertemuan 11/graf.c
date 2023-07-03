/*
    Tugas 10 - Graf
    Author: Ainun Nadhifah Syamsiyah
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct tipeS
{
    struct tipeS *left;
    int INFO;
    struct tipeS *right;
};
typedef struct tipeS simpul;
simpul *P, *FIRST, *LAST, *PVertex, *PEdge, *Q, *R, *S;
simpul *PointS[5];

int main()
{
    int A[5][5] = {0, 5, 0, 2, 0,
                   6, 0, 3, 0, 0,
                   0, 0, 0, 0, 9,
                   0, 0, 12, 0, 7,
                   0, 14, 0, 0, 0};
    char nmS[5] = {'A', 'B', 'C', 'D', 'E'}; // Nama simpul vertex
    int I, J;

    // Simpul vertex yang pertama
    I = 0;
    J = 0;
    P = (simpul *)malloc(sizeof(simpul));
    P->INFO = nmS[0];
    FIRST = P;
    LAST = P;
    P->left = NULL;
    P->right = NULL;
    PointS[0] = P;
    printf("%c", P->INFO);
    printf(" alamat %p", PointS[0]);

    // Simpul vertex yang berikutnya
    for (I = 1; I <= 4; I++)
    {
        P = (simpul *)malloc(sizeof(simpul));
        P->INFO = nmS[I];
        LAST->left = P;
        LAST = LAST->left;
        P->left = NULL;
        P->right = NULL;
        PointS[I] = P;
        printf("\n%c", P->INFO);
        printf(" alamat %p", PointS[I]);
    }
    printf("\n");

    // Simpul edge untuk semua vertex
    Q = FIRST;
    for (I = 0; I <= 4; I++)
    {
        R = Q;
        printf("Vertex %c ....", Q->INFO);
        for (J = 0; J <= 4; J++)
        {
            if (A[I][J] != 0)
            {
                P = (simpul *)malloc(sizeof(simpul));
                P->INFO = A[I][J];
                R->right = P;
                P->left = PointS[J];
                printf("berhubungan dengan %c: ", P->left->INFO);
                printf("bobot %d;", P->INFO);
                P->right = NULL;
                R = P;
            }
        }
        printf("\n");
        Q = Q->left;
    }
    return 0;
}
/*
    Tugas 9 - Tugas Final Tree
    Author: Ainun Nadhifah Syamsiyah
    NRP: 5025221053
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int data;
    struct tree *left, *right;
} Tree;

typedef struct node
{
    Tree *data;
    struct node *next;
} Node;

typedef struct queue
{
    Node *front, *rear;
} Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue *q, Tree *k)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = k;
    temp->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

Tree *GetQueue(Queue *q)
{
    return q->front->data;
}

void deQueue(Queue *q)
{
    if (q->front == NULL)
        return;
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}

int isEmptyQueue(Queue *q)
{
    return q->front == NULL;
}

Tree *pohon;

void init()
{
    pohon = NULL;
}

void clear()
{
    pohon = NULL;
}

int isEmpty()
{
    return pohon == NULL;
}

void tambah(Tree **root, int databaru)
{
    if ((*root) == NULL)
    {
        Tree *baru = (Tree *)malloc(sizeof(Tree));
        baru->data = databaru;
        baru->left = baru->right = NULL;
        (*root) = baru;
        (*root)->left = (*root)->right = NULL;
    }
    else if (databaru < (*root)->data)
        tambah(&(*root)->left, databaru);
    else if (databaru > (*root)->data)
        tambah(&(*root)->right, databaru);
    else if (databaru == (*root)->data)
        printf("Data sudah ada\n");
}

void preOrder(Tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Tree *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(Tree *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void LevelOrder(Tree *root)
{
    Queue *Q;
    Q = createQueue();
    enQueue(Q, root);
    while (!isEmptyQueue(Q))
    {
        Tree *n = GetQueue(Q);
        printf("%d ", n->data);
        if (n->left != NULL)
            enQueue(Q, n->left);
        if (n->right != NULL)
            enQueue(Q, n->right);
        deQueue(Q);
    }
}

Tree *cari(Tree *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (data < root->data)
        return cari(root->left, data);
    else if (data > root->data)
        return cari(root->right, data);
    else
        return root;
}

int count(Tree *root)
{
    if (root == NULL)
        return 0;
    else
        return count(root->left) + count(root->right) + 1;
}

int height(Tree *root)
{
    if (root == NULL)
        return -1;
    else
    {
        int u = height(root->left);
        int v = height(root->right);
        if (u > v)
            return u + 1;
        else
            return v + 1;
    }
}

Tree *findMin(Tree *root)
{
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

Tree *findMax(Tree *root)
{
    if (root == NULL)
        return NULL;
    else if (root->right == NULL)
        return root;
    else
        return findMax(root->right);
}

void leaf(Tree *root)
{
    if (root == NULL)
        printf("kosong\n");
    if (root->left != NULL)
        leaf(root->left);
    if (root->right != NULL)
        leaf(root->right);
    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);
}

void showMenu()
{
    printf("Menu Binary Search Tree:\n");
    printf("1. Tambah data\n");
    printf("2. Cari data\n");
    printf("3. Kunjungi data secara preorder\n");
    printf("4. Kunjungi data secara inorder\n");
    printf("5. Kunjungi data secara postorder\n");
    printf("6. Kunjungi data secara levelorder\n");
    printf("7. Hitung jumlah node dalam tree\n");
    printf("8. Cari data terkecil\n");
    printf("9. Cari data terbesar\n");
    printf("10. Hitung tinggi tree\n");
    printf("11. Cetak daun\n");
    printf("12. Exit\n\n");
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
            tambah(&pohon, x);
            break;
        }
        case 2:
        {
            printf("Masukkan data yang ingin Anda cari: ");
            int x;
            scanf("%d", &x);
            Tree *temp = cari(pohon, x);
            if (temp != NULL)
                printf("Data %d ditemukan\n", temp->data);
            else
                printf("Data tidak ditemukan\n");
            break;
        }
        case 3:
        {
            printf("Preorder: ");
            preOrder(pohon);
            break;
        }
        case 4:
        {
            printf("Inorder: ");
            inOrder(pohon);
            break;
        }
        case 5:
        {
            printf("Postorder: ");
            postOrder(pohon);
            break;
        }
        case 6:
        {
            printf("Levelorder: ");
            LevelOrder(pohon);
            break;
        }
        case 7:
        {
            printf("Jumlah node dalam tree: %d\n", count(pohon));
            break;
        }
        case 8:
        {
            Tree *temp = findMin(pohon);
            if (temp != NULL)
                printf("Data terkecil: %d\n", temp->data);
            else
                printf("Data tidak ditemukan\n");
            break;
        }
        case 9:
        {
            Tree *temp = findMax(pohon);
            if (temp != NULL)
                printf("Data terbesar: %d\n", temp->data);
            else
                printf("Data tidak ditemukan\n");
            break;
        }
        case 10:
        {
            printf("Tinggi tree: %d\n", height(pohon));
            break;
        }
        case 11:
        {
            printf("Daun: ");
            leaf(pohon);
            printf("\n");
            break;
        }
        case 12:
        {
            return 0;
            break;
        }
        }
        printf("\n");
        system("pause");
        system("cls");
    }
    return 0;
}
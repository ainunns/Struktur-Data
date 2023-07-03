#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

struct TNode
{
    int data;
    struct TNode *next, *prev;
};

struct TNode *head, *tail;

struct TNode *createNode(int databaru)
{
    struct TNode *baru = (struct TNode *)malloc(sizeof(struct TNode));
    baru->data = databaru;
    baru->next = baru->prev = NULL;
    return baru;
}

void init()
{
    head = tail = NULL;
}

bool isEmpty()
{
    return (head == NULL);
}

void tampil()
{
    struct TNode *bantu = head;
    if (!isEmpty())
    {
        printf("Data pada linked list sekarang: ");
        while (bantu != NULL)
        {
            printf("%d ", bantu->data);
            bantu = bantu->next;
        }
        puts("");
    }
    else
        puts("Linked list kosong");
}

void tampilRev()
{
    if (!isEmpty())
    {
        printf("Data pada linked list sekarang (secara terbalik): ");
        struct TNode *bantu = tail;
        while (bantu != NULL)
        {
            printf("%d ", bantu->data);
            bantu = bantu->prev;
        }
        puts("");
    }
    else
        puts("Linked list kosong");
}

void insertDepan(int dataBaru)
{
    struct TNode *baru = createNode(dataBaru);
    if (isEmpty())
    {
        head = baru;
        tail = head;
        head->next = head->prev = NULL;
        tail->next = tail->prev = NULL;
    }
    else
    {
        struct TNode *bantu = head;
        while (bantu != NULL)
        {
            bantu->data += baru->data;
            bantu = bantu->next;
        }
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    printf("Data %d berhasil masuk ke depan\n", dataBaru);
    tampil();
}

void insertBelakang(int dataBaru)
{
    struct TNode *baru = createNode(dataBaru), *bantu;
    if (isEmpty())
    {
        head = baru;
        tail = head;
        head->next = head->prev = NULL;
        tail->next = tail->prev = NULL;
    }
    else
    {
        tail->next = baru;
        baru->data += tail->data;
        baru->prev = tail;
        tail = baru;
        tail->next = NULL;
    }
    printf("Data %d berhasil masuk ke belakang\n", dataBaru);
    tampil();
}

void hapusDepan()
{
    if (!isEmpty())
    {
        int d = head->data;
        if (head->next != NULL)
        {
            struct TNode *hapus = head, *bantu = head->next;
            head = head->next;
            head->prev = NULL;
            while (bantu != NULL)
            {
                bantu->data -= hapus->data;
                bantu = bantu->next;
            }
            free(hapus);
        }
        else
        {
            head = tail = NULL;
        }
        printf("Data %d berhasil dihapus\n", d);
        tampil();
    }
    else
        puts("Linked list kosong");
}

void hapusBelakang()
{
    if (!isEmpty())
    {
        int d;
        if (head->next != NULL)
        {
            struct TNode *hapus = tail;
            d = tail->data - tail->prev->data;
            tail = tail->prev;
            tail->next = NULL;
            free(hapus);
        }
        else
        {
            d = head->data;
            head = tail = NULL;
        }
        printf("Data %d berhasil dihapus\n", d);
        tampil();
    }
    else
        puts("Linked list kosong");
}

void clear()
{
    if (!isEmpty())
    {
        struct TNode *bantu = head, *hapus;
        while (bantu != NULL)
        {
            hapus = bantu;
            bantu = bantu->next;
            free(hapus);
        }
        head = tail = NULL;
    }
    printf("Linked list berhasil dikosongkan\n");
}

void editData(int index, int dataBaru)
{
    int cnt = 1, edited = 0, val;
    struct TNode *bantu = head;
    while (bantu != NULL)
    {
        if (cnt == index)
        {
            edited = 1;
            val = dataBaru - (bantu->data - (index > 1) * (bantu->prev->data));
        }
        cnt++;
        if (edited)
            bantu->data += val;
        bantu = bantu->next;
    }
    if (!edited)
        printf("Data pada linked list gagal diedit\n", index);
    else
        printf("Data ke-%d berhasil diedit\n", index);
    tampil();
}

void showMenu()
{
    printf("Menu Double Linked List non Circular:\n");
    printf("1. Tambah data ke depan\n");
    printf("2. Tambah data ke belakang\n");
    printf("3. Hapus data terdepan\n");
    printf("4. Hapus data terbelakang\n");
    printf("5. Tampilkan seluruh data\n");
    printf("6. Hapus seluruh data\n");
    printf("7. Edit data\n");
    printf("8. Exit\n\n");
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
            printf("Masukkan data yang ingin Anda tambahkan ke depan: ");
            int x;
            scanf("%d", &x);
            insertDepan(x);
            break;
        }
        case 2:
        {
            printf("Masukkan data yang ingin Anda tambahkan ke belakang: ");
            int x;
            scanf("%d", &x);
            insertBelakang(x);
            break;
        }
        case 3:
        {
            hapusDepan();
            break;
        }
        case 4:
        {
            hapusBelakang();
            break;
        }
        case 5:
        {
            printf("Apakah Anda ingin menampilkan data secara terbalik (y/n)? ");
            char resp;
            scanf("\n%c", &resp);
            (resp == 'y') ? tampilRev() : tampil();
            break;
        }
        case 6:
        {
            clear();
            break;
        }
        case 7:
        {
            printf("Masukkan index dari data yang ingin Anda edit: ");
            int idx;
            scanf("%d", &idx);
            printf("Masukkan nilai dari data yang baru: ");
            int dataBaru;
            scanf("%d", &dataBaru);
            editData(idx, dataBaru);
            break;
        }
        case 8:
        {
            return 0;
            break;
        }
        }
        getch();
        system("cls");
    }
    return 0;
}
// compile command: gcc -o DoubleLinkedListNonCircular_HeadandTail DoubleLinkedListNonCircular_HeadandTail.c
// run command: DoubleLinkedListNonCircular_HeadandTail

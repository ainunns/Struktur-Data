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
    baru->next = baru->prev = baru;
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
    if (!isEmpty())
    {
        printf("Data pada linked list sekarang: ");
        struct TNode *bantu = head;
        do
        {
            printf("%d ", bantu->data);
            bantu = bantu->next;
        } while (bantu != tail->next);
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
        do
        {
            printf("%d ", bantu->data);
            bantu = bantu->prev;
        } while (bantu != head->prev);
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
        head = tail = baru;
        head->next = head->prev = head;
        tail->next = tail->prev = tail;
    }
    else
    {
        baru->next = head;
        head->prev = baru;
        head = baru;
        head->prev = tail;
        tail->next = head;
    }
    printf("Data %d berhasil masuk ke depan\n", dataBaru);
    tampil();
}

void insertBelakang(int dataBaru)
{
    struct TNode *baru = createNode(dataBaru), *bantu;
    if (isEmpty())
    {
        head = tail = baru;
        head->next = head->prev = head;
        tail->next = tail->prev = tail;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }
    printf("Data %d berhasil masuk ke belakang\n", dataBaru);
    tampil();
}

void hapusDepan()
{
    if (!isEmpty())
    {
        int d = head->data;
        if (head == tail)
        {
            head = tail = NULL;
            free(head);
        }
        else
        {
            struct TNode *hapus = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            free(hapus);
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
        if (head == tail)
        {
            d = head->data;
            head = tail = NULL;
            free(head);
        }
        else
        {
            struct TNode *hapus = tail;
            d = tail->data;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            free(hapus);
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
        while (bantu->next != head)
        {
            hapus = bantu;
            bantu = bantu->next;
            free(hapus);
        }
        head = tail = NULL;
    }
    printf("Linked list berhasil dikosongkan\n");
}

int cariData(int nilai, bool isHead)
{
    if (!isEmpty())
    {
        struct TNode *bantu = head;
        int index = 1;
        if (isHead)
        {
            do
            {
                if (bantu->data == nilai)
                    return index;
                bantu = bantu->next;
                index++;
            } while (bantu != tail->next);
        }
        else
        {
            bantu = tail;
            do
            {
                if (bantu->data == nilai)
                    return index;
                bantu = bantu->prev;
                index++;
            } while (bantu != head->prev);
        }
    }
    return -1;
}

void hapusData(int nilai)
{
    if (cariData(nilai, true) == -1)
    {
        printf("%d gagal dihapus karena data tidak ditemukan\n", nilai);
        return;
    }
    if (head->data == nilai)
    {
        hapusDepan();
    }
    else if (tail->data == nilai)
    {
        hapusBelakang();
    }
    else
    {
        struct TNode *bantu = head, *sblm = NULL;
        while (bantu->next != head)
        {
            if (nilai == bantu->data)
            {
                sblm->next = bantu->next;
                bantu->prev = sblm;
                struct TNode *hapus = bantu;
                free(hapus);
                break;
            }
            sblm = bantu;
            bantu = bantu->next;
        }
    }
    printf("Data %d berhasil dihapus\n", nilai);
    tampil();
}

void showMenu()
{
    printf("Menu Single Linked List non Circular:\n");
    printf("1. Tambah data ke depan\n");
    printf("2. Tambah data ke belakang\n");
    printf("3. Hapus data terdepan\n");
    printf("4. Hapus data terbelakang\n");
    printf("5. Tampilkan seluruh data\n");
    printf("6. Hapus seluruh data\n");
    printf("7. Cari data\n");
    printf("8. Hapus data tertentu\n");
    printf("9. Exit\n\n");
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
            printf("Masukkan data yang ingin Anda cari: ");
            int x;
            scanf("%d", &x);
            printf("Apakah Anda ingin mencari data tersebut dari head (y/n)? ");
            char resp;
            scanf("\n%c", &resp);
            int idx = cariData(x, (resp == 'y'));
            if (idx == -1)
                printf("Data tidak ditemukan\n");
            else
                printf("Data ditemukan pada index ke-%d\n", idx);
            break;
        }
        case 8:
        {
            printf("Masukkan data yang ingin Anda hapus: ");
            int x;
            scanf("%d", &x);
            hapusData(x);
            break;
        }
        case 9:
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

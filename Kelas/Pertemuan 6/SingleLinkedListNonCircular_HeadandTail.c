#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

struct TNode
{
    int data;
    struct TNode *next;
};

struct TNode *head, *tail;
int size = 0;

struct TNode *createNode(int databaru)
{
    struct TNode *baru = (struct TNode *)malloc(sizeof(struct TNode));
    baru->data = databaru;
    baru->next = NULL;
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
    struct TNode *b = head;
    if (!isEmpty())
    {
        printf("Data pada linked list sekarang: ");
        do
        {
            printf("%d ", b->data);
            b = b->next;
        } while (b != tail->next);
        puts("");
    }
    else
        puts("Linked list masih kosong");
}

void tambahDepan(int dataBaru)
{
    struct TNode *baru = createNode(dataBaru);
    if (isEmpty())
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
    size++;
    printf("Data %d berhasil masuk ke depan\n", dataBaru);
    tampil();
}

void tambahBelakang(int dataBaru)
{
    struct TNode *baru = createNode(dataBaru);
    if (isEmpty())
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
    size++;
    printf("Data %d berhasil masuk ke belakang\n", dataBaru);
    tampil();
}

void hapusDepan()
{
    if (!isEmpty())
    {
        struct TNode *hapus = head;
        int d = head->data;
        if (head != tail)
        {
            head = head->next;
            free(hapus);
        }
        else
        {
            head = tail = NULL;
        }
        size--;
        printf("Data %d berhasil dihapus\n", d);
        tampil();
    }
    else
        puts("Masih kosong");
}

void hapusBelakang()
{
    if (!isEmpty())
    {
        struct TNode *hapus = head;
        int d = tail->data;
        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            struct TNode *bantu = head;
            while (bantu->next != tail)
                bantu = bantu->next;
            hapus = tail;
            tail = bantu;
            free(hapus);
            tail->next = NULL;
        }
        size--;
        printf("Data %d berhasil dihapus\n", d);
        tampil();
    }
    else
        puts("Masih kosong");
}

void clear()
{
    if (!isEmpty())
    {
        struct TNode *bantu = head;
        while (bantu != NULL)
        {
            struct TNode *hapus = bantu;
            bantu = bantu->next;
            size--;
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
        while (bantu != NULL)
        {
            if (nilai == bantu->data)
                break;
            bantu = bantu->next;
            index++;
        }
        if (index > size)
            return -1;
        if (!isHead)
            index = size - index + 1;
        return index;
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
        while (bantu != NULL)
        {
            if (nilai == bantu->data)
            {
                sblm->next = bantu->next;
                struct TNode *hapus = bantu;
                free(hapus);
                break;
            }
            sblm = bantu;
            bantu = bantu->next;
        }
    }
    size--;
    printf("Data %d berhasil dihapus\n", nilai);
    tampil();
}

void insertData(int dataBaru, int ref, bool isBefore)
{
    if (cariData(ref, true) == -1)
    {
        printf("Data %d gagal ditambahkan karena data acuan tidak dapat ditemukan\n", dataBaru);
        return;
    }
    struct TNode *baru = createNode(dataBaru), *bantu = head, *sblm = NULL;
    while (bantu != NULL)
    {
        if (bantu->data == ref)
        {
            printf("Data berhasil disisipkan\n");
            if (isBefore && bantu == head)
                tambahDepan(dataBaru);
            else if (!isBefore && bantu == tail)
                tambahBelakang(dataBaru);
            else
            {
                if (isBefore)
                {
                    sblm->next = baru;
                    baru->next = bantu;
                }
                else
                {
                    baru->next = bantu->next;
                    bantu->next = baru;
                }
                tampil();
            }
            break;
        }
        sblm = bantu;
        bantu = bantu->next;
    }
    size++;
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
    printf("9. Sisipkan data\n");
    printf("10. Exit\n\n");
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
            tambahDepan(x);
            break;
        }
        case 2:
        {
            printf("Masukkan data yang ingin Anda tambahkan ke belakang: ");
            int x;
            scanf("%d", &x);
            tambahBelakang(x);
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
            tampil();
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
            printf("Masukkan data yang ingin Anda sisipkan: ");
            int x;
            scanf("%d", &x);
            printf("Masukkan data yang akan dijadikan acuan penyisipan: ");
            int y;
            scanf("%d", &y);
            printf("Apakah Anda ingin menyisipkan sebelum data acuan (y/n)? ");
            char resp;
            scanf("\n%c", &resp);
            insertData(x, y, resp == 'y');
            break;
        }
        case 10:
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
// compile command: gcc -o SingleLinkedListNonCircular_HeadandTail SingleLinkedListNonCircular_HeadandTail.c
// run command: SingleLinkedListNonCircular_HeadandTail

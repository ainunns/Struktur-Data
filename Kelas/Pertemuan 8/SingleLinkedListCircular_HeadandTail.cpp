#include <bits/stdc++.h>
using namespace std;
struct TNode
{
    int data;
    TNode *next;
};

TNode *head, *tail;

TNode *createNode(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = baru;
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

void tambahDepan(int dataBaru)
{
    TNode *baru = createNode(dataBaru);
    if (isEmpty())
    {
        head = tail = baru;
        head->next = head;
        tail->next = tail;
    }
    else
    {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
    cout << "Data " << dataBaru << " masuk ke depan\n";
}

void tambahBelakang(int dataBaru)
{
    TNode *baru = createNode(dataBaru);
    if (isEmpty())
    {
        head = tail = baru;
        head->next = head;
        tail->next = tail;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout << "Data " << dataBaru << " masuk ke belakang\n";
}

void tampil()
{
    TNode *b = head;
    if (!isEmpty())
    {
        do
        {
            cout << b->data << " ";
            b = b->next;
        } while (b != tail->next);
        cout << "\n";
    }
    else
        cout << "Masih kosong\n";
}

void hapusDepan()
{
    if (!isEmpty())
    {
        TNode *hapus = head;
        int d = head->data;
        if (head != tail)
        {
            head = head->next;
            tail->next = head;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
        cout << d << " terhapus\n";
    }
    else
        cout << "Masih kosong\n";
}

void hapusBelakang()
{
    if (!isEmpty())
    {
        TNode *hapus = head;
        if (!isEmpty())
        {
            int d;
            if (head == tail)
            {
                d = tail->data;
                head = tail = NULL;
            }
            else
            {
                TNode *bantu = head;
                while (bantu->next != tail)
                    bantu = bantu->next;
                hapus = tail;
                tail = bantu;
                d = hapus->data;
                tail->next = head;
                delete hapus;
            }
            cout << d << " terhapus\n";
        }
    }
    else
        cout << "Masih kosong\n";
}

void clear()
{
    if (!isEmpty())
    {
        TNode *bantu = head;
        while (bantu->next != head)
        {
            TNode *hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        head = tail = NULL;
    }
}

void showMenu()
{
    cout << "Menu Single Linked List Circular:\n";
    cout << "1. Tambah data ke depan\n";
    cout << "2. Tambah data ke belakang\n";
    cout << "3. Hapus data terdepan\n";
    cout << "4. Hapus data terbelakang\n";
    cout << "5. Tampilkan seluruh data\n";
    cout << "6. Hapus seluruh data\n";
    cout << "7. Exit\n\n";
    cout << "Silahkan pilih menu yang Anda inginkan: ";
}

int main()
{
    init();
    while (true)
    {
        showMenu();
        int response;
        cin >> response;
        cin.ignore();
        switch (response)
        {
        case 1:
        {
            cout << "Masukkan data yang ingin Anda tambahkan: ";
            int x;
            cin >> x;
            tambahDepan(x);
            break;
        }
        case 2:
        {
            cout << "Masukkan data yang ingin Anda tambahkan: ";
            int x;
            cin >> x;
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
            return 0;
            break;
        }
        }
        cout << "ketik 1 untuk lanjut: ";
        int c;
        cin >> c;
        system("cls");
    }
    return 0;
}

#include <iostream>
using namespace std;
struct TNode
{
    int data;
    TNode *next;
};

TNode *head;

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
    head = NULL;
}

bool isEmpty()
{
    return (head == NULL);
}

void insertDepan(int dataBaru)
{
    TNode *baru = createNode(dataBaru);
    if (isEmpty())
    {
        head = baru;
        head->next = head;
    }
    else
    {
        TNode *bantu = head;
        while (bantu->next != head)
            bantu = bantu->next;
        baru->next = head;
        head = baru;
        bantu->next = head;
    }
    cout << "Data masuk\n";
}

void insertBelakang(int dataBaru)
{
    TNode *baru = createNode(dataBaru);
    if (isEmpty())
    {
        head = baru;
        head->next = head;
    }
    else
    {
        TNode *bantu = head;
        while (bantu->next != head)
            bantu = bantu->next;
        baru->next = head;
    }
    cout << "Data masuk\n";
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
        } while (b != head);
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
        if (head->next != head)
        {
            TNode *bantu = head;
            while (bantu->next != head)
                bantu = bantu->next;
            head = head->next;
            delete hapus;
            bantu->next = head;
        }
        else
        {
            head = NULL;
        }
    }
    else
        cout << "Masih kosong\n";
}

void hapusBelakang()
{
    if (!isEmpty())
    {
        TNode *hapus = head;
        if (head->next == head)
            head = NULL;
        else
        {
            TNode *bantu = head;
            while (bantu->next->next != head)
                bantu = bantu->next;
            hapus = bantu->next;
            int d = bantu->data;
            bantu->next = head;
            delete hapus;
            cout << d << " terhapus\n";
        }
    }
    else
        cout << "Masih kosong\n";
}

void clear()
{
    TNode *bantu = head;
    while (bantu->next != head)
    {
        TNode *hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = NULL;
}

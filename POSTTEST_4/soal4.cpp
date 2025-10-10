// SOAL 4

// Anda memiliki sebuah circular doubly linked list yang datanya sudah terurut (ascending). Buatlah fungsi untuk menyisipkan sebuah node baru ke dalam list tersebut sehingga urutannya tetap terjaga.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

/*
 * Fungsi ini menerima referensi ke pointer head dan data yang akan disisipkan.
 * Pointer head bisa berubah jika data baru menjadi elemen terkecil.
 */

void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // Kasus 1: List masih kosong
    if (head_ref == nullptr) {
        // node pertama nunjuk dirinya sendiri
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    // Kasus 2: Data baru lebih kecil dari head, sisipkan di awal
    // 1. Jika data < head_ref->data, sisipkan sebelum head dan update head_ref
    if (data < head_ref->data) {
        Node* tail = head_ref->prev;

        newNode->next = head_ref;
        newNode->prev = tail;
        tail->next = newNode;
        head_ref->prev = newNode;
        head_ref = newNode; 
        return;
    }

    // Kasus 3: Cari posisi di tengah/akhir yang pas
    Node* current = head_ref;
    // 1. Gunakan pointer current mulai dari head_ref
    newNode->next = current->next;
    // 2. Loop: while (current->next != head_ref && current->next->data < data)
    while (current->next != head_ref && current->next->data < data)
    {
        current = current->next;
    }
    
    // 3. Setelah loop, sisipkan node baru setelah current
    newNode->next = current->next;
    newNode->prev = current;

    // 4. Pastikan update semua pointer next dan prev dengan benar
    current->next->prev = newNode;
    current->next = newNode;
    //
    // Kalau ada data yang sama, tetap sisipkan setelahnya
    if (current->data == data) {
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

void printList(Node *head_ref)
{
    // kalau list kosong langsung keluar aja
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    // pakai do-while biar minimal cetak sekali karena circular.
    do
    {
        // cetak data node sekarang
        cout << current->data << " ";
        // lanjuttt
        current = current->next;
    } 
    
    // berhenti kalau sudah balik ke head
    while (current != head_ref);
    cout << endl;
    
}

int main()
{
    Node *head = nullptr;

    // Test sorted insert
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    // Expected output: 10 20 30 40
    printList(head);

    return 0;
}


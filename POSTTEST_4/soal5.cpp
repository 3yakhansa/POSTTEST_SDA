// SOAL 5

// Buat sebuah fungsi untuk menukar posisi node head dan node tail dalam sebuah circular doubly linked list tanpa menukar datanya, melainkan dengan memanipulasi pointernya.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

/*
 * Fungsi ini menerima referensi ke pointer head dan tail.
 * Pointer head dan tail akan di-update setelah penukaran.
 */

void exchangeHeadAndTail(Node *&head_ref) {
    // cuma jalan kalau ada 2 node atau lebih
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref;
    Node* tail = head_ref->prev;  

    // Kalau list cuma punya 2 node, cukup swap head_ref aja
    if (head->next == tail && tail->next == head) {
        swap(head_ref, tail);
        return;
    }
    // Simpan tetangga head & tail (head_next dan tail_prev)
    Node* head_next = head->next;
    Node* tail_prev = tail->prev;

    // perbarui koneksi: tail_prev <-> tail <-> head_next
    tail_prev->next = head;
    tail->prev = tail_prev;
    tail->next = head_next;
    head_next->prev = tail;
    // perbarui koneksi: head_next <- ... -> tail_prev <-> head <-> tail_prev
    head->next = tail;
    head->prev = tail_prev;
    tail_prev->next= head;
    // ubah head_ref ke node tail
    head_ref = tail;

}

void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    // loop mutar sampai balik lagi ke head
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

// fungsi buat nyisipkan node di akhir circular doubly linked list
void insertEnd(Node *&head_ref, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};

    // kalau list masih kosong, node pertama jadi circular
    if (head_ref == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main()
{
    Node *head = nullptr;

    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    // Expected output: 5 2 3 4 1
    printList(head);

    return 0;
}



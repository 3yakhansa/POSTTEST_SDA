// SOAL 1

// Buat sebuah fungsi yang menerima string dan mengembalikannya dalam keadaan terbalik. Anda harus menggunakan struktur data Stack yang diimplementasikan secara manual menggunakan singly linked list.

#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// nambahin node baru ke dalam stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// menghapus dan mengambil elemen paling atas dalam stack
char pop(Node*& top) {
    if (top == nullptr) return '\0'; 
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

// Fungsi membalik string
string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // 1. Push setiap karakter dari string s ke dalam stack.
    for (char c : s) {
        // menambahkan karakter pada posisi paling atas ke dalam stack 
        push(stackTop, c);
    }

    // 2. ambil tiap karakter dari stack dan tambahkan ke string `reversed`.
    char c;
    // selama hasil pop bukan '\0' (stack belum kosong) tambahkan karakter ke dalam reversed
    while ((c = pop(stackTop)) != '\0') {
        reversed += c;
    }
    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; 
    return 0;
}
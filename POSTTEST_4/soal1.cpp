// SOAL 1

// Buat sebuah fungsi yang menerima string dan mengembalikannya dalam keadaan terbalik. Anda harus menggunakan struktur data Stack yang diimplementasikan secara manual menggunakan singly linked list.

#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};


void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0'; 
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // 1. Push setiap karakter dari string s ke dalam stack.
    for (char c : s) {
        push(stackTop, c);
    }

    // 2. Pop setiap karakter dari stack dan tambahkan ke string `reversed`.
    char c;
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
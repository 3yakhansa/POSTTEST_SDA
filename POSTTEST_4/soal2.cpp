//  SOAL 2

// Buat fungsi yang memeriksa apakah sebuah string yang berisi tanda kurung (), {}, dan [] seimbang. Contohnya, "{[()]}" seimbang, tetapi "{[(])}" tidak. Gunakan implementasi Stack manual.

#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    // 1. Cek tiap karakter dengan Loop setiap karakter dalam `expr`.
    for (char c : expr) {
        // 2. Kalau ketemu karakter kurung buka '(', '{', '[', simpan di stack.
        if (c == '(' || c == '{' || c == '[') {
            Node* newNode = new Node{c, stackTop};
            stackTop = newNode;
        }
        // 3. kalau ketemu karakter kurung tutup ')', '}', ']', cek:
        else if (c == ')' || c == '}' || c == ']') {
            //    a. Apakah stack kosong? kalau iya, berarti gak seimbang
            if (stackTop == nullptr) return false;
            //    b. Ambil karakter (pop) dari stack.
            char topChar = stackTop->data;
            Node* temp = stackTop;
            stackTop = stackTop->next;
            delete temp;

            // cocokkan karakternya
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    // 4. Habis dicek, kalau stack kosong, return true (seimbang). kalau gak, return false (tidak seimbang).
    if (stackTop == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Expected output: Seimbang
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}

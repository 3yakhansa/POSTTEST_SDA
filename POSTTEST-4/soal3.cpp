//  SOAL 3

// Buat implementasi Queue manual menggunakan linked list untuk simulasi antrian printer yang memproses dokumen berdasarkan urutan kedatangan (FIFO).

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // 1. Kalau antrian masih kosong, front & rear langsung tunjuk ke node baru
    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    }
    // 2.  Kalau sudah ada isinya, sambungkan node baru di belakang lalu geser rear
    else if (rear != nullptr)
    {
        rear->next = newNode;
        rear = newNode;
    }
    
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    // 1. Simpan dokumen paling depan (front node)
    string document = front->document;
    // 2. Geser front ke node selanjutnya (front->next)
    front = front->next;
    // 3. Kalau habis digeser kosong, rear juga di-set kosong
    if (front == nullptr) {
        rear = nullptr;
    }
    // 4. hapus node lama, terus balikin data
    delete front;
    return document;

    return ""; // Placeholder
}

void processAllDocuments(Node*& front, Node*& rear) {
    // Selama masih ada isi antrian, ambil satu per satu
    while (front != nullptr) {
        string document = dequeue(front, rear);
    // Tampilkan dokumen dengan Format: "Memproses: [nama_dokumen]"
     cout << "Memproses: " << document << endl;
    }   
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}

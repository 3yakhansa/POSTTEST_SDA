// ## Soal 2

// Binary Search Tree (BST), semua nilai yang lebih kecil dari root berada di subtree kiri. Dengan properti ini, kita dapat dengan mudah menemukan nilai terkecil dalam tree. Buatlah fungsi untuk mencari nilai minimum tersebut.

// Lengkap kode berikut:

#include <iostream>
using namespace std;
// Struktur Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}
/**
 * @brief Fungsi untuk mencari nilai terkecil dalam sebuah BST.
 * @param root Pointer ke node root dari tree.
 * @return Nilai integer terkecil. Mengembalikan -1 jika tree kosong.
 * @logic
 * 1. Cek jika tree kosong.
 * 2. Selama masih ada anak kiri (left child), terus telusuri ke kiri.
 * 3. Node paling kiri adalah node dengan nilai terkecil.
 */
int findMinValue(Node* root) {
    // --- LENGKAPI KODE DI SINI ---
    // Mengecek apakah tree kosong, kalau iya kembalikan -1.
    if (root == nullptr) {
        return -1;
    }
     // Selama masih ada anak kiri, terus bergerak ke kiri.
    while (root->left != nullptr) {
        root = root->left;
    }
    // Setelah sampai di ujung kiri, kembalikan nilai terkecil.
    return root->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl; // Harusnya output: 20
    return 0;
}


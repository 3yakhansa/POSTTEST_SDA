#include <iostream>
using namespace std;

struct Flight {
    string kodePenerbangan;
    string tujuan;
    string status;
};

struct Node {
    Flight flight;
    Node *next;
};

string pilihStatus() {
    int pilihan;
    cout << "Pilih Status Penerbangan:\n";
    cout << "1. Tepat Waktu\n";
    cout << "2. Terlambat\n";
    cout << "3. Naik Pesawat\n";
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: return "Tepat Waktu";
        case 2: return "Terlambat";
        case 3: return "Naik Pesawat";
        default:
            cout << "Input tidak valid, otomatis Tepat Waktu nih.\n";
            return "Tepat Waktu";
    }
}

void read(Node *head) {
    if (head == nullptr) {
        cout << "Jadwal Penerbangan Kosong.\n";
        return;
    }
    Node *temp = head;
    cout << "\n=== DAFTAR JADWAL PENERBANGAN ===\n";
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << ". "
             << temp->flight.kodePenerbangan << " | "
             << temp->flight.tujuan << " | "
             << temp->flight.status << endl;
        temp = temp->next;
    }
    cout << "--------------------------------\n";
}

void addFirst(Node *&head, Node *&tail, string kode, string tujuan, string status) {
    Node *newNode = new Node;
    newNode->flight = {kode, tujuan, status};
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) tail = newNode;
}

void addLast(Node *&head, Node *&tail, string kode, string tujuan, string status) {
    Node *newNode = new Node;
    newNode->flight = {kode, tujuan, status};
    newNode->next = nullptr;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
}

void addSpecific(Node *&head, Node *&tail, int posisi, string kode, string tujuan, string status) {
    if (posisi < 1) {
        cout << "Posisi tidak valid!\n";
        return;
    }
    if (posisi == 1) {
        addFirst(head, tail, kode, tujuan, status);
        return;
    }
    Node *temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }
    if (temp == nullptr) {
        cout << "Posisi lebih besar dari panjang list.\n";
        return;
    }
    if (temp->next == nullptr) {
        addLast(head, tail, kode, tujuan, status);
    } else {
        Node *newNode = new Node;
        newNode->flight = {kode, tujuan, status};
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFirst(Node *&head, Node *&tail) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal yang bisa dihapus.\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr) tail = nullptr;
    cout << "Jadwal pertama dihapus.\n";
}

void deleteLast(Node *&head, Node *&tail) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal yang bisa dihapus.\n";
        return;
    }
    if (head == tail) { 
        delete head;
        head = tail = nullptr;
    } else {
        Node *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    cout << "Jadwal terakhir berhasil dihapus.\n";
}

void deleteSpecific(Node *&head, Node *&tail, int posisi) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal.\n";
        return;
    }
    if (posisi < 1) {
        cout << "Posisi tidak valid.\n";
        return;
    }
    if (posisi == 1) {
        deleteFirst(head, tail);
        return;
    }
    Node *temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Posisi lebih besar dari panjang list.\n";
        return;
    }
    Node *hapus = temp->next;
    temp->next = hapus->next;
    if (hapus == tail) tail = temp;
    delete hapus;
    cout << "Jadwal di posisi " << posisi << " berhasil dihapus.\n";
}

void updateStatus(Node *&head, string kode) {
    read(head);
    if (head == nullptr) {
        cout << "Jadwal kosong.\n";
        return;
    }
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->flight.kodePenerbangan == kode) {
            cout << "Status lama: " << temp->flight.status << endl;
            string newStatus = pilihStatus();
            temp->flight.status = newStatus;
            cout << "Status penerbangan berhasil diperbarui!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Kode penerbangan tidak ditemukan.\n";
}

int main() {
    Node *head = nullptr;
    Node *tail = nullptr;

    string nama, nim;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    cin >> nim;

    string last3 = nim.substr(nim.size() - 3);
    int lastDigit = nim.back() - '0';
    int sisipPos = lastDigit + 1;
    int counter = 0;

    int pilihan;
    do {
        cout << "\n+------------------------------------------------------------+\n";
        cout << "|              SISTEM JADWAL PENERBANGAN                     |\n";
        cout << "|       [" << nama << " - " << nim << "]\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "| 1. Tambah Jadwal (Awal)                                    |\n";
        cout << "| 2. Tambah Jadwal (Akhir)                                   |\n";
        cout << "| 3. Tambah Jadwal (Spesifik)                                |\n";
        cout << "| 4. Hapus Jadwal (Awal)                                     |\n";
        cout << "| 5. Hapus Jadwal (Akhir)                                    |\n";
        cout << "| 6. Hapus Jadwal (Spesifik)                                 |\n";
        cout << "| 7. Update Status Penerbangan                               |\n";
        cout << "| 8. Tampilkan Semua Jadwal                                  |\n";
        cout << "| 0. Keluar                                                  |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 3) {
            counter++;
            string kode = "JT-" + last3;
            if (counter > 1) kode += "-" + to_string(counter - 1);
            string tujuan;
            cout << "Masukkan tujuan penerbangan: ";
            cin.ignore();
            getline(cin, tujuan);
            string status = pilihStatus();

            if (pilihan == 1)
                addFirst(head, tail, kode, tujuan, status);
            else if (pilihan == 2)
                addLast(head, tail, kode, tujuan, status);
            else if (pilihan == 3)
                addSpecific(head, tail, sisipPos, kode, tujuan, status);

            cout << "Jadwal berhasil ditambahkan " << kode << endl;
        }
        else if (pilihan == 4) deleteFirst(head, tail);
        else if (pilihan == 5) deleteLast(head, tail);
        else if (pilihan == 6) {
            int pos;
            cout << "Masukkan posisi yang ingin dihapus: ";
            cin >> pos;
            deleteSpecific(head, tail, pos);
        }
        else if (pilihan == 7) {
            cout << "Masukkan kode penerbangan yang ingin diupdate: ";
            string kode;
            cin >> kode;
            updateStatus(head, kode);
        }
        else if (pilihan == 8) read(head);
        else if (pilihan == 0) {
    cout << "Terima kasih telah menggunakan sistem ini.\n";
    cout << R"(           _
     |\ ____\_\__
   -=\c`""""""" "`)
       `~~~~~/ /~~`
        -==/ /
          '-' )" << endl;
    cout << "berangkat dulu diks\n";
}
else {
    cout << "Pilihan tidak valid.\n";
}

    } while (pilihan != 0);
    return 0;
}

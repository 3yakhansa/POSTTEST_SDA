#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    double ipk;
};

int main() {
    Mahasiswa mhs[4];

    cout << "Input data 4 mahasiswa:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "Nama : ";
        cin.ignore(i == 0 ? 0 : 1, '\n'); 
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
    }

    for (int i = 0; i < 4-1; i++) {
        for (int j = 0; j < 4-i-1; j++) {
            if (mhs[j].ipk > mhs[j+1].ipk) {
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }

    cout << "\nDATA MAHASISWA:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << i+1 << ". Nama: " << mhs[i].nama
             << ", NIM: " << mhs[i].nim
             << ", IPK: " << mhs[i].ipk << endl;
    }

    return 0;
}

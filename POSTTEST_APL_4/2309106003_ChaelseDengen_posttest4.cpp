#include <iostream>
#include <string>
using namespace std;

struct Drakor {
    string judul;
};

struct User {
    string id;
    string pass;
};

struct GudangDrakor {
    Drakor drakor[1000];
    int jumlah_data;
};

User users[1] = {{"cecel", "2309106003"}};

void login() {
    cout << "Masukkan id dan password" << endl;
    string id_login;
    string pass_login;
    int attempt = 3;
    while (attempt > 0) {
        cout << "ID: ";
        getline(cin, id_login);
        cout << "Password: ";
        getline(cin, pass_login);
        bool authenticated = false;
        for (const User &user : users) {
            if (user.id == id_login && user.pass == pass_login) {
                authenticated = true;
                break;
            }
        }
        if (authenticated) {
            cout << "Berhasil login!" << endl;
            return;
        } else {
            cout << "ID atau password salah!" << endl;
            attempt--;
            cout << "Tersisa: " << attempt << " percobaan" << endl << endl;
            if (attempt == 0) {
                cout << "Anda di kick!" << endl;
                exit(0);
            }
        }
    }
}

void addDrakor(GudangDrakor &gudang) {
    cout << "Tambah drakor" << endl;
    string ulang;
    do {
        cout << "Masukkan judul drakor: ";
        getline(cin, gudang.drakor[gudang.jumlah_data].judul);
        gudang.jumlah_data++;
        cout << "Apakah ingin menambah lagi? (y/n): ";
        cin >> ulang;
        cin.ignore();
    } while (ulang == "y");
}

void listDrakor(const GudangDrakor &gudang) {
    cout << "List drakor" << endl;
    for (int i = 0; i < gudang.jumlah_data; i++) {
        cout << "Drakor ke-" << i + 1 << ": " << gudang.drakor[i].judul << endl;
    }
}

void updateDrakor(GudangDrakor &gudang) {
    int ubah;
    cout << "Ubah data drakor" << endl;
    for (int i = 0; i < gudang.jumlah_data; i++) {
        cout << "Drakor ke-" << i + 1 << ": " << gudang.drakor[i].judul << endl;
    }
    cout << "Masukkan nomor yang ingin diubah: ";
    cin >> ubah;
    cin.ignore();
    cout << "Masukkan judul drakor baru: ";
    getline(cin, gudang.drakor[ubah - 1].judul);
}

void deleteDrakor(GudangDrakor &gudang) {
    int hapus;
    string ulang;
    do {
        cout << "Hapus drakor: ";
        cin >> hapus;
        cin.ignore();
        if (hapus >= 1 && hapus <= gudang.jumlah_data) {
            for (int i = hapus - 1; i < gudang.jumlah_data - 1; i++) {
                gudang.drakor[i] = gudang.drakor[i + 1];
            }
            gudang.jumlah_data--;
        } else {
            cout << "Nomor tidak valid" << endl;
        }
        cout << "Ingin menghapus lagi? (y/n): ";
        cin >> ulang;
    } while (ulang == "y");
}

void menu(GudangDrakor &gudang) {
    int pilih;
    string judul = "Welcome to Gudang Drakor";
    cout << judul << endl;
    cout << "List menu" << endl;
    cout << "1. Tambah drakor" << endl;
    cout << "2. List drakor" << endl;
    cout << "3. Ubah drakor" << endl;
    cout << "4. Hapus drakor" << endl;
    cout << "5. Exit" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilih;
    cin.ignore();
    switch (pilih) {
        case 1:
            addDrakor(gudang);
            break;
        case 2:
            listDrakor(gudang);
            break;
        case 3:
            updateDrakor(gudang);
            break;
        case 4:
            deleteDrakor(gudang);
            break;
        case 5:
            cout << "Program selesai..." << endl;
            return;
        default:
            cout << "Inputan tidak ada" << endl;
    }
    menu(gudang);
}

int main() {
    GudangDrakor gudang;
    gudang.jumlah_data = 0;
    login();
    menu(gudang);
    return 0;
}
#include <iostream>
#include "inventory.h" 

using namespace std;

int main() {
    loadData();

    int pilihan;
    do {
        cout << "MENU INVENTARIS" << endl;
        cout << "1. Tambah Barang (Create)" << endl;
        cout << "2. Tampilkan Barang (Read)" << endl;
        cout << "3. Edit Barang (Update)" << endl;
        cout << "4. Barang Terlaris " << endl;
        cout << "5. Hitung Total Inventori " << endl;
        cout << "6. Hapus Barang (Delete)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahBarang(); break;
            case 2: tampilkanBarang(); break;
            case 3: editBarang(); break;
            case 4: terlaris(); break;
            case 5: totalinventory(); break;
            case 6: hapusBarang(); break;
            case 0: 
                saveData(); 
                cout << "exit"; 
                break;
            default: cout << "tidak valid"; break;
        }
    } while (pilihan != 0);

    return 0;
}
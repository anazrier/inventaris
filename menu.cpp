#include <iostream>
#include <cstdlib> // Untuk fungsi system("cls")
#include "menu.h"
#include "inventory.h"

using namespace std;

void bersihkanlayar() {
    // Gunakan "cls" untuk Windows, atau "clear" jika menggunakan Linux/Mac
    system("cls"); 
}

void tekanenter() {
    cout << "\nTekan enter untuk kembali....";
    cin.ignore();
    cin.get();
    bersihkanlayar();
}

void menuCRUD() {
    int pilihan;
    do {
        bersihkanlayar();
        cout << "==========================================" << endl;
        cout << "            SUB MENU KELOLA DATA          " << endl;
        cout << "==========================================" << endl;
        cout << "1. Tambah Barang (Create)" << endl;
        cout << "2. Tampilkan Barang (Read)" << endl;
        cout << "3. Edit Barang (Update)" << endl;
        cout << "4. Hapus Barang (Delete)" << endl;
        cout << "0. Kembali Ke Menu Utama" << endl;
        cout << "==========================================" << endl;
        cout << "Masukkan Pilihan [0 - 4]: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1 :
                tambahBarang();
                tekanenter();
                break;
            case 2 :
                tampilkanBarang();
                tekanenter();
                break;
            case 3 : 
                editBarang();
                tekanenter();
                break;
            case 4 :
                hapusBarang();
                tekanenter();
                break;
            case 0 : 
                break;
            default :
                cout << endl << "Pilihan Tidak Valid [!]" << endl;
                tekanenter();
                break;
        }
    } while (pilihan != 0); 
}

void menuutama() {
    int pilihan;
    do {
        bersihkanlayar();
        cout << "==========================================" << endl;
        cout << "        SISTEM MANAJEMEN TDR3000          " << endl;
        cout << "==========================================" << endl;
        cout << "1. Kelola Data Barang (CRUD)" << endl;
        cout << "2. Catat Penjualan (Kasir)" << endl;
        cout << "3. Search Barang" << endl;
        cout << "4. Tampilkan Barang Terlaris" << endl;
        cout << "5. Total Nilai Inventori" << endl;
        cout << "0. Keluar dan Simpan" << endl;
        cout << "==========================================" << endl;
        cout << "Pilih Menu [0 - 5]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1 :
                menuCRUD();
                break;
            case 2 :
                catatPenjualan();
                tekanenter();
                break;
            case 3 :
                // cariBarang(); // Memanggil fungsi cari yang dibuat di awal
                tekanenter();
                break;
            case 4 :
                terlaris();
                tekanenter();
                break;
            case 5 : 
                totalinventory();
                tekanenter();
                break;
            case 0 :
                bersihkanlayar();
                saveData(); // Pastikan data tersimpan sebelum benar-benar keluar
                cout << endl << "Menyimpan data..... Program selesai." << endl;
                break;
            default :
                cout << endl << "Pilihan Tidak Valid [!]. Silahkan coba lagi.";
                tekanenter();
                break; 
        }
    } while (pilihan != 0);
}
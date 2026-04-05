#include <iomanip>
#include <iostream>
#include <fstream>
#include "inventory.h"
#include "menu.h"
#include <string>

using namespace std;
DataBarang item;
int jumlahBarang = 0;

void loadData() {
    ifstream file("data_inventaris.txt");
    if (file.is_open()) {
        file >> jumlahBarang;
        file.ignore(); 
        
        for (int i = 0; i < jumlahBarang; i++) {
            getline(file, item.kode[i]);
            getline(file, item.nama[i]);
            file >> item.harga[i];
            file >> item.stok[i];
            file.ignore(); 
        }
        file.close();
        cout << "[INFO] Data Inventaris Berhasil Dimuat." << endl;
    } else {
        cout << "[INFO] Data Inventaris Kosong atau belum dibuat." << endl;
    }
}

void saveData() {
    ofstream file("data_inventaris.txt");
    if (file.is_open()) {
        file << jumlahBarang << endl;
        for (int i = 0; i < jumlahBarang; i++) {
            file << item.kode[i] << endl;
            file << item.nama[i] << endl;
            file << item.harga[i] << endl;
            file << item.stok[i] << endl;
        }
        file.close();
        cout << "[INFO] Data Berhasil Disimpan. " << endl;
    }
}

void tambahBarang() {
    bersihkanlayar();
    cout << "==========================================" << endl;
    cout << "             TAMBAH BARANG BARU           " << endl;
    cout << "==========================================" << endl;
    
    if (jumlahBarang < MAX_DATA) {
        cout << "[+] Masukkan Kode Barang : ";
        cin >> item.kode[jumlahBarang];
        
        cout << "[+] Masukkan Nama Barang : ";
        getline(cin >> ws, item.nama[jumlahBarang]);
        
        cout << "[+] Masukkan Harga Barang: ";
        cin >> item.harga[jumlahBarang];
        
        cout << "[+] Masukkan Stok Barang : ";
        cin >> item.stok[jumlahBarang];
        cout << "==========================================" << endl;
        
        jumlahBarang++;
        saveData();
    } else {
        cout << "[!] Kapasitas Inventaris Sudah Penuh." << endl;
    }
}

void tampilkanBarang() {
    bersihkanlayar();
    cout << endl << "===============================================================" << endl;
    cout << "                        DAFTAR BARANG                          " << endl;
    cout << "===============================================================" << endl;

    if (jumlahBarang > 0) {
        cout << "| " << left << setw(10) << "Kode" 
            << "| " << left << setw(20) << "Nama Barang" 
            << "| " << left << setw(12) << "Harga" 
            << "| " << left << setw(8) << "Stok" << " |" << endl;
        cout << "---------------------------------------------------------------" << endl;
        
        for (int i = 0; i < jumlahBarang; i++) {
            cout << "| " << left << setw(10) << item.kode[i] 
                << "| " << left << setw(20) << item.nama[i] 
                << "| Rp " << left << setw(9) << item.harga[i] 
                << "| " << left << setw(8) << item.stok[i] << " |" << endl;
        }
        cout << "===============================================================" << endl;
    } else {
        cout << " [!] Tidak ada data barang untuk ditampilkan." << endl;
        cout << "===============================================================\n";
    }
}

void editBarang() {
    bersihkanlayar();
    string kode;
    cout << endl << "=======================================" << endl;
    cout << "              EDIT BARANG              " << endl;
    cout << "=======================================" << endl;
    cout << " Masukkan kode barang yang akan diedit: ";
    cin >> kode;
    cout << "---------------------------------------" << endl;
    
    bool found = false;
    for (int i = 0; i < jumlahBarang; i++) {
        if (item.kode[i] == kode) {
            found = true;
            
            cout << " [INFO] Nama Lama  : " << item.nama[i] << endl;
            cout << " [INFO] Harga Lama : Rp " << item.harga[i] << endl;
            cout << " [INFO] Stok Lama  : " << item.stok[i] << endl;
            cout << "---------------------------------------" << endl;
            
            cin.ignore(); 
            
            cout << " [~] Nama baru  : ";
            getline(cin, item.nama[i]); 
            
            cout << " [~] Harga baru : Rp ";
            cin >> item.harga[i];
            
            cout << " [~] Stok baru  : ";
            cin >> item.stok[i];
            
            saveData();
            break;
        }
    }
    
    if (!found) {
        cout << endl << " [!] Barang dengan kode '" << kode << "' tidak ditemukan." << endl;
    }
}

void hapusBarang() {
    bersihkanlayar();
    string kode;
    cout << endl << "=======================================" << endl;
    cout << "              HAPUS BARANG             " << endl;
    cout << "=======================================" << endl;
    cout << " Masukkan kode barang yang akan dihapus: ";
    cin >> kode;
    cout << "---------------------------------------" << endl;
    
    bool found = false;
    for (int i = 0; i < jumlahBarang; i++) {
        if (item.kode[i] == kode) {
            found = true;
            
            cout << " [INFO] Data Barang yang akan dihapus:" << endl;
            cout << " Nama  : " << item.nama[i] << endl;
            cout << " Harga : Rp " << item.harga[i] << endl;
            cout << " Stok  : " << item.stok[i] << endl;
            cout << "---------------------------------------" << endl;
            
            char konfirmasi;
            cout << " Yakin akan menghapus barang ini? (y/n): ";
            cin >> konfirmasi;
            
            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                for (int j = i; j < jumlahBarang - 1; j++) {
                    item.kode[j] = item.kode[j + 1];
                    item.nama[j] = item.nama[j + 1];
                    item.harga[j] = item.harga[j + 1];
                    item.stok[j] = item.stok[j + 1];
                }
                jumlahBarang--;
                saveData(); 
            } else {
                cout << endl << " [BATAL] Penghapusan data barang dibatalkan." << endl;
            }
            
            break; 
        }
    }
    
    if (!found) {
        cout << endl << " [!] Barang dengan kode '" << kode << "' tidak ditemukan." << endl;
    }
}

void catatPenjualan() {
    bersihkanlayar();
    string kode;
    int jumlahBeli;

    cout << endl << "=======================================" << endl;
    cout << "            CATAT PENJUALAN            " << endl;
    cout << "=======================================" << endl;
    cout << " Masukkan kode barang yang dibeli: ";
    cin >> kode;
    cout << "---------------------------------------" << endl;

    bool found = false;
    for (int i = 0; i < jumlahBarang; i++) {
        if (item.kode[i] == kode) {
            found = true;
            
            cout << " [INFO] Nama Barang : " << item.nama[i] << endl;
            cout << " [INFO] Harga       : Rp " << item.harga[i] << endl;
            cout << " [INFO] Stok sisa   : " << item.stok[i] << endl;
            cout << "---------------------------------------" << endl;
            
            cout << "Masukkan jumlah beli: ";
            cin >> jumlahBeli;

            if (jumlahBeli > item.stok[i]) {
                cout << endl << "[!] TRANSAKSI GAGAL: Stok tidak mencukupi!" << endl;
            } else if (jumlahBeli <= 0) {
                cout << endl << "[!] TRANSAKSI GAGAL: Jumlah input tidak valid!" << endl;
            } else {
                item.stok[i] -= jumlahBeli;     
                item.terjual[i] += jumlahBeli;  
                saveData(); 
                
                double totalHarga = item.harga[i] * jumlahBeli;
                cout << endl << " [BERHASIL] Penjualan berhasil dicatat!" << endl;
                cout << " > Total Bayar : Rp " << totalHarga << endl;
                cout << " > Sisa Stok   : " << item.stok[i] << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << endl << " [!] Barang dengan kode '" << kode << "' tidak ditemukan." << endl;
    }
}

void terlaris() {
    if (jumlahBarang == 0) {
        cout << " [!] Data inventaris masih kosong!" << endl;
        return;
    }

    int maxIdx = 0;
    for (int i = 1; i < jumlahBarang; i++) {
        if (item.terjual[i] > item.terjual[maxIdx]) {
            maxIdx = i;
        }
    }

    cout << "\n--- Barang Terlaris ---" << endl;
    cout << "Nama Barang: " << item.nama[maxIdx] << endl;
    cout << "Jumlah Terjual: " << item.terjual[maxIdx] << endl;
    cout << "-----------------------" << endl;
}

void totalinventory() {
    if (jumlahBarang == 0) {
        cout << " [!] Data inventaris masih kosong!" << endl;
        return;
    }

    double total_inventori = 0;
    cout << "\n--- Perhitungan Total Inventori ---" << endl;
    cout << fixed << setprecision(0);

    for (int i = 0; i < jumlahBarang; i++) {
        double subTotal = item.harga[i] * item.stok[i];
        total_inventori += subTotal;

        cout << item.nama[i] << ": Rp" << item.harga[i] << " x " << item.stok[i] << " = Rp" << subTotal << endl;
    }

    cout << "-----------------------------------" << endl;
    cout << "Total Nilai Inventori: Rp" << total_inventori << endl;
    cout << "-----------------------------------" << endl;
}

void cariBarang() {
    bersihkanlayar();
    string kode;

    cout << endl << "=======================================" << endl;
    cout << "            CARI BARANG                " << endl;
    cout << "=======================================" << endl;
    cout << " Masukkan kode barang: ";
    cin >> kode;
    cout << "---------------------------------------" << endl;

    bool ditemukan = false;

    for (int i = 0; i < jumlahBarang; i++) {
        if (item.kode[i] == kode) {
            ditemukan = true;

            cout << " [INFO] Barang ditemukan!" << endl;
            cout << " Kode  : " << item.kode[i] << endl;
            cout << " Nama  : " << item.nama[i] << endl;
            cout << " Harga : Rp " << item.harga[i] << endl;
            cout << " Stok  : " << item.stok[i] << endl;
            cout << "---------------------------------------" << endl;

            break;
        }
    }

    if (!ditemukan) {
        cout << " [!] Barang dengan kode '" << kode << "' tidak ditemukan." << endl;
    }
}
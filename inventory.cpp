#include <iomanip>
#include <iostream>
#include <fstream>
#include "inventory.h"

using namespace std;
DataBarang item;
int jumlahBarang = 0;

// load data
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
        cout << "berhasil";
    } else {
        cout << "kosong";
    }
}

// save data
void saveData() {
    ofstream file("data_inventaris.txt");
    if (file.is_open()) {
        file << jumlahBarang;
        for (int i = 0; i < jumlahBarang; i++) {
            file << item.kode[i];
            file << item.nama[i];
            file << item.harga[i];
            file << item.stok[i];
        }
        file.close();
        cout << "berhasil";
    }
}

//crud
//add item

void tambahBarang() {
    if (jumlahBarang < MAX_DATA) {
        cout << "Masukkan kode barang: ";
        cin >> item.kode[jumlahBarang];
        
        cout << "Masukkan nama barang: ";
        cin >> item.nama[jumlahBarang];
        
        cout << "Masukkan harga barang: ";
        cin >> item.harga[jumlahBarang];
        
        cout << "Masukkan stok barang: ";
        cin >> item.stok[jumlahBarang];
        
        jumlahBarang++;
        saveData();
        cout << "berhasil" << endl;
    } else {
        cout << "penuh" << endl;
    }
}

//show item
void tampilkanBarang() {
    if (jumlahBarang > 0) {
        cout << left << setw(10) << "Kode" 
             << left << setw(20) << "Nama" 
             << left << setw(10) << "Harga" 
             << left << setw(10) << "Stok" << endl;
        for (int i = 0; i < jumlahBarang; i++) {
            cout << left << setw(10) << item.kode[i] 
                 << left << setw(20) << item.nama[i] 
                 << left << setw(10) << item.harga[i] 
                 << left << setw(10) << item.stok[i] << endl;
        }
    } else {
        cout << "ksoong" << endl;
    }
}

//edit item
void editBarang() {
    string kode;
    cout << "Masukkan kode barang yang ingin diedit: ";
    cin >> kode;
    
    bool found = false;
    for (int i = 0; i < jumlahBarang; i++) {
        if (item.kode[i] == kode) {
            found = true;
            cout << "Masukkan nama baru: ";
            cin >> item.nama[i];
            
            cout << "Masukkan harga baru: ";
            cin >> item.harga[i];
            
            cout << "Masukkan stok baru: ";
            cin >> item.stok[i];
            
            saveData();
            cout << "berhasil" << endl;
            break;
        }
    }
    
    if (!found) {
        cout << "tidak ditemukan" << endl;
    }
}

//delete item
void hapusBarang() {
    string kode;
    cout << "Masukkan kode barang yang ingin dihapus: ";
    cin >> kode;
    
    bool found = false;
    for (int i = 0; i < jumlahBarang; i++) {
        if (item.kode[i] == kode) {
            found = true;
            for (int j = i; j < jumlahBarang - 1; j++) {
                item.kode[j] = item.kode[j + 1];
                item.nama[j] = item.nama[j + 1];
                item.harga[j] = item.harga[j + 1];
                item.stok[j] = item.stok[j + 1];
            }
            jumlahBarang--;
            saveData();
            cout << "berhasil" << endl;
            break;
        }
    }
    
    if (!found) {
        cout << "tidak ditemukan" << endl;
    }
}



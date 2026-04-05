#ifndef INVENTARIS_H
#define INVENTARIS_H

#include <string>
using namespace std;

const int MAX_DATA = 100;

struct DataBarang {
    string kode[MAX_DATA];
    string nama[MAX_DATA];
    double harga[MAX_DATA];
    int stok[MAX_DATA];
};


void loadData();
void saveData();

void tambahBarang();
void tampilkanBarang();
void editBarang();
void hapusBarang();

#endif
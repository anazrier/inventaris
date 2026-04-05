#include <iostream>
#include "inventory.h" 
#include "menu.h"

using namespace std;

int main() {
    // 1. Muat data dari file TXT ke dalam memori SoA saat program dihidupkan
    loadData();

    // 2. Beri jeda sebentar agar pesan "[INFO] Data berhasil dimuat" bisa terbaca
    tekanenter();

    // 3. Panggil dan jalankan sistem menu utama
    menuutama();

    return 0;
}
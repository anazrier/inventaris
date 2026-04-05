# Sistem Manajemen Inventori Kelompok 1 (TDR3000)

Sebuah program aplikasi kasir dan manajemen inventori berbasis *Console* (CLI) yang ditulis menggunakan bahasa C++. Program ini mengimplementasikan konsep **Structure of Arrays (SoA)** untuk efisiensi pemrosesan atribut data dan menggunakan struktur kode **Modular** (pemisahan `.h` dan `.cpp`) agar lebih rapi dan mudah di- *maintenance*.

## Anggota Kelompok
Proyek ini dikembangkan oleh:
- **Zaqiah Khurul (125111025)**
- **Sendy Ramadhan (125111028)**
- **Anazri Eriyani (125111043)**

## Fitur Utama
1. **CRUD Data Barang:**
   - Tambah barang baru (Input Kode, Nama, Harga, Stok).
   - Tampilkan seluruh daftar barang dalam bentuk tabel yang rapi.
   - Edit detail barang yang sudah ada.
   - Hapus barang dari sistem.
2. **Sistem Kasir (Catat Penjualan):** Melakukan transaksi pemotongan stok otomatis dan mencatat jumlah barang yang laku terjual.
3. **Analisis Inventori:**
   - Menampilkan barang terlaris berdasarkan riwayat penjualan.
   - Menghitung total valuasi/nilai seluruh barang di inventori.
4. **Penyimpanan Permanen (File I/O):** Data tidak akan hilang saat program ditutup. Seluruh data otomatis dimuat dari dan disimpan kembali ke dalam file `data_inventaris.txt`.

## Struktur File
- `main.cpp` : File utama (*entry point*) untuk menjalankan program.
- `menu.h` & `menu.cpp` : Mengatur tampilan antarmuka (UI) dan navigasi menu.
- `inventory.h` & `inventory.cpp` : Menyimpan struktur data (SoA) dan memuat seluruh logika bisnis (CRUD, perhitungan matematis, dan manajemen *File I/O*).

## Cara Menjalankan Program (Kompilasi)

Karena program ini bersifat modular, seluruh file `.cpp` harus dikompilasi secara bersamaan. 

**Menggunakan Terminal / Command Prompt:**
1. Buka terminal dan arahkan ke direktori tempat file proyek disimpan.
2. Jalankan perintah kompilasi berikut:
   ```bash
   g++ main.cpp menu.cpp inventory.cpp -o program_kasir

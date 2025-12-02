#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

// =====================================
// CLEAR SCREEN (tanpa cstdlib)
// =====================================
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

// =====================================
// STRUCT
// =====================================
struct Item {
    string nama;
    int harga;
};

struct Barang {
    Item Es_Krim[3];
    Item Jajanan[3];
    Item Minuman[3];
    Item Roti[3];
    Item Makanan[3];
} dataBarang = {
    // ================= Es Krim
    {
        {"Vanilla", 5000},
        {"Coklat", 6000},
        {"Strawberry", 7000}
    },

    // ================= Jajanan
    {
        {"Chitato", 8000}, 
        {"Taro", 9000}, 
        {"Lays", 10000}
    },

    // ================= Minuman
    {
        {"Teh Botol", 4000}, 
        {"Aqua", 3000}, 
        {"Coca Cola", 7000}
    },

    // ================= Roti
    {
        {"Roti Tawar", 15000}, 
        {"Roti Coklat", 20000}, 
        {"Roti Keju", 25000}
    },

    // ================= Makanan
    {
        {"Nasi Goreng", 20000}, 
        {"Mie Ayam", 15000}, 
        {"Sate Ayam", 25000}
    }
};

string namaKategori[5] = {
    "Es Krim",
    "Jajanan",
    "Minuman",
    "Roti",
    "Makanan"
};

// =====================================
// FILE I/O
// =====================================
void simpanTransaksi(const string &isi) {
    ofstream file("transaksi.txt", ios::app);
    file << isi << endl;
    file.close();
}

// =====================================
// Tampilkan semua barang dalam kategori
// =====================================
void tampilkanKategori(Item arr[3], string judul) {
    clearScreen();
    cout << "====== " << judul << " ======\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << arr[i].nama 
             << " - Rp " << arr[i].harga << endl;
    }
    cout << "\nTekan ENTER untuk kembali...";
    getch();
}

// =====================================
// MENU DATA BARANG (pilih kategori)
// =====================================
void menuDataBarang() {
    int pilih = 0;

    while (true) {
        clearScreen();
        cout << "======= DATA BARANG =======\n\n";

        for (int i = 0; i < 5; i++) {
            if (i == pilih) cout << "=> ";
            else cout << "  ";
            cout << namaKategori[i] << endl;
        }

        cout << "\nW/S untuk naik turun, ENTER untuk pilih, Q untuk keluar";

        char t = getch();
        if (t == 'w' || t == 'W') pilih = (pilih + 4) % 5;
        else if (t == 's' || t == 'S') pilih = (pilih + 1) % 5;
        else if (t == 13) {
            switch (pilih) {
                case 0: tampilkanKategori(dataBarang.Es_Krim, "Es Krim"); break;
                case 1: tampilkanKategori(dataBarang.Jajanan, "Jajanan"); break;
                case 2: tampilkanKategori(dataBarang.Minuman, "Minuman"); break;
                case 3: tampilkanKategori(dataBarang.Roti, "Roti"); break;
                case 4: tampilkanKategori(dataBarang.Makanan, "Makanan"); break;
            }
        }
        else if (t == 'q' || t == 'Q') break;
    }
}

// =====================================
// MENU TRANSAKSI
// =====================================
void menuTransaksi() {
    clearScreen();

    int total = 0;

    cout << "=========== TRANSAKSI ===========\n";

    while (true) {
        cout << "\nPilih kategori:\n";
        for (int i = 0; i < 5; i++)
            cout << i+1 << ". " << namaKategori[i] << endl;

        cout << "0. Selesai\n";

        int kategori;
        cout << "Kategori: ";
        cin >> kategori;

        if (kategori == 0) break;
        if (kategori < 1 || kategori > 5) continue;

        // pilih array sesuai kategori
        Item* arr;
        switch (kategori) {
            case 1: arr = dataBarang.Es_Krim; break;
            case 2: arr = dataBarang.Jajanan; break;
            case 3: arr = dataBarang.Minuman; break;
            case 4: arr = dataBarang.Roti; break;
            case 5: arr = dataBarang.Makanan; break;
        }

        cout << "\nPilih item:\n";
        for (int i = 0; i < 3; i++)
            cout << i+1 << ". " << arr[i].nama << " - Rp " << arr[i].harga << endl;

        int kode;
        cout << "Kode barang (1-3): ";
        cin >> kode;

        if (kode < 1 || kode > 3) continue;

        int qty;
        cout << "Qty: ";
        cin >> qty;

        int subtotal = arr[kode-1].harga * qty;
        total += subtotal;

        cout << "Subtotal: Rp " << subtotal << endl;
    }

    cout << "\nTOTAL AKHIR: Rp " << total << endl;
    simpanTransaksi("Total transaksi = " + to_string(total));

    cout << "Transaksi disimpan.\nTekan ENTER...";
    getch();
}

// =====================================
// RIWAYAT
// =====================================
void menuRiwayat() {
    clearScreen();
    ifstream file("transaksi.txt");

    cout << "======= RIWAYAT TRANSAKSI =======\n";

    if (!file.is_open()) {
        cout << "Belum ada transaksi.\n";
    } 
    else {
        string line;
        while (getline(file, line)) cout << line << endl;
        file.close();
    }

    cout << "\nTekan ENTER...";
    getch();
}


//====================================
// MENU HAPUS RIWAYAT
//====================================
void menu_hapus_riwayat(){
    int lokasi = 0;
    string pilihan[2] = {"ya", "tidak"};
    while(true){
        clearScreen();
        cout << "======= HAPUS RIWAYAT TRANSAKSI =======" << '\n' << '\n';
        cout << "Apakah anda yakin ingin menghapus riwayat transaksi?" << '\n' << '\n';

        for(int i=0; i<2; i++){
                if(i == lokasi) cout << "=> ";
              else cout << "  ";
                cout << pilihan[i] << '\n';
     }
        cout << "\n" << "W/S untuk navigasi, ENTER untuk pilih.";

        char t = getch();
        if(t == 'w' || t == 'W')
        lokasi = (lokasi + 1) % 2;
        else if(t == 's' || t == 'S')
        lokasi = (lokasi + 1) % 2;
        else if(t == 13){
            if(lokasi == 0){
            ofstream file;
            file.open("transaksi.txt", ios::trunc);
            file.close();
            cout << "\n" << "Riwayat transaksi telah dihapus.";
            cout << "\n" << "Tekan ENTER untuk kembali...";
            getch();
            return;
            } 
            else if(lokasi == 1){
                return;
            }
        }
    }
}

// =====================================
// MENU UTAMA
// =====================================
void Menu_Utama(){;
    string Menu[4] = {
        "Transaksi",
        "Data Barang",
        "Riwayat Transaksi",
        "Hapus Riwayat"
    };

    int Lokasi = 0;

    while(true){
        clearScreen();
        cout << "======= APLIKASI KASIR =======" << '\n' << '\n';

        for(int i=0; i<4; i++){
            if(i == Lokasi) cout << "=> ";
            else cout << "  ";
            cout << Menu[i] << '\n';
        }

        cout << "\n" << "W/S untuk navigasi, ENTER untuk pilih.";

        char T = getch();
        if(T == 'w' || T == 'W') 
        Lokasi = (Lokasi + 3) % 4;
        else if(T == 's' || T == 'S') 
        Lokasi = (Lokasi + 1) % 4;
        else if(T == 13){
            if(Lokasi == 0) menuTransaksi();
            else if(Lokasi == 1) menuDataBarang();
            else if(Lokasi == 2) menuRiwayat();
            else if(Lokasi == 3) menu_hapus_riwayat();
         }
    }
}

// =====================================
int main() {;
    Menu_Utama();
    return 0;
}
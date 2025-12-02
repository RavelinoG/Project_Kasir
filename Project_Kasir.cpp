#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

void ClearScreen(){
    cout << "\033[2J\033[1;H";
}

struct Item{
    string Nama;
    int Harga;
};

struct Barang{
    string Es_Krim[3];
    string Jajanan[3];
    string Minuman[3];
    string Roti[3];
    string Makanan[3];
} hargaBarang= {
    {
    {"Vanilla", 5000},
    {"Coklat", 6000},
    {"Strawberry", 7000}
    },

    {
    {"Chitato", 8000}, 
    {"Taro", 9000}, 
    {"Lays", 10000},
    },

    {
    {"Teh Botol", 4000}, 
    {"Aqua", 3000}, 
    {"Coca Cola", 7000}
    },

    {
    {"Roti Tawar", 15000}, 
    {"Roti Coklat", 20000}, 
    {"Roti Keju", 25000}
    },

    {
    {"Nasi Goreng", 20000}, 
    {"Mie Ayam", 15000}, 
    {"Sate Ayam", 25000}
    }
};

string Nama_Kategori[5] = {
    "Es Krim",
    "Jajanan",
    "Minuman",
    "Roti",
    "Makanan"
};

void Menu_Hapus_Riwayat(){
    int lokasi = 0;
    string pilihan[2] = {"ya", "tidak"};
    while(true){
        ClearScreen();
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

void Menu_Utama(){;
    string Menu[4] = {
        "Transaksi",
        "Data Barang",
        "Riwayat Transaksi",
        "Hapus Riwayat"
    };

    int Lokasi = 0;

    while(true){
        ClearScreen();
        cout << "======= APLIKASI KASIR =======" << '\n\n';

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
            if(Lokasi == 0) Menu_Transaksi();
            else if(Lokasi == 1) Menu_Data_Barang();
            else if(Lokasi == 2) Menu_Riwayat();
            else if(Lokasi == 3) Menu_Hapus_Riwayat();
         }
    }
}

int main (){
    Menu_Utama();
    return 0;
}
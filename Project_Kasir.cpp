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

void Simpan_Transaksi(const string &Isi){
    ofstream file("transaksi.txt", ios::app);
    if(file.is_open()){
        file << Isi << '\n';
        file.close();
    } else {
        cout << "Gagal membuka file transaksi.txt" << endl;
    }
}

void Tampilkan_Kategori(){
    ClearScreen();
    cout << "====== KATEGORI BARANG ======" << '\n';

    for(int i = 0; i < 5; i++){
        cout << i+1 << ". " << Nama_Kategori[i] << '\n';
    }
    cout << "=====================" << endl;
    cout << "Tekan ENTER untuk kembali ";
    getch();
}
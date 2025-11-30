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

void Menu_Data_Barang(){
    ClearScreen();
    cout << "====== DAFTAR BARANG ======" << '\n';

    for(int i = 0; i < JumlahBarang; i++){
        cout << i+1 << ". " << harga[i].Nama << " - Rp " << Barang[i].Harga << '\n';
    }
    cout << "=====================" << endl;
    cout << "Tekan ENTER untuk kembali ";
    getch();
}

void Menu_Tambah_Barang(){
    ClearScreen();
    cout << "====== TAMBAH BARANG ======" << '\n';

    if(JumlahBarang >= 10){
        cout << "Kapasitas barang sudah penuh!" << '\n';
        cout << "Tekan ENTER untuk kembali ";
        getch();
        return;
}

cout << "Nama Barang: ";
cin.ignore();
getline(cin, Barang[JumlahBarang].Nama);

cout << "Harga Barang: ";
cin >> Barang[JumlahBarang].Harga;  
JumlahBarang++;

cout << '\n' << "Barang berhasil ditambahkan!" << '\n';
cout << "Tekan ENTER untuk kembali ";
getch();
}

void Menu_Transaksi(){
    ClearScreen();
    int kode,qty,total=0;
    cout << "====== TRANSAKSI ======" << '\n';

    while(true){
        cout << '\n' << "Masukkan nomor barang (1-" << JumlahBarang << ") (0=selesai): ";
        cin >> kode;

        if(kode=0) break;
        if(kode<1 || kode>JumlahBarang){
            cout << "Kode barang tidak valid!" << '\n';
            continue;
        }

        cout << "Quantity: ";
        cin >> qty;

        int subtotal = Barang[kode-1].Harga * qty;
        total += subtotal;

        cout << "Subtotal: Rp " << subtotal << '\n';
    }
    cout << '\n' << "Total Pembayaran: Rp " << total << '\n';
    Simpan_Transaksi("Total Pembayaran: Rp " + to_string(total));
    cout << "Transaksi disimpan!" << '\n';
    cout << "Tekan ENTER untuk kembali ";
    getch();    
}


int main (){
    cout << "hello guys";
}
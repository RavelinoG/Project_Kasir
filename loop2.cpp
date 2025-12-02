#include <iostream>
using namespace std;

int main () {

int Angka ,sum = 0, hitung = 0;
while (hitung < 10)
{
    cout << "Masukan angka: ";
    cin >> Angka;
    sum+= Angka;
    hitung++;
}
cout << "jumlah: " << sum;
    return 0;
}
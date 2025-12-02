#include <iostream>
using namespace std;
 
int main() {

    float a,b,hasil;
    char operasi;

    cout << "Masukan angka: ";
    cin >> a;
    cout << "Pilih operasi +,-,*,/,%: ";
    cin >> operasi;
    cout << "Masukan angka lagi: ";
    cin >> b;

    cout << "\nHasil dari operasi: ";
    cout << a << operasi << b;
    
        switch (operasi)
    {
    case '+': hasil = a + b;
    break;
    case '-': hasil = a - b;
    break;
    case '*': hasil = a * b;
    break;
    case '/': hasil = a / b;
    break;
    
    default:cout << "operasi yang anda pilih tidak ada" << endl;
        break;
    }
    cout << "= " << hasil << '\n';
    return 0;
}
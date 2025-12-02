#include <iostream>
using namespace std;

int main(){

    float suhu [5],Total;

    cout << "Masukan 5 buah data suhu \n";
    for(int i=0; i<5; i++){
    cout << i+1 << ": ";
    cin >> suhu[i];
    }

    cout << "Data suhu yang anda masukan: \n";
    for (int i=0; i<5 ; i++)
    cout << suhu[i] << '\n';

    float tertinggi = suhu[0];
    for(int i=0; i<5; i++){
        if(suhu[i] > tertinggi){
            tertinggi = suhu[i];
        }
    }
    cout << "Suhu tertinggi adalah: " << tertinggi << '\n';

    for(int i=0; i<5; i++){
        Total += suhu[i];
    }
    cout << "Suhu rata ratanya adalah: " << Total / double(5) << '\n';
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int angka;

    string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan",
        "sepuluh", "sebelas"
    };

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka >= 0 && angka <= 11) {
        cout << satuan[angka];
    }
    else if (angka < 20) {
        cout << satuan[angka - 10] << " belas";
    }
    else if (angka < 100) {
        int puluh = angka / 10;
        int sisa = angka % 10;

        cout << satuan[puluh] << " puluh";

        if (sisa != 0)
            cout << " " << satuan[sisa];
    }
    else if (angka == 100) {
        cout << "seratus";
    }
    else {
        cout << "Angka harus antara 0 - 100";
    }

    return 0;
}

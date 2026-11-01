//main.cpp
#include "Buku.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    List L;
    CreateList(L);

    /* =========================================
       SOAL 1: INSERT DATA & CEK DUPLIKASI
       ========================================= */
    cout << "[ SOAL 1: INPUT DATA ]" << endl;
    infotype b1;
    cout << "masukkan kode buku: "; cin >> b1.kodeBuku;
    cout << "masukkan judul buku: "; cin >> b1.judul;
    cout << "masukkan tahun terbit: "; cin >> b1.thnTerbit;
    insertLast(L, alokasi(b1));
    cout << endl;

    infotype b2;
    cout << "masukkan kode buku: "; cin >> b2.kodeBuku;
    cout << "masukkan judul buku: "; cin >> b2.judul;
    cout << "masukkan tahun terbit: "; cin >> b2.thnTerbit;
    insertLast(L, alokasi(b2));
    cout << endl;

    infotype b3;
    cout << "masukkan kode buku: "; cin >> b3.kodeBuku;
    cout << "masukkan judul buku: "; cin >> b3.judul;
    cout << "masukkan tahun terbit: "; cin >> b3.thnTerbit;
    
    address cek = findElm(L, b3.kodeBuku);
    if (cek != Nil) {
        cout << "kode buku sudah terdaftar" << endl;
    } else {
        insertLast(L, alokasi(b3));
    }
    cout << endl;

    infotype b4;
    cout << "masukkan kode buku: "; cin >> b4.kodeBuku;
    cout << "masukkan judul buku: "; cin >> b4.judul;
    cout << "masukkan tahun terbit: "; cin >> b4.thnTerbit;
    insertLast(L, alokasi(b4));
    cout << endl;

    cout << "DATA LIST 1" << endl;
    cout << endl;
    printInfo(L);
    cout << endl;


    /* =========================================
       SOAL 2: PENCARIAN ELEMEN
       ========================================= */
    cout << "[ SOAL 2: PENCARIAN DATA ]" << endl;
    cout << "Masukkan Kode Buku yang dicari : ";
    string cariKode;
    cin >> cariKode;

    address hasilCari = findElm(L, cariKode);
    if (hasilCari != Nil) {
        cout << endl;
        cout << "Kode Buku   : " << hasilCari->info.kodeBuku << endl;
        cout << "Judul       : " << hasilCari->info.judul << endl;
        cout << "Tahun Terbit: " << hasilCari->info.thnTerbit << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
    cout << endl;


    /* =========================================
       SOAL 3: PENGHAPUSAN ELEMEN
       ========================================= */
    cout << "[ SOAL 3: PENGHAPUSAN DATA ]" << endl;
    cout << "Masukkan Kode Buku yang akan dihapus : ";
    string hapusKode;
    cin >> hapusKode;

    address targetHapus = findElm(L, hapusKode);

    if (targetHapus != Nil) {
        address P;
        if (targetHapus == L.First) {
            deleteFirst(L, P);
        } else if (targetHapus == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = targetHapus->prev;
            deleteAfter(Prec, P);
        }
        dealokasi(P);
        cout << "Data dengan kode buku " << hapusKode << " berhasil dihapus." << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    cout << endl;
    cout << "DATA LIST 1" << endl;
    cout << endl;
    printInfo(L);

    return 0;
}
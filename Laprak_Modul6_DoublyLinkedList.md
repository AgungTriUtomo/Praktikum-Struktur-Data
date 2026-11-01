# <h1 align="center">Laporan Praktikum Modul 6 - Doubly Linked List</h1>
<p align="center">Agung Tri Utomo - 109082500048</p>

## Dasar Teori

Doubly linked list (senarai berantai ganda) adalah struktur data linear yang terdiri dari node-node yang saling terhubung, dengan setiap node memiliki dua pointer yang menunjuk ke node sebelumnya dan node berikutnya [1]. Dibandingkan singly linked list yang hanya dapat ditelusuri satu arah, struktur ini memungkinkan penghapusan node yang cepat dan penelusuran list yang efisien ke dua arah [2]. Seperti linked list pada umumnya, struktur ini cocok untuk data yang sering berubah karena penyisipan dan penghapusan tidak memerlukan pergeseran elemen lain, sedangkan array unggul pada akses langsung berdasarkan indeks [3].

### A. Doubly Linked List<br/>
Pada doubly linked list setiap node menyimpan data serta dua pointer, yaitu `next` ke node sesudahnya dan `prev` ke node sebelumnya. Keberadaan pointer `prev` membuat list dapat ditelusuri maju maupun mundur, dengan konsekuensi memori tambahan untuk satu pointer di setiap node dan pembaruan dua tautan setiap kali terjadi penyisipan atau penghapusan.
#### 1. Node (ElmList)
Setiap elemen (node) terdiri dari tiga bagian: `info` yang menyimpan data, `next` yang menyimpan alamat node selanjutnya, dan `prev` yang menyimpan alamat node sebelumnya. Pada modul ini `info` bertipe `buku` yang berisi `kodeBuku`, `judul`, dan `thnTerbit`, sedangkan `address` adalah pointer ke `ElmList`.
#### 2. List, Pointer First dan Last
List direpresentasikan oleh struct `List` yang memiliki dua field, yaitu `First` yang menunjuk ke node pertama dan `Last` yang menunjuk ke node terakhir. List dinyatakan kosong apabila `First` dan `Last` bernilai `Nil` (`NULL`). `prev` dari node pertama dan `next` dari node terakhir bernilai `Nil`. Adanya pointer `Last` membuat penyisipan di akhir list tidak perlu menelusuri seluruh node.
#### 3. Abstract Data Type (ADT)
Operasi-operasi pada list dikumpulkan dalam sebuah ADT yang terdiri dari file header (`Buku.h`) berisi deklarasi tipe dan prototype, file implementasi (`Buku.cpp`) berisi isi fungsi dan prosedur, serta file `main.cpp` untuk mencoba ADT tersebut.

### B. Operasi Dasar Doubly Linked List<br/>
Operasi dasar mencakup pembuatan list, alokasi dan dealokasi node, penyisipan, penghapusan, pencarian, dan penelusuran seluruh elemen. Operasi insertion dan deletion merupakan operasi utama pada doubly linked list karena keduanya harus menjaga konsistensi pointer `next` dan `prev` [1].
#### 1. Alokasi dan insertLast
Fungsi `alokasi` membuat node baru dengan `new`, mengisi `info`, serta mengatur `next` dan `prev` ke `Nil`. Prosedur `insertLast` menyisipkan node di akhir list: jika list kosong, node menjadi `First` sekaligus `Last`; jika tidak, `prev` node baru diarahkan ke `Last` lama, `next` `Last` lama diarahkan ke node baru, lalu node baru menjadi `Last`.
#### 2. Searching (findElm)
Searching dilakukan dengan mengunjungi setiap node dari `First`, membandingkan data yang dicari dengan `info` node, dan berhenti begitu ditemukan. Jika sampai akhir list tidak ditemukan, fungsi mengembalikan `Nil`. Pencarian tetap bersifat linear sehingga membutuhkan waktu O(n).
#### 3. Delete (deleteFirst, deleteLast, deleteAfter)
Penghapusan pada doubly linked list dibagi menjadi tiga kasus. `deleteFirst` melepas node pertama, `deleteLast` melepas node terakhir, dan `deleteAfter` melepas node yang berada setelah node `Prec`. Pada setiap kasus pointer `next` dan `prev` node tetangga harus diperbarui agar list tetap terhubung dengan benar, dan node yang dilepas kemudian dihapus dari memori dengan `dealokasi`.
#### 4. Traversal (printInfo)
Traversal adalah proses menelusuri seluruh node dengan pointer bantu. Karena adanya pointer `prev`, penelusuran dapat dilakukan dari `First` ke `Last` menggunakan `next`, maupun dari `Last` ke `First` menggunakan `prev` [2].

## Guided

1.Doublylist.h
```c++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

#define Nil NULL

// Latihan 1
struct infotype {
    std::string nopol; 
    std::string warna; 
    int thnBuat;      
};
typedef struct elmlist *address;
struct elmlist {
    infotype info;  
    address next;   
    address prev;   
};
struct List {
    address First; 
    address Last;  
};


// Latihan 1
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Latihan 2

address findElm(List L, std::string nopol);

// Latihan 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteElm(List &L, std::string nopol, bool &status);

#endif
```
Penjelasan : File ini mendeklarasikan struktur data dasar untuk Doubly Linked List. Terdiri dari struct infotype (data kendaraan), struct elmlist (node yang memiliki pointer next dan prev), dan struct List (menyimpan pointer First dan Last). File ini juga mendeklarasikan prototipe fungsi operasi dasar seperti pembuatan list, alokasi, insert, delete, dan pencarian.


2. Doublylist.cpp

```C++
#include "Doublylist.h"

// Latihan 1
void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil; 
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void printInfo(List L) {
    address P = L.Last;
    if (P == Nil) {
        std::cout << "List kosong." << std::endl;
        return;
    }
    while (P != Nil) {
        std::cout << "no polisi : " << P->info.nopol << std::endl;   
        std::cout << "warna     : " << P->info.warna << std::endl;   
        std::cout << "tahun     : " << P->info.thnBuat << std::endl; 
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) { 
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;         
        (L.Last)->next = P;     
        L.Last = P;               
    }
}

// Latihan 2
address findElm(List L, std::string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Latihan 3
void deleteFirst(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.First; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;     
        (L.First)->prev = Nil; 
        P->next = Nil;         
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.Last; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;      
        (L.Last)->next = Nil; 
        P->prev = Nil;         
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) return;

    P = Prec->next;
    if (P == L.Last) {
        deleteLast(L, P);
    } else {
        Prec->next = P->next;     
        (P->next)->prev = Prec; 
        P->next = Nil;            
        P->prev = Nil;           
    }
}

void deleteElm(List &L, std::string nopol, bool &status) {
    address P = findElm(L, nopol);
    status = false;

    if (P != Nil) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P); 
        status = true;
    }
}
```
Penjelasan :File ini berisi implementasi logika dari fungsi-fungsi yang dideklarasikan di header. Fungsi insertLast menambahkan node di akhir list dengan mengatur ulang pointer prev dan next antar node. Prosedur printInfo menampilkan data dengan iterasi mundur dari Last ke First. Fungsi findElm melakukan pencarian berdasarkan nomor polisi. Sedangkan prosedur deleteElm berfungsi sebagai wrapper yang mencari posisi node lalu memanggil fungsi deleteFirst, deleteLast, atau deleteAfter yang sesuai untuk menghapus node tersebut dari list.

3. main.cpp

```c++
#include <iostream>
#include "Doublylist.h"
using namespace std;

void inputData(List &L) {
    infotype data;
    address P;

    cout << "masukkan nomor polisi: "; cin >> data.nopol;
    cout << "masukkan warna kendaraan: "; cin >> data.warna;
    cout << "masukkan tahun kendaraan: "; cin >> data.thnBuat;
    if (findElm(L, data.nopol) == Nil) {
        P = alokasi(data); 
        insertLast(L, P);  
    } else {
        cout << "nomor polisi sudah terdaftar" << endl; 
    }
}

int main() {
    List L;
    CreateList(L); 
    address P;

    // Latihan 1
    inputData(L); 
    inputData(L); 
    inputData(L); 
    inputData(L); 

    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    // Latihan 2
    string nopolCari;
    cout << "\nMasukkan Nomor Polisi yang dicari : "; 
    cin >> nopolCari; 
    
    P = findElm(L, nopolCari); 
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl; 
        cout << "Warna        : " << P->info.warna << endl; 
        cout << "Tahun        : " << P->info.thnBuat << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolCari << " tidak ditemukan." << endl;
    }

    // Latihan 3
    string nopolHapus;
    bool hapusBerhasil;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopolHapus;

    deleteElm(L, nopolHapus, hapusBerhasil); 

    if (hapusBerhasil) {
        cout << "Data dengan nomor polisi " << nopolHapus << " berhasil dihapus." << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan." << endl;
    }
    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    return 0;
}
```
Penjelasan : File ini adalah program utama untuk menguji ADT. Program melakukan input data kendaraan dengan pengecekan duplikasi nomor polisi menggunakan findElm sebelum dimasukkan ke list. Setelah itu, program menguji fungsi pencarian data berdasarkan input pengguna, lalu menguji prosedur penghapusan data. Setelah penghapusan, program menampilkan kembali isi list untuk memverifikasi bahwa data telah berhasil dihapus.

## Unguided

### 1. Pembuatan ADT Dasar dan Insert Data
Buatlah ADT Doubly Linked List sebagai berikut di dalam file "Buku.h": Type infotype : buku < kodeBuku : string judul : string thnTerbit : integer

Type address : pointer to ElmList Type ElmList < info : infotype next : address prev : address

Type List < First : address Last : address

procedure CreateList( input/output L : List ) function alokasi( x : infotype ) -> address procedure dealokasi( input/output P : address ) procedure printInfo( input L : List ) procedure insertLast( input/output L : List, input P : address ) Buatlah implementasi ADT Doubly Linked List pada file “Buku.cpp" dan cobalah hasil implementasi ADT tersebut pada file "main.cpp". Pastikan sistem melakukan pengecekan duplikasi kodeBuku sebelum memasukkan data baru ke dalam list.

### 2.Pencarian Elemen (Searching)
Carilah elemen dengan kode buku B001 dengan membuat fungsi baru: fungsi findElm( L : List, x : infotype ) : address

### 3. Penghapusan Elemen (Delete)
Hapus elemen dengan kode buku B003 dengan membuat prosedur delete berikut: procedure deleteFirst( input/output L : List, input/output P : address ) procedure deleteLast( input/output L : List, input/output P : address ) procedure deleteAfter( input Prec : address, input/output P : address )


**Buku.h**
```C++
//Buku.h
#ifndef BUKU_H
#define BUKU_H

#include <iostream>
#include <string>
using namespace std;

#define Nil NULL

/* =========================================
   SOAL 1: PEMBUATAN ADT DASAR
   ========================================= */
struct buku {
    string kodeBuku;
    string judul;
    int thnTerbit;
};

typedef buku infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);


/* =========================================
   SOAL 2: PENCARIAN ELEMEN
   ========================================= */
address findElm(List L, string kodeBuku);


/* =========================================
   SOAL 3: PENGHAPUSAN ELEMEN
   ========================================= */
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```

**Buku.cpp**
```C++
//Buku.cpp
#include "Buku.h"
#include <iostream>

using namespace std;

/* =========================================
   SOAL 1: PEMBUATAN ADT DASAR & INSERT
   ========================================= */
void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
        P->prev = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    if (P == Nil) {
        cout << "List Kosong" << endl;
    } else {
        while (P != Nil) {
            cout << "kode buku  : " << P->info.kodeBuku << endl;
            cout << "judul      : " << P->info.judul << endl;
            cout << "tahun      : " << P->info.thnTerbit << endl;
            P = P->next;
        }
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

/* =========================================
   SOAL 2: PENCARIAN ELEMEN
   ========================================= */
address findElm(List L, string kodeBuku) {
    address P = L.First;
    bool found = false;
    while (P != Nil && !found) {
        if (P->info.kodeBuku == kodeBuku) {
            found = true;
        } else {
            P = P->next;
        }
    }
    return P;
}

/* =========================================
   SOAL 3: PENGHAPUSAN ELEMEN
   ========================================= */
void deleteFirst(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First == L.Last) {
        P = L.First;
        L.First = Nil;
        L.Last = Nil;
        P->next = Nil;
        P->prev = Nil;
    } else {
        P = L.First;
        L.First = L.First->next;
        L.First->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First == L.Last) {
        P = L.Last;
        L.First = Nil;
        L.Last = Nil;
        P->next = Nil;
        P->prev = Nil;
    } else {
        P = L.Last;
        L.Last = L.Last->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            P->next->prev = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    } else {
        P = Nil;
    }
}
```

**main.cpp**
```C++
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
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/AgungTriUtomo/109082500048_AgungTriUtomo_Modul6/blob/main/Output_Modul6/OutputSoal.png)


1. Pembuatan ADT Dasar dan Insert Data (Soal 1)
Pada soal pertama, program main.cpp digunakan untuk memasukkan empat data buku ke dalam Doubly Linked List. Sebelum data disimpan, program memeriksa terlebih dahulu apakah kode buku sudah terdapat di dalam list dengan menggunakan fungsi findElm. Jika kode buku ternyata sudah digunakan, seperti B001 pada input ketiga, maka data tidak akan dimasukkan dan program menampilkan pesan "kode buku sudah terdaftar". Namun, jika kode belum ada, program akan membuat node baru menggunakan fungsi alokasi, kemudian menyimpannya di bagian akhir list melalui insertLast. Setelah seluruh proses input selesai, fungsi printInfo dijalankan untuk menampilkan semua data buku yang berhasil disimpan secara berurutan.
2. Pencarian Elemen (Soal 2)
Pada soal kedua, dilakukan pengujian terhadap fungsi findElm untuk mencari data buku berdasarkan kode yang dimasukkan pengguna. Sebagai contoh, pengguna mencari buku dengan kode B001. Proses pencarian dimulai dari elemen pertama list (L.First), kemudian dilanjutkan ke elemen berikutnya menggunakan pointer next sampai kode buku yang dicari ditemukan. Jika data tersedia, fungsi akan mengembalikan alamat node yang sesuai sehingga informasi buku berupa kode, judul, dan tahun terbit dapat ditampilkan. Sebaliknya, jika kode tidak ditemukan sampai akhir list (Nil), program akan memberikan pesan bahwa buku tersebut tidak tersedia.
3. Penghapusan Elemen (Soal 3)
Pada soal ketiga, program digunakan untuk mencoba proses penghapusan data buku dari Doubly Linked List. Pengguna diminta memasukkan kode buku yang ingin dihapus, misalnya B003. Pertama, program mencari data tersebut menggunakan fungsi findElm. Apabila data berhasil ditemukan, program akan memeriksa letak node yang akan dihapus. Karena B003 berada di posisi tengah, program mengambil node sebelumnya menggunakan pointer Prec, kemudian menjalankan prosedur deleteAfter untuk melepaskan node tersebut dari list. Setelah hubungan antar-node diperbaiki, memori dari node yang dihapus dibebaskan menggunakan fungsi dealokasi. Terakhir, fungsi printInfo dipanggil kembali untuk menampilkan data yang tersisa dan memastikan bahwa buku dengan kode B003 sudah berhasil dihapus.



## Kesimpulan
Pada praktikum ini ADT doubly linked list berhasil diimplementasikan dalam tiga file, yaitu `Buku.h`, `Buku.cpp`, dan `main.cpp`. Operasi `insertLast` memanfaatkan pointer `Last` sehingga penyisipan di akhir list tidak perlu menelusuri seluruh node, dan pengecekan duplikasi `kodeBuku` mencegah data ganda masuk ke dalam list. Operasi searching (`findElm`) bertumpu pada penelusuran node satu per satu dari `First`, sedangkan operasi delete (`deleteFirst`, `deleteLast`, dan `deleteAfter`) harus memperbarui pointer `next` dan `prev` agar list tetap konsisten. Pointer `prev` juga memungkinkan penelusuran mundur dari `Last`, sebagaimana digunakan pada `printInfo`. Praktikum ini menunjukkan bahwa doubly linked list lebih fleksibel dibandingkan singly linked list, dengan konsekuensi memori tambahan untuk satu pointer pada setiap node.

## Referensi
[1] Wijoyo, A., Prayudi, L. A., Fiqih, M., Santoso, R. D., Putra, R. T. S., Arifin, T., & Farhan, A. (2024). "Penggunaan Algoritma Doubly Linked List Untuk Insertion Dan Deletion". JRIIN: Jurnal Riset Informatika dan Inovasi, 1(12), 1329–1331. Diakses melalui https://jurnalmahasiswa.com/index.php/jriin/article/view/1282.
<br>[2] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). "Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List". JUTECH, 5(2). Diakses melalui https://www.jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263.
<br>[3] Sofianti, H. A., Manullang, Y. V., Tampubolon, N. A., Naibaho, L. H., & Gunawan, I. (2025). "Implementasi Struktur Data Array dan Linked List dalam Pengelolaan Data Mahasiswa". Menulis: Jurnal Penelitian Nusantara, 1(6), 871–877. https://doi.org/10.59435/menulis.v1i6.417.

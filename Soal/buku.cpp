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
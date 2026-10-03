#include <iostream>
using namespace std;

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

int main() {
    int a, b, c;

    cout << "Masukkan nilai a: ";
    cin >> a;

    cout << "Masukkan nilai b: ";
    cin >> b;

    cout << "Masukkan nilai c: ";
    cin >> c;

    cout << "\nSebelum ditukar: ";
    cout << a << " " << b << " " << c << endl;

    tukarPointer(&a, &b, &c);

    cout << "Setelah ditukar: ";
    cout << a << " " << b << " " << c << endl;

    return 0;
}

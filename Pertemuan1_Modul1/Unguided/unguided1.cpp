#include <iostream>
using namespace std;

int main() {
 float bil1, bil2;

 cout << "bilangan pertama : ";
 cin >> bil1;
 cout << "bilangan kedua : ";
 cin >> bil2;

 cout << "Penjumlahan (" << bil1 << " + " << bil2 << ") = " << bil1 + bil2 << endl;
 cout << "Pengurangan (" << bil1 << " - " << bil2 << ") = " << bil1 - bil2 << endl;
 cout << "Perkalian   (" << bil1 << " * " << bil2 << ") = " << bil1 * bil2 << endl;
 cout << "Pembagian (" << bil1 << " / " << bil2 << ") = " << bil1 / bil2 << endl;
 return 0;
}

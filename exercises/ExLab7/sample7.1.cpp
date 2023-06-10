#include <iostream>
using namespace std;
class liczba {
int wartosc;
public:
liczba (int l) { wartosc = l; } // konstruktor
void wysw() { cout << wartosc << endl; }
};
main() {
liczba p = liczba(5);
liczba s(7);
cout << "piec = ";
p.wysw();
cout << "siedem = ";
s.wysw();
return 0;
}
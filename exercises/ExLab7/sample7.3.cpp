#include <iostream>
using namespace std;
class procesor {
int l_watkow;
int l_rdzeni;
public:
procesor (); //konstruktor bezargumentowy
procesor(int, int); //konstruktor 2 argumentowy
procesor (int); //konstruktor jednoargumentowy
~procesor(); //destruktor
void wysw_param();
};
procesor::procesor (int a, int b) {
l_watkow = a;
l_rdzeni = b;
}
procesor::procesor() {
l_watkow = 1;
l_rdzeni = 1;
}
procesor::procesor(int a) {
l_watkow = 1;
l_rdzeni = a;
}
procesor::~procesor(){
cout << "Obiekt zostal zniszczony" << endl;
}
void procesor::wysw_param() {
cout << "\nProcesor posiada " << l_watkow << " watkow";
cout << "\nProcesor posiada " << l_rdzeni << " rdzeni";
}
main() {
procesor i5(4,4);
procesor i7(8,4);
procesor p3;
procesor c2d(2);
cout << "Program przechowuje i wyswietla informacje na temat "
<< "procesorow\n";
cout << "\n\tp3\n";
p3.wysw_param();
cout << endl;
cout << "\n\tc2d\n";
c2d.wysw_param();
cout << endl;
cout << "\n\ti5\n";
i5.wysw_param();
cout << endl;
cout << "\n\ti7\n";
i7.wysw_param();
cout << endl;
return 0;
}
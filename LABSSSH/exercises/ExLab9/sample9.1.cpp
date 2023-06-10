#include <iostream>
using namespace std;
class hero {
int str, dex, vit, int, cha;
public:
void przyp_atr (int x) {
str = x; dex = x; vit = x; int = x;
cha = x;
}
void wysw_atr() {
cout<<"\t\t\tHero stats:"<<endl;
cout<<"\tStrength: "<<str<<endl;
cout<<"\tDexterity: "<<dex<<endl;
cout<<"\tInteligence: "<<int<<endl;
cout<<"\tVitality: "<<vit<<endl;
cout<<"\tCharisma: "<<cha<<endl;
}
};
class knight : public hero {
public:
knight (int l){
przyp_atr(l);
wysw_atr();
}
};
main() {
int b;
do {
if (b > 9) {
cout<<"Learn to read! the number supposed to be "
<<"from 0 to 9"<<endl;
}
cout << "Your knight is being created. "
<< "Enter a number from 0 to 9: "<<endl;
cin>>b;
} while (b>9);
knight r1(b);
return 0;
}
#include <iostream>

 using namespace std;

 class base {
 public:
 void hat() {
 cout << "Random empty hat" << endl;
 }
 };

 class derived
 : public base {
 public:
 void hat() { /hiding base class method
 cout << "Hat with magical rabbit inside!" << endl;
 }
 };

 int main() {
 base empty;
 derivative full; empty.hat();
full.hat();

 base * ptr = & full;
  ptr->hat();
 }
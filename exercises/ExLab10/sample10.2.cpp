#include <iostream>

 using namespace std;

 class base {
 public:
 virtual void hat() {
 cout << "Random empty hat" << endl;
 }
 };

 class derived
 : public base {
 public:
 virtual void hat() { /hiding base class method
 cout << "Hat with magical rabbit inside!" << endl;
 }
 };

 int main() {
 base empty;
 derivative full;

 empty.hat();
 full.hat();
base * ptr = & full;
 ptr->hat();
 }
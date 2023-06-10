#include<iostream>
 #include<string>

 using namespace std;

 class vehicle{
 protected:
 int wheels;
 float engineCapacity;
 string engineType;
 string vehicleName;

 public:
 virtual ~vehicle(){};
 virtual void engineStart()=0;
 virtual void engineStop()=0;
 virtual void displayStats()=0;


 };
class car: public vehicle{
 float trunkCapacity;
 public:
 car(int w, float ec, float tc, string et, string vn){
 wheels = w;
 engineCapacity = ec;
 engineType = et;
 vehicleName = vn;
 trunkCapacity = tc;

 }
 ~car(){
 cout<<"Car destroyed!"<<endl;
 }
 void engineStart(){
 cout<< "Checking engine..."<<endl;
 cout << engineCapacity <<"L "<< engineType << " roars loudly!"<<endl;
 }
 void engineStop(){
 cout<< engineType << " modestly stops"<<endl;
 }
 void displayStats(){
 cout << "Car name: " <<vehicleName << endl;
 cout << "Engine type: "<<engineType<<", capacity:"<<engineCapacity<<"L"<<endl;
    cout << "Trunc capacity: "<<trunkCapacity<<endl;
 cout << "This vehicle has "<<wheels<<" wheels"<<endl;
 }
 void car_Name(){
 cout<< vehicleName;
 }
 };

 class motobike: public vehicle{

 public:
 motobike(int w, float ec, string et, string vn){
 wheels = w;
 engineCapacity = ec;
 engineType = et;
 vehicleName = vn;
}
 ~motobike(){
 cout<<"Bike destroyed!"<<endl;
 }
 void engineStart(){
 cout << "Engine roars loudly!"<<endl;
 }
 void engineStop(){
 cout<< "Engine modestly stops"<<endl;
 }
 void displayStats(){
 cout << "Bike name: " <<vehicleName << endl;
 cout << "Engine type: "<<engineType<<", capacity:"<<engineCapacity<<"L"<<endl;
 cout << "This vehicle has "<<wheels<<" wheels"<<endl;
 }
 void bike_Name(){
 cout<< vehicleName;
 }
 };

 int main(){
 car camaro(4,6.5,257.68,"L78 V8","1969 Camaro SS 396â");
 motobike rocket(2,2.3,"In-line three, four-stroke", "TriumphRocket III Roadster");

 int a;
 vehicle *choice;

 do{
 cout<<"Pick your ride: "<<endl<<"1.";camaro.car_Name();cout<<"."<<endl;
cout<< "2. ";rocket.bike_Name();cout<<"."<<endl;
 cin>>a;
 }while (a!=1&&a!=2);

 if (a==1)choice=&camaro;
 else choice=&rocket;

 cout <<"You have chosen your ride!"<<endl;
 choice->displayStats();
 choice->engineStart();
    cout<<"Shame itâs just a virual vehicle :("<<endl;
 choice->engineStop();


 return 0;
 }

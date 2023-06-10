#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int numberOfProducts = 5;
const float productsPrice[numberOfProducts]={6.00, 6.30, 3.00, 5.00, 4.38};
int stock[numberOfProducts] ={10, 12, 12, 15, 20};
const string productsName[numberOfProducts] = {"Cola", "Pepsi", "Water","Chips","Mars" };


void vendingMachineMenu ()
{
    cout << "CODE    Product  Pcs      Price" << endl;
    for ( int i = 0; i < numberOfProducts; i++)
    {
        cout << i + 1 << "    * " << productsName[i] << "   \t* " << stock[i] << " \t- " << productsPrice[i] << " zlt" << endl;
    }
    
}

int howMany (int userChoice)
{
    int quantity;
    cout << "Please enter the quantity of the product you picked: ";
    cin >> quantity;
    while (quantity > stock[userChoice])
    {
        cout << " Not Enough Product :'(\nAvailable quantity for the selected product is:  "<<  stock[userChoice] << "\n Please enter a valid quantity:"  << endl;
        cin >> quantity;
    } ;
     return quantity;
    
}


int main ()
{
    int userChoice;
    int quantity;

    vendingMachineMenu();
    
while (userChoice != 1001) {
    if (userChoice != 1001) 
    {
    cout << "Please select product: " << endl;
    cin >> userChoice;
    userChoice = userChoice - 1;

 switch (userChoice)
    {
 case 0:
     cout << "You have picked " << productsName[userChoice] << " Available quantity is: " << stock[userChoice] << endl;
    // howMany(userChoice);
    quantity = howMany(userChoice);
    stock[userChoice] = stock[userChoice] - quantity ;
        break;

 case 1:
     cout << "You have picked " << productsName[userChoice] << " Available quantity is: " << stock[userChoice] << endl;
    // howMany(userChoice);
    quantity = howMany(userChoice);
    stock[userChoice] = stock[userChoice] - quantity ;
        break;

 case 2:
     cout << "You have picked " << productsName[userChoice] << " Available quantity is: " << stock[userChoice] << endl;
    // howMany(userChoice);
    quantity = howMany(userChoice);
    stock[userChoice] = stock[userChoice] - quantity ;
        break; 

 case 3:
     cout << "You have picked " << productsName[userChoice] << " Available quantity is: " << stock[userChoice] << endl;
    // howMany(userChoice);
    quantity = howMany(userChoice);
    stock[userChoice] = stock[userChoice] - quantity ;
        break; 

 case 4:
     cout << "You have picked " << productsName[userChoice] << " Available quantity is: " << stock[userChoice] << endl;
    // howMany(userChoice);
    quantity = howMany(userChoice);
    stock[userChoice] = stock[userChoice] - quantity ;
        break; 

 default:
    cout << "\nPlease enter a valid Choice.\n"<< endl;
        break; 
        
    }
    vendingMachineMenu();
    }
    // 1002 to exit;
    else {
        cout << "Vending Machine Out Of Service :((((" << endl; //Whyy it doesnt WORK :(((((((
        exit(1);
         }
} 

}




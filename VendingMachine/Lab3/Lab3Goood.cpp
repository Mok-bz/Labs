#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Item{
    string name;
    int quantity;
    float price;
};

struct AvailableCoin{
    float coin;
    int quantity;

};

int quantityOfEnteredCoins[6];

const int numberOfProducts = 5;




vector<AvailableCoin> readCashPoolData()
    {
    ifstream file("pool.txt"); // open the file for reading
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
    exit ;
    };

    vector<AvailableCoin> availableCoins;
    float coin;
    int quantity;

    while (file >> coin >> quantity)
    {
        AvailableCoin availableCoin = { coin, quantity };
        availableCoins.push_back(availableCoin); // add new element to the end of the vector
    }
    file.close(); // close the file
    return availableCoins;
    }


    vector<Item> readData()
    {
    ifstream file("data.txt"); // open the file for reading


    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
    exit ;
    };

    vector<Item> items; // create a vector to store the items
    string name,note;
    int quantity;
    float price;


    while (file >> name >> quantity >> price >> note) {
        if (note == "needs-more-products" ) quantity += 10;
        Item item = { name,quantity,price };
        items.push_back(item); // add new element to the end of the vector


    }

        file.close(); // close the file

    return (items) ;

    }

    void printItems(vector<Item> items)
    {
            for (int i = 0; i < 5; i++)
        {
            cout << "Code: " << i + 1 << ", Name: " << items[i].name << ", \tQuantity: " << items[i].quantity << ", \tPrice: " << items[i].price << " Zlt" << endl;
        }
    }

         void updateData (vector<Item> menuNew)
         {
        fstream file;
        file.open("data.txt", ios::in | ios::out | ios::trunc);
            if (file.good() == true)
            {
                cout << "External menu updated...." << endl;

            }

    for (int i = 0; i < numberOfProducts ; i++)
    {
    string productsNameList;
    if (menuNew[i].quantity != 0 )
    {

    file << menuNew[i].name << " " << menuNew[i].quantity << " " << menuNew[i].price << " --" << endl ;

    }else{
       file << menuNew[i].name << " " << menuNew[i].quantity << " " << menuNew[i].price << " needs-more-products" << endl ;
    }
    }

         }

    int howMany (int userChoice, vector<Item> items)
    {
    int quantity;
    cout << "Please enter the quantity of the product you picked: ";
    cin >> quantity;
         while (quantity > items[userChoice].quantity)
         {
            cout << " Not Enough Product :'(\nAvailable quantity for the selected product is:  "<<  items[userChoice].quantity << "\n Please enter a valid quantity:"  << endl;
            cin >> quantity;
         } ;
     return quantity;
    }
    bool isValidCoin(double input,vector<AvailableCoin> availableCoins )
    {
    bool valid = false;
    float valid_coin[6] = {5,2,1,0.5,0.2,0.1};
    for (int i = 0; i < 6; i++)
    {
        if (input==valid_coin[i] )
        {
            valid = true;
        }
    }
    return valid;
    }
void coinswriting(vector<AvailableCoin> availableCoins)
{
    fstream pool2;

    pool2.open("pool.txt", ios::out);
    if (pool2.good() == true)
    {

        for (int i = 0; i < 6; i++)
        {
            pool2 << availableCoins[i].coin <<" "<< availableCoins[i].quantity << endl;
        }
    }

    else
        cout << "File access forbidden " << endl;
    pool2.close();
}
void setEnteredAmount(float *enteredAmount)
{
    float input;
    cin >> input;
    *enteredAmount=input;
}
int main ()
{
vector<AvailableCoin> availableCoins = readCashPoolData() ;

vector<Item> menuNew = readData() ;
printItems(menuNew);

    int userChoice;
    int quantity;
    float enteredAmount;
while (userChoice != 1001) {
    if (userChoice != 1001)
    {
    cout << "Please select product: " << endl;
    cin >> userChoice;
    userChoice = userChoice - 1;

        if (userChoice <= 4 && userChoice >= 0)
            {
            
            cout << "You have picked " << menuNew[userChoice].name << " Available quantity is: " << menuNew[userChoice].quantity << endl;
            quantity = howMany(userChoice, menuNew);
            float totalMoney = menuNew[userChoice].price * quantity;
            menuNew[userChoice].quantity = menuNew[userChoice].quantity - quantity ;
            cout << "Price is: " << totalMoney << endl;
            cout << "Please enter " << totalMoney << endl;
            enteredAmount = 0;
          while (true)
        {

            while (!isValidCoin(enteredAmount,availableCoins))
            {
                cout << "enter correct coin ";
                setEnteredAmount(&enteredAmount);
            }
                if (enteredAmount == 5)
                {
                    quantityOfEnteredCoins[0] += 1;
                }
                else if (enteredAmount == 2)
                {
                    quantityOfEnteredCoins[1] += 1;
                }
                else if (enteredAmount == 1)
                {
                    quantityOfEnteredCoins[2] += 1;
                }
                else if (enteredAmount == 0.5)
                {
                    quantityOfEnteredCoins[3] += 1;
                }
                else if (enteredAmount == 0.2)
                {
                    quantityOfEnteredCoins[4] += 1;
                }
                else if (enteredAmount == 0.1)
                {
                    quantityOfEnteredCoins[5] += 1;
                }


            // check if the amount is fully paid
            if (totalMoney == enteredAmount)
            {
                cout << "Purchase succeded  " << endl;
                for (int i=0 ; i<6 ;i++)
                {
                    availableCoins[i].quantity+=quantityOfEnteredCoins[i];
                }


            coinswriting(availableCoins);
                break;
            }
            else if (enteredAmount > totalMoney)
            {
                // if more then return the excess
                // put the change here ...

                double difference = enteredAmount - totalMoney;

                while (difference > 0)
                {
                    if (difference >= 5 && availableCoins[0].quantity > 0)
                    {
                        availableCoins[0].quantity -= 1; // Which coin gets -1 from the quantity.
                        difference -= 5;    // To calculate the change.
                        cout << "5 PLN dropped\n";
                    }
                    else if (difference >= 2 && availableCoins[1].quantity > 0)
                    {
                        availableCoins[1].quantity -= 1;
                        difference -= 2;
                        cout << "2 PLN dropped\n";
                    }
                    else if (difference >= 1 && availableCoins[2].quantity > 0)
                    {
                        availableCoins[2].quantity -= 1;
                        difference -= 1;
                        cout << "1 PLN dropped\n";
                    }
                    else if (difference >= 0.5 && availableCoins[3].quantity > 0)
                    {
                        availableCoins[3].quantity -= 1;
                        difference -= 0.5;
                        cout << "0.5 PLN dropped\n";
                    }
                    else if (difference >= 0.2 && availableCoins[4].quantity > 0)
                    {
                        availableCoins[4].quantity -= 1;
                        difference -= 0.2;
                        cout << "0.2 PLN dropped\n";
                    }
                    else if (difference >= 0.1 && availableCoins[5].quantity > 0)
                    {
                        availableCoins[5].quantity -= 1;
                        difference -= 0.1;
                        cout << "0.1 PLN dropped\n";
                    }
                    else
                    {
                        cout << "Unable to give a change, deduct the payment in cash" << endl;
                        return 0;
                    }
                }
                for (int i=0 ; i<6 ;i++)
                {
                    availableCoins[i].quantity+=quantityOfEnteredCoins[i];
                }

            coinswriting(availableCoins);
                break;
            }
            else
            {
                cout << "You need to enter more" << endl;
                double remaining = totalMoney - enteredAmount;
                cout << "Please enter remaining coins " << remaining << " PLN" << endl;
                cin >> enteredAmount;
                totalMoney = remaining;
            }
            coinswriting(availableCoins);
        }

            }

         else {

               cout << "\nPlease enter a valid Choice."<< endl;

                }

    printItems(menuNew);
    }
    // 1002 to exit;
    else {
        cout << "Vending Machine Out Of Service :((((" << endl; //Whyy it doesnt WORK :(((((((
        exit(1);
         }

         updateData (menuNew);

 }

}




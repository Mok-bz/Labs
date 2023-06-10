#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "struct.cpp"
using namespace std;

class VendingMachine
{
public:
    vector<AvailableCoin> CashPool;
    vector<Item> Products;
    int UserChoice;
    int QuantityChoiced;
    float EnteredAmount;
    int QuantityOfEnteredCoins[6]={0};

public:
    VendingMachine()
    {
        readData();
        readCashPoolData();
        UserChoice=0;
        QuantityChoiced=0;
        EnteredAmount=0;
    };
    void printItems()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Code: " << i + 1 << ", Name: " << Products[i].name << ", \tQuantity: " << Products[i].quantity << ", \tPrice: " << Products[i].price << " Zlt" << endl;
        }
    }
    void readCashPoolData()
    {
        ifstream file("pool.txt"); // open the file for reading
        if (!file.is_open())
        {
            cout << "Error: Unable to open file." << endl;
            exit(1);
        };

        float coin;
        int quantity;

        while (file >> coin >> quantity)
        {
            AvailableCoin availableCoin = {coin, quantity};
            CashPool.push_back(availableCoin); // add new element to the end of the vector
        }
        file.close(); // close the file

    }
    void readData()
    {
        ifstream file("data.txt"); // open the file for reading

        if (!file.is_open())
        {
            cout << "Error: Unable to open file." << endl;
            exit(1);
        };

        vector<Item> items; // create a vector to store the items
        string name, note;
        int quantity;
        float price;

        while (file >> name >> quantity >> price >> note)
        {
            if (note == "needs-more-products")
                quantity += 10;
            Item item = {name, quantity, price};
            items.push_back(item); // add new element to the end of the vector
        }

        file.close(); // close the file

        Products = items;
    }
    void updateData()
    {
        fstream file;
        file.open("data.txt", ios::in | ios::out | ios::trunc);
        if (file.good() == true)
        {
            cout << "External menu updated...." << endl;
            for (int j = 0; j < 5; j++)
        {
            
            if (Products[j].quantity != 0)
            {

                file << Products[j].name << " " << Products[j].quantity << " " << Products[j].price << " --" << endl;
            }
            else
            {

                file << Products[j].name << " " << Products[j].quantity << " " << Products[j].price << " needs-more-products" << endl;
            }
        }

        }

        
        
    }
    void coinswriting()
    {
        fstream pool2;

        pool2.open("pool.txt", ios::out);
        if (pool2.good() == true)
        {

            for (int i = 0; i < 6; i++)
            {
                pool2 << CashPool[i].coin << " " << CashPool[i].quantity << endl;
            }
        }

        else
            cout << "File access forbidden " << endl;
        pool2.close();
    }
    int howMany(int userChoice, vector<Item> items)
    {
        int quantity;
        cout << "Please enter the quantity of the product you picked: ";
        cin >> quantity;
        while (quantity > items[userChoice].quantity)
        {
            cout << " Not Enough Product :'(\nAvailable quantity for the selected product is:  " << items[userChoice].quantity << "\n Please enter a valid quantity:" << endl;
            cin >> quantity;
        };
        return quantity;
    }
    bool isValidCoin(double input, vector<AvailableCoin> CashPool)
    {
        bool valid = false;
        float valid_coin[6] = {5, 2, 1, 0.5, 0.2, 0.1};
        for (int i = 0; i < 6; i++)
        {
            if (input == valid_coin[i])
            {
                valid = true;
            }
        }
        return valid;
    }
    void setEnteredAmount(float *EnteredAmount)
    {
        float input;
        cin >> input;
        *EnteredAmount = input;
    }
    int start()
    {
        UserChoice = 0;
        while (UserChoice != 1001)
        {
            if (UserChoice != 1001)
            {
                cout << "Please select product: " << endl;
                cin >> UserChoice;
                UserChoice = UserChoice - 1;

                if (UserChoice <= 4 && UserChoice >= 0)
                {

                    cout << "You have picked " << Products[UserChoice].name << " Available quantity is: " << Products[UserChoice].quantity << endl;
                    QuantityChoiced = howMany(UserChoice, Products);
                    float totalMoney = Products[UserChoice].price * QuantityChoiced;
                    Products[UserChoice].quantity = Products[UserChoice].quantity - QuantityChoiced;
                    cout << "Price is: " << totalMoney << endl;
                    cout << "Please enter " << totalMoney << endl;
                    EnteredAmount = 0;
                    while (true)
                    {

                        while (!isValidCoin(EnteredAmount, CashPool))
                        {
                            cout << "enter correct coin ";
                            setEnteredAmount(&EnteredAmount);
                        }
                        if (EnteredAmount == 5)
                        {
                            QuantityOfEnteredCoins[0] += 1;
                        }
                        else if (EnteredAmount == 2)
                        {
                            QuantityOfEnteredCoins[1] += 1;
                        }
                        else if (EnteredAmount == 1)
                        {
                            QuantityOfEnteredCoins[2] += 1;
                        }
                        else if (EnteredAmount == 0.5)
                        {
                            QuantityOfEnteredCoins[3] += 1;
                        }
                        else if (EnteredAmount == 0.2)
                        {
                            QuantityOfEnteredCoins[4] += 1;
                        }
                        else if (EnteredAmount == 0.1)
                        {
                            QuantityOfEnteredCoins[5] += 1;
                        }

                        // check if the amount is fully paid
                        if (totalMoney == EnteredAmount)
                        {
                            cout << "Purchase succeded  " << endl;
                            for (int i = 0; i < 6; i++)
                            {
                                CashPool[i].quantity += QuantityOfEnteredCoins[i];
                            }

                            coinswriting();
                            break;
                        }
                        else if (EnteredAmount > totalMoney)
                        {
                            // if more then return the excess
                            // put the change here ...

                            double difference = EnteredAmount - totalMoney;

                            while (difference > 0)
                            {
                                if (difference >= 5 && CashPool[0].quantity > 0)
                                {
                                    CashPool[0].quantity -= 1; // Which coin gets -1 from the quantity.
                                    difference -= 5;           // To calculate the change.
                                    cout << "5 PLN dropped\n";
                                }
                                else if (difference >= 2 && CashPool[1].quantity > 0)
                                {
                                    CashPool[1].quantity -= 1;
                                    difference -= 2;
                                    cout << "2 PLN dropped\n";
                                }
                                else if (difference >= 1 && CashPool[2].quantity > 0)
                                {
                                    CashPool[2].quantity -= 1;
                                    difference -= 1;
                                    cout << "1 PLN dropped\n";
                                }
                                else if (difference >= 0.5 && CashPool[3].quantity > 0)
                                {
                                    CashPool[3].quantity -= 1;
                                    difference -= 0.5;
                                    cout << "0.5 PLN dropped\n";
                                }
                                else if (difference >= 0.2 && CashPool[4].quantity > 0)
                                {
                                    CashPool[4].quantity -= 1;
                                    difference -= 0.2;
                                    cout << "0.2 PLN dropped\n";
                                }
                                else if (difference >= 0.1 && CashPool[5].quantity > 0)
                                {
                                    CashPool[5].quantity -= 1;
                                    difference -= 0.1;
                                    cout << "0.1 PLN dropped\n";
                                }
                                else
                                {
                                    cout << "Unable to give a change, deduct the payment in cash" << endl;
                                    return 0;
                                }
                            }
                            for (int i = 0; i < 6; i++)
                            {
                                CashPool[i].quantity += QuantityOfEnteredCoins[i];
                            }

                            coinswriting();
                            break;
                        }
                        else
                        {
                            cout << "You need to enter more" << endl;
                            double remaining = totalMoney - EnteredAmount;
                            cout << "Please enter remaining coins " << remaining << " PLN" << endl;
                            cin >> EnteredAmount;
                            totalMoney = remaining;
                        }
                        coinswriting();
                    }
                }

                else
                {

                    cout << "\nPlease enter a valid Choice." << endl;
                }

                printItems();
            }
            // 1002 to exit;
            else
            {
                cout << "Vending Machine Out Of Service :((((" << endl; // Whyy it doesnt WORK :(((((((
                exit(1);
            }

            updateData();
        }
        return 0;
    }
};

int main()
{
    VendingMachine vendingMachine;
    vendingMachine.printItems();
    vendingMachine.start();
    return 0;
};
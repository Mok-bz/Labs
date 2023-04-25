#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Item
{
    string name;
    int quantity;
    float price;
};

const int numberOfProducts = 5;
const float productsPrice[numberOfProducts] = {6.00, 6.30, 3.00, 5.00, 4.38};
int stock[numberOfProducts] = {10, 12, 12, 15, 20};
const string productsName[numberOfProducts] = {"Cola", "Pepsi", "Water", "Chips", "Mars"};

vector<Item> readData()
{
    ifstream file("data.txt"); // open the file for reading

    if (!file.is_open())
    {
        cout << "Error: Unable to open file." << endl;
        exit;
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

    return (items);
}

void printItems(vector<Item> items)
{

    for (int i = 0; i < 5; i++)
    {
        cout << "Code: " << i + 1 << ", Name: " << items[i].name << ", \tQuantity: " << items[i].quantity << ", \tPrice: " << items[i].price << " Zlt" << endl;
    }
}

void updateData(vector<Item> menuNew)
{
    fstream file;
    file.open("data.txt", ios::in | ios::out | ios::trunc);
    if (file.good() == true)
    {
        cout << "External menu updated...." << endl;
    }

    for (int i = 0; i < numberOfProducts; i++)
    {
        string productsNameList;
        if (menuNew[i].quantity != 0)
        {

            file << menuNew[i].name << " " << menuNew[i].quantity << " " << menuNew[i].price << " --" << endl;
        }
        else
        {
            file << menuNew[i].name << " " << menuNew[i].quantity << " " << menuNew[i].price << " needs-more-products" << endl;
        }
    }
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

int main()
{

    vector<Item> menuNew = readData();
    printItems(menuNew);

    int userChoice;
    int quantity;
    string itemName;

    while (userChoice != 1001)
    {
        if (userChoice != 1001)
        {
            cout << "Please select product: " << endl;
            cin >> userChoice;
            userChoice = userChoice - 1;

            if (userChoice <= 4 && userChoice >= 0)
            {
                cout << "You have picked " << menuNew[userChoice].name << " Available quantity is: " << menuNew[userChoice].quantity << endl;
                quantity = howMany(userChoice, menuNew);
                menuNew[userChoice].quantity = menuNew[userChoice].quantity - quantity;
            }
            else
            {

                cout << "\nPlease enter a valid Choice." << endl;
            }

            printItems(menuNew);
        }
        // 1002 to exit;
        else
        {
            cout << "Vending Machine Out Of Service :((((" << endl;
            exit(1);
        }

        updateData(menuNew);
    }
}

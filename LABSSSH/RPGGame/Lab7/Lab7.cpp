#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>


using namespace std;

class Character
{
private:
    string name;
    int strength;
    int dexterity;
    int endurance;
    int intelligence;
    int charisma;

public:
    Character(string nam, int str, int dext, int endu, int intel, int chari)
    {
    name = nam;
    strength = str;
    dexterity = dext;
    endurance = endu;
    intelligence = intel;
    charisma = chari;
    }

    void display ()
    {
        cout << "Character: " << name << endl;
        cout << "Strength: " << strength << endl;
        cout << "Dexterity: " << dexterity << endl;
        cout << "Endurance: " << endurance << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Charisma: " << charisma << endl;
    }

    void exportCharacter()
    {
        string fileName = name + ".txt";
        ofstream toFile(fileName);
        toFile << name << endl;
        toFile << strength << endl;
        toFile << dexterity << endl;
        toFile << endurance << endl;
        toFile << intelligence << endl;
        toFile << charisma << endl;
        toFile.close();
        cout << "New Character suceffuly created\n" << "File name: "<< fileName << endl;

    }

};

void makeNewCHaracter ()
{
    string name;
    int strength, dexterity, endurance, intelligence, charisma;
    cout << " Character Name: " << endl;
    cin >> name;
    cout << " Character strength: " << endl;
    cin >> strength;
    cout << " Character dexterity: " << endl;
    cin >> dexterity;
    cout << " Character endurance: " << endl;
    cin >> endurance;
    cout << " Character intelligence: " << endl;
    cin >> intelligence;
    cout << " Character charisma: " << endl;
    cin >> charisma;

    
    cin.ignore(); // ignore the newline character left in the buffer by cin
    Character New(name, strength, dexterity, endurance, intelligence, charisma);
    New.display();
    New.exportCharacter();

}

void loadCharacter()
{
    string fileName;
    cout << "Enter the Character ( FileName.txt )..\n" << "Character: " << endl;
    getline(cin, fileName);
    ifstream inFile(fileName) ;
    if (!inFile.is_open()) {
        cout << "Error: unable to open file " << fileName << endl;
        return;
    }
    string name;
    int strength, dexterity, endurance, intelligence, charisma;
    getline(inFile, name);

    inFile >> strength;
    inFile >> dexterity;
    inFile >> endurance;
    inFile >> intelligence;
    inFile >> charisma;
    inFile.close();
    Character New(name, strength, dexterity, endurance, intelligence, charisma);
    New.display();



}



int main()
{
    int userChoice;
    while (userChoice != 3 )
    {
        if (userChoice != 3 ){
        cout << "Menu:" << endl;
        cout << "1. Create new character" << endl;
        cout << "2. Load character" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;
        cin.ignore(); // ignore the newline character left in the buffer by cin
        switch (userChoice) {
        case 1:
            makeNewCHaracter();
            break;
        case 2:
            loadCharacter();
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
        }
        else 
        {
            exit(0);
        }
    }
    





    return 0;
}
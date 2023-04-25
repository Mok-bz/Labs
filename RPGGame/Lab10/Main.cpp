#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "HeroManagging.hpp"
#include "MonsterManagging.hpp"
#include "Templates.hpp"

using namespace std;

void chooseProffessionOfHero(Character &hero)
{
    int choice;
    cout << "choose : 1 for Mage | 2 for Berserker | 3 for Warrior | 4 for thief \n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        Mage mage;
        mage.increaseIntelligence(hero);
        break;
    case 2:
        Berserker berserker;
        berserker.increaseStrength(hero);
        break;
    case 3:
        Warrior warrior;
        warrior.increaseEndurance(hero);
        break;
    case 4:
        Thief thief;
        thief.increaseDexterity(hero);
        break;
    default:
        break;
    }
}
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
    chooseProffessionOfHero(New);
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

void createMonsters()
{
    vector<Monster> Monsters;
    string Mname,Mcollection;

    for (int i=0; i< 5; i++)
    {
        cout << "Enter monster name";
        cin >> Mname;
        Monster monster(Mname);
        Monsters.push_back(monster);
    }
    cout << "Enter the name of Monsters collection" ;
    cin >> Mcollection ;
    string fileName = Mcollection+".txt";
    ofstream toFile(fileName);
    for (int i=0; i<Monsters.size();i++)
    {
        toFile << Monsters[i].getMonsterInfo()<< endl;
    }
    toFile.close();
    cout << "New List of Monsters succefully created\n" << "File name: "<< fileName << endl;

};

int main()
{
    srand((unsigned) time(0));
    int userChoice;
    while (userChoice != 4 )
    {
        if (userChoice != 4 ){
        cout << "Menu:" << endl;
        cout << "1. Create new character" << endl;
        cout << "2. Load character" << endl;
        cout << "3. Create list of Monsters" << endl;
        cout << "4. Exit" << endl;
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
            createMonsters();
            break;
        case 4:
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
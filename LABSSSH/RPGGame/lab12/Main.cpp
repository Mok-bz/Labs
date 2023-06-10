#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "HeroManagging.hpp"
#include "MonsterManagging.hpp"
#include "Templates.hpp"

using namespace std;

void chooseProffessionOfHero(Character& hero)
{
    int choice;
    cout << "Choose: 1 for Mage | 2 for Berserker | 3 for Warrior | 4 for Thief\n";
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

void makeNewCharacter()
{
    string name;
    int strength, dexterity, endurance, intelligence, charisma;
    cout << "Character Name: ";
    cin >> name;
    cout << "Character strength: ";
    cin >> strength;
    cout << "Character dexterity: ";
    cin >> dexterity;
    cout << "Character endurance: ";
    cin >> endurance;
    cout << "Character intelligence: ";
    cin >> intelligence;
    cout << "Character charisma: ";
    cin >> charisma;

    cin.ignore(); // Ignore the newline character left in the buffer by cin
    Character New(name, strength, dexterity, endurance, intelligence, charisma);
    New.display();
    chooseProffessionOfHero(New);
    New.exportCharacter();
}

Character loadCharacter()
{
    string fileName;
    cout << "Enter the Character (FileName.txt): ";
    getline(cin, fileName);
    ifstream inFile(fileName.c_str());
    if (!inFile.is_open())
    {
        cout << "Error: unable to open file " << fileName << endl;
        //return;
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
    return New;
}

void createMonsters()
{
    vector<Monster> Monsters;
    string Mname, Mcollection;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter monster name: ";
        cin >> Mname;
        Monster monster(Mname);
        Monsters.push_back(monster);
    }
    cout << "Enter the name of Monsters collection: ";
    cin >> Mcollection;
    string fileName = Mcollection + ".txt";
    ofstream toFile(fileName.c_str());
    if (!toFile.is_open())
    {
        cout << "Error: unable to create file " << fileName << endl;
        return;
    }
    for (int i = 0; i < static_cast<int>(Monsters.size()); i++)
    {
        toFile << Monsters[i].getMonsterInfo() << endl;
    }
    toFile.close();
    cout << "New List of Monsters successfully created.\nFile name: " << fileName << endl;
}

int stringToInt(const std::string& str) {
    std::stringstream ss(str);
    int value;
    ss >> value;
    return value;
}

vector<Monster> LoadMonsters()
{

    std::ifstream file("mons.txt"); // Assuming the input file is named "input.txt"
    std::vector<std::vector<std::string> > data;

    if (file.is_open()) {
        std::string line;

        // Read each line from the file
        while (std::getline(file, line)) {
            std::vector<std::string> row;
            std::stringstream line_ss(line);
            std::string token;

            // Split the line into tokens
            while (line_ss >> token) {
                row.push_back(token);
            }

            // Add the row to the data vector
            data.push_back(row);
        }

        file.close();

        // Display the separated information
        for (int i = 0; i < data.size(); ++i) {
            for (int j = 0; j < data[i].size(); ++j) {
                std::cout << data[i][j] << " ";

            }
            std::cout << std::endl;
        }
        vector<Monster> monsters;
        for (int i = 0; i < 5; i++)
        {


         Monster monster1( data[i][0], stringToInt(data[i][1]), stringToInt(data[i][2]), stringToInt(data[i][3]), stringToInt(data[i][4]), stringToInt(data[i][5]),stringToInt(data[i][6]),stringToInt(data[i][7]));
         monsters.push_back(monster1);
        }
        return monsters;
       
        
    } else {
        std::cout << "Failed to open the file." << std::endl;
    }
    
}


void battle(Character MyCharacter){

    Monster monster;
    vector<Monster> monsters ;
    monsters = LoadMonsters();
//::loadinggg
    monster = monsters[1];
    if (monster.gethealth() > MyCharacter.gethealth()){
        cout << "Monster Won" << endl;
    }
    else{
        cout << "Hero won" << endl;
    }
}

int main()
{
    Character MyCharacter;
    srand(static_cast<unsigned>(time(0)));
    int userChoice = 0;
    while (userChoice != 4)
    {
        cout << "Menu:" << endl;
        cout << "1. Create new character" << endl;
        cout << "2. Load character" << endl;
        cout << "3. Create list of Monsters" << endl;
        cout << "4. Battle simulation" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: "<< endl;
        cin >> userChoice;
        cin.ignore(); // Ignore the newline character left in the buffer by cin
        switch (userChoice)
        {
        case 1:
            makeNewCharacter();
            break;
        case 2:
            MyCharacter = loadCharacter();
            break;
        case 3:
            createMonsters();
            break;
        case 4:
            battle(MyCharacter);
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

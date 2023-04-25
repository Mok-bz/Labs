#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "HeroManagging.hpp"

using namespace std;

Character::Character(string nam, int str, int dext, int endu, int intel, int chari)
{
    name = nam;
    strength = str;
    dexterity = dext;
    endurance = endu;
    intelligence = intel;
    charisma = chari;
};
void Character::exportCharacter()
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
};
void Character::display()
{
        cout << "Character: " << name << endl;
        cout << "Strength: " << strength << endl;
        cout << "Dexterity: " << dexterity << endl;
        cout << "Endurance: " << endurance << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Charisma: " << charisma << endl;
}
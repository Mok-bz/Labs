#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "MonsterManagging.hpp"

using namespace std;

Monster::Monster(string name)
{
    this->name = name;
    strength = 1 + (rand() % 10);
    dexterity = 1 + (rand() % 10);
    endurance = 1 + (rand() % 10);
    intelligence = 1 + (rand() % 10);
    charisma = 1 + (rand() % 10);

    cout << name << " " << strength << " " << dexterity << " " << endurance << " " << intelligence << " " << charisma << endl;
}

Monster::Monster()
{
}

Monster::~Monster()
{
}

string Monster::getMonsterInfo()
{
    return (name + " " + to_string(strength) + " " + to_string(dexterity) + " " + to_string(endurance) + " " + to_string(intelligence) + " " + to_string(charisma));
}

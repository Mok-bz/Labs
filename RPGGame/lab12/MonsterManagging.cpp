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
    health = strength + dexterity + endurance + intelligence + charisma ;
    exp = 1;
    cout << name << " " << strength << " " << dexterity << " " << endurance << " " << intelligence << " " << charisma  << " " << health << endl;
}

Monster::Monster(string nam, int str, int dext, int endu, int intel, int chari, int health, int exp )
{
  this->name = nam;
    strength = str;
    dexterity = dext;
    endurance = endu;
    intelligence = intel;
    charisma = chari;
    health = strength + dexterity + endurance + intelligence + charisma ;
    exp = 1;
}

Monster::Monster()
{
}

Monster::~Monster()
{
}

string Monster::getMonsterInfo()
{
    return (name + " " + to_string(strength) + " " + to_string(dexterity) + " " + to_string(endurance) + " " + to_string(intelligence) + " " + to_string(charisma) + " " + to_string(health)+ " " + to_string(health)+ " " + to_string(exp) );
}

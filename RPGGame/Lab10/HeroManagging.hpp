#ifndef HeroManagging_hpp
#define HeroManagging_hpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> 
using namespace std;

class Character
{
protected:
    string name;
    int strength;
    int dexterity;
    int endurance;
    int intelligence;
    int charisma;

public:
    Character(string nam, int str, int dext, int endu, int intel, int chari);
    Character(); // added necessary default constructor
    ~Character(); // added necessary default destructor
    void  exportCharacter();
    void  display();
    friend class Warrior;
    friend class Mage;
    friend class Thief;
    friend class Berserker;
};

class Mage
{

public:
    void increaseIntelligence(Character &hero)
    {
        hero.intelligence+=50;
        cout<<"**Intelligence increased by 50**"<<endl;
    }
};
class Warrior
{
public:
        void increaseEndurance(Character &hero)
    {
        hero.endurance+=50;
        cout<<"**Endurance increased by 50**"<<endl;
    }

};
class Berserker
{
public:
        void increaseStrength(Character &hero)
    {
        hero.strength+=50;
        cout<<"**Strength increased by 50**"<<endl;
    }

};
class Thief
{
public:
        void increaseDexterity(Character &hero)
    {
        hero.dexterity+=50;
        cout<<"**Dexterity increased by 50**"<<endl;
    }

};
#endif
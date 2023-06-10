#ifndef HeroManagging_hpp
#define HeroManagging_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Character {
public:
    string name;
    int strength;
    int dexterity;
    int endurance;
    int intelligence;
    int charisma;
    int health;

public:
    Character(string nam, int str, int dext, int endu, int intel, int chari);
    Character(); // Added default constructor
    ~Character(); // Added default destructor
    void exportCharacter();
    void display();
    int gethealth(); // Changed function name to follow naming convention
    friend class Warrior;
    friend class Mage;
    friend class Thief;
    friend class Berserker;
};

class Mage {
public:
    void increaseIntelligence(Character& hero);
};

class Warrior {
public:
    void increaseEndurance(Character& hero);
};

class Berserker {
public:
    void increaseStrength(Character& hero);
};

class Thief {
public:
    void increaseDexterity(Character& hero);
};

#endif

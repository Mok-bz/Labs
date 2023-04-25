#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "MonsterManagging.hpp"


Monster:: Monster(string name)
    {
    name=1 + (rand() % 10);
    strength=1 + (rand() % 10);
     dexterity=1 + (rand() % 10);
     endurance=1 + (rand() % 10);
     intelligence=1 + (rand() % 10);
     charisma=1 + (rand() % 10);

        cout << name << " " << strength << " " << dexterity << " " << endurance << " " << intelligence << " " << charisma<<endl;
    };
void Monster:: getMonsterInfo()
    {
        return (name+" "+to_string(strength)+" "+to_string(dexterity)+" "+to_string(endurance)+" "+to_string(intelligence)+" "+to_string(charisma));
    }
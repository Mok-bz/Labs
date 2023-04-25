#ifndef MonsterManagging_hpp
#define MonsterManagging_hpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "HeroManagging.hpp"

class Monster : Character 
{
public:

    Monster(string name);
    string  getMonsterInfo();
};
#endif
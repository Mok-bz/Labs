#ifndef MonsterManagging_hpp
#define MonsterManagging_hpp
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <cstdlib> 
#include "HeroManagging.hpp"
// #include "HeroManagging.cpp"

class Monster : Character 
{
public:

    Monster(string name);
    string  getMonsterInfo();
    Monster(); // added necessary default constructor
    ~Monster(); // added necessary default destructor

};
#endif


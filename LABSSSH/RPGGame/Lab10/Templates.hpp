/* #ifndef Templates_hpp
#define Templates_hpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "HeroManagging.hpp"
#include "MonsterManagging.hpp"

using namespace std;


class Templatess
{
public:
    void virtual chooseProffessionOfHero(Character &hero)=0;
    void virtual makeNewCHaracter ()=0;
    void virtual loadCharacter()=0;
    void virtual createMonsters()=0;
};
#endif */
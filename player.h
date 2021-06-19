#ifndef Player_H
#define Player_H

#include "game.h"
#include <sstream>
using namespace std;

class player :
    public game
{
public:
    void play();
};

#endif

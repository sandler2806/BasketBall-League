#pragma once
#include "Team.hpp"
class Game
{
    Team* in;
    Team* out;
public:
    Game(Team* in,Team* out);
    int inPoints, outPoints;
};



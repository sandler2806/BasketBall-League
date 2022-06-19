#pragma once
#include "Game.hpp"

class Schedule
{
    Team ** pTeam;
    int numbers[20];
    void cycle();
    void  game();
    void  reorder();
public:
    Schedule(Team ** pTeam);
    void gamesPeriod();

};

#pragma once
#include <vector>
#include "Game.hpp"
#include "Schedule.hpp"

class League{
    Team* pTeam[20];
    Schedule * schedule;
public:
    League();
    void gamesSession();
    void printTable();
    void statusTable();
    void bestTeams(int size);
    void bestWinStreak();
    void worstLoseStreak();
    void moreScoresThanDefeat();
};





#include <iostream>
#pragma once
using namespace std;
class Team
{
    int winStreak=0,loseStreak=0,positivePoints=0,negativePoints=0;
public:
    int bestWinStreak=0;
    int worseLoseStreak=0;
    string name;
    double skill;
    Team(double skill, string name);
    int wins=0, loses=0;
    int totalPoints();
    void win(int positivePoint, int negativePoint);
    void lose(int positivePoint, int negativePoint);
    double winsProb();
};
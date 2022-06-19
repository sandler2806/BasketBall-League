#include "Team.hpp"
void Team::lose(int positivePoint, int negativePoint){
    positivePoints += positivePoint;
    negativePoints += negativePoint;
    winStreak = 0;
    loseStreak++;
    loses++;
    if(loseStreak>worseLoseStreak){
        worseLoseStreak=loseStreak;
    }
}

Team::Team(double skill, string name):skill(skill), name(name){}
int Team::totalPoints(){return positivePoints - negativePoints;}
double Team::winsProb(){return static_cast<double>(wins) / 39;}

void Team::win(int positivePoint, int negativePoint){
    positivePoints += positivePoint;
    negativePoints += negativePoint;
    loseStreak = 0;
    winStreak++;
    wins++;
    if(winStreak>bestWinStreak){
        bestWinStreak=winStreak;
    }
}



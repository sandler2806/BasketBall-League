#include "Game.hpp"
#include <random>
Game::Game(Team *in,Team * out):in(in),out(out), inPoints(55), outPoints(50){

    random_device randomDevice;
    mt19937 generator{randomDevice()};
    normal_distribution<> basicPoints(23,10 );
    normal_distribution<> bonusPoints(4, 5);

    int scoreBasicIn=0;
    int scoreBonusIn=0;
    int scoreBasicOut=0;
    int scoreBonusOut=0;

    while (scoreBasicIn<=0||scoreBasicIn>45){
        scoreBasicIn = basicPoints(generator);
    }
    while (scoreBasicOut<=0||scoreBasicOut>50){
        scoreBasicOut = basicPoints(generator);
    }
    while (scoreBonusIn<=0||scoreBonusIn>10){
        scoreBonusIn = bonusPoints(generator);
    }
    while (scoreBonusOut<=0||scoreBonusOut>10){
        scoreBonusOut = bonusPoints(generator);
    }
    inPoints+=scoreBasicIn+scoreBasicIn*in->skill;
    outPoints += scoreBasicOut+ scoreBonusOut* out->skill;

    if(inPoints < outPoints){
        in->lose(inPoints, outPoints);
        out->win(outPoints, inPoints);
    }
    else{
        in->win(inPoints, outPoints);
        out->lose(outPoints, inPoints);
    }
}
#include "doctest.h"
#include "sources/League.hpp"
#include <string>
using namespace std;


TEST_CASE("valid input"){
    Team team {0.4, "1"};
    Team team2 {0.3, "2"};
    Game game {&team, &team2};

    if(game.inPoints>game.outPoints){
        CHECK(team.wins==1);
        CHECK(team.loses==0);
        CHECK(team.worseLoseStreak==0);
        CHECK(team.bestWinStreak==1);
        CHECK(team.totalPoints()>=0);

        CHECK(team2.wins==0);
        CHECK(team2.loses==1);
        CHECK(team2.worseLoseStreak==1);
        CHECK(team2.bestWinStreak==0);
        CHECK(team2.totalPoints()<=0);
    }
    else{
        CHECK(team2.wins==1);
        CHECK(team2.loses==0);
        CHECK(team2.worseLoseStreak==0);
        CHECK(team2.bestWinStreak==1);
        CHECK(team2.totalPoints()>=0);

        CHECK(team.wins==0);
        CHECK(team.loses==1);
        CHECK(team.worseLoseStreak==1);
        CHECK(team.bestWinStreak==0);
        CHECK(team.totalPoints()<=0);
    }

}

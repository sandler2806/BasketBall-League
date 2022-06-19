#include "League.hpp"
#include<algorithm>
vector<string> teamsNames {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"};

League::League(){
    for(unsigned int i =0; i <20; i++){
        pTeam[i] = new Team(static_cast<double >(rand() %10)/10 , teamsNames.at(i));
    }
    schedule = new Schedule(pTeam);
}
void League::gamesSession(){
    schedule->gamesPeriod();
    sort(pTeam, pTeam + 20, [](Team * team, Team *team2){
        if(team->winsProb()==team2->winsProb())
            return team->totalPoints()>team2->totalPoints();
        return team->winsProb()>team2->winsProb();
    });
}
void League::printTable() {
    statusTable();
    bestTeams(8);
    bestWinStreak();
    worstLoseStreak();
    moreScoresThanDefeat();
}
void League::statusTable(){
    cout<<"table status"<<endl;
    for(Team* team: pTeam){
        cout<<team->name<<",number of wins:"<<team->wins<<",number of loses:"<<team->loses<<",win prob:"<<team->winsProb()
        <<","<<"total points:"<<team->totalPoints()<<endl;
    }
}
void League::moreScoresThanDefeat() {
    int teamsNum = 0;
    for (Team *team: pTeam) {
        if (team->totalPoints() > 0) {
            teamsNum++;
        }
    }
    cout << teamsNum << " teams have more scores than defeat" << endl;
}

void League::worstLoseStreak(){
    int worst=0;
    for(Team* team: pTeam) {
        if(team->worseLoseStreak>worst){
            worst=team->worseLoseStreak;
        }
    }
}
void League::bestWinStreak(){
    int best=0;
    for(Team* team: pTeam) {
        if(team->bestWinStreak>best){
            best=team->bestWinStreak;
        }
    }
    cout<<"the best win streak is: "<<best<<endl;
}

void League::bestTeams(int size=10){
    if(size>20){
        throw invalid_argument("too many teams");
    }
    cout<<"the best "<<size<<" teams are:"<<endl;
    for(int i = 0 ; i < size; i++){
        cout<<i+1<<") "<<pTeam[i]->name<<endl;
    }
}
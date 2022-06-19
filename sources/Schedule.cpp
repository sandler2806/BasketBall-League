#include "Schedule.hpp"
#include <list>
#include <numeric>
using namespace std;

Schedule::Schedule(Team ** pTeam):pTeam(pTeam){}
void Schedule::reorder() {
    for (int i = 1; i <20 ; ++i) {
        int first = numbers[0];
        numbers[i-1] = numbers[i];
        numbers[19]=first;
    }
}
void Schedule::gamesPeriod(){
    cycle();
    cycle();
}

void Schedule::cycle(){
    iota(begin(numbers),end(numbers),0);
    for(int i=0; i < 19; i++){game();}
}

void Schedule::game(){
    for(int i = 0 ; i < 10; i++){Game(pTeam[numbers[i]],pTeam[numbers[19 - i]]);}
    reorder();
}


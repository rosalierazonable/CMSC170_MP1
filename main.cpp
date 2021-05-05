/*
 *  CMSC170: INTRODUCTION TO ARTIFICIAL INTELLIGENCE
 *  AI SEARCH PROBLEM - 8 PUZZLE
 *  USING A* ALGORITHM
 *  - Rosalie Razonable
 */

#include <iostream>
#include "State.h"
using namespace std;

bool isGoalState(State& s, State& goalState);

int main() {
    State goalState(3, {0, 1, 2, 3, 4, 5, 6, 7, 8});
    State s;
//    State s(3, {0, 1, 2, 3, 4, 5, 6, 7, 8});

    s.displayStateConfig();
    s.createBoard();
    cout << s.locateEmptyTile() << endl;
//    s.swapTiles(7).createBoard();
    cout << isGoalState(s, goalState);
    return 0;
}

bool isGoalState(State& s, State& goalState) {
    return goalState.getState() == s.getState();
}
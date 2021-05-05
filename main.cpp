/*
 *  CMSC170: INTRODUCTION TO ARTIFICIAL INTELLIGENCE
 *  AI SEARCH PROBLEM - 8 PUZZLE
 *  USING A* ALGORITHM
 *  - Rosalie Razonable
 */

#include <iostream>
#include "State.h"
using namespace std;

int main() {
    State s;
//    State s1(3, {0, 1, 2, 3, 5, 6, 4, 8, 7});


    s.displayStateConfig();
    s.createBoard();
    cout << s.locateEmptyTile() << endl;
    s.swapTiles(7).createBoard();
    return 0;
}

/*
 *  CMSC170: INTRODUCTION TO ARTIFICIAL INTELLIGENCE
 *  RAZONABLE, ROSALIE S.
 *
 *  AI SEARCH PROBLEM - 8 PUZZLE
 *  USING A* ALGORITHM
 *
 */

#include <iostream>
#include "Board.h"
#include "Neighbour.h"
#include "Node.h"

using namespace std;

bool isGoalState(State& s, State& goalState);

// Declaration of static attributes
map<unsigned int, vector<int>> Neighbour::neighbourMap = {};
map<unsigned int, vector<int>> Board::BoardIdxMap = {};

int main() {
    State goalState(3, {0, 1, 2, 3, 4, 5, 6, 7, 8}); //default goal state

    State s;

    s.createBoard();
    cout << endl;

    Node *r = new Node(s);
    r->setLevel(1);
    r->setChild(new Node(s.swapTiles(1)));
    r->getChild()->setLevel(1);
    r->setPathCostValue(goalState);
    cout << r->getPathCostValue();
    Node::printKthChild(r, s, 1);

    return 0;
}

// Auxiliary Methods
bool isGoalState(State& s, State& goalState) {
    return goalState.getState() == s.getState();
}

/* REFERENCES:
 *
 * https://www.geeksforgeeks.org/left-child-right-sibling-representation-tree/
 * https://www.geeksforgeeks.org/generic-treesn-array-trees/
 * https://www.geeksforgeeks.org/largest-element-in-an-n-ary-tree/
 * https://www.geeksforgeeks.org/creating-tree-left-child-right-sibling-representation/ (to be checked)
 * https://bytes.com/topic/c/answers/491099-undefined-reference-error-map
 */
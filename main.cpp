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
#include "Solver.h"
#include <bits/stdc++.h>

using namespace std;

bool isGoalState(State& s, State& goalState);

// Declaration of static attributes
map<unsigned int, vector<int>> Neighbour::neighbourMap = {};
map<unsigned int, vector<int>> Board::BoardIdxMap = {};

int main() {
    State goalState(3, {0, 1, 2, 3, 4, 5, 6, 7, 8}); //default goal state
    State s;

    Node *r = new Node(s);

//    Solver program(r);
//    program.solvePuzzle(r, goalState);

      Solver puzzle(r);
//      puzzle.solve(r,goalState);
        puzzle.solvePuzzle(r,goalState);
    return 0;
}

// Auxiliary Methods
bool isGoalState(State& s, State& goalState) {
    return goalState.getState() == s.getState();
}

/* REFERENCES:
 *
 * https://www.youtube.com/watch?v=D5aJNFWsWew&list=PLnrZOBR0x7yq6_p-DywsuH1R559NU2xLp&index=7 (Harvard CS50)
 * https://www.geeksforgeeks.org/left-child-right-sibling-representation-tree/
 * https://www.geeksforgeeks.org/generic-treesn-array-trees/
 * https://www.geeksforgeeks.org/largest-element-in-an-n-ary-tree/
 * https://www.geeksforgeeks.org/creating-tree-left-child-right-sibling-representation/ (to be checked)
 * https://bytes.com/topic/c/answers/491099-undefined-reference-error-map
 * https://www.youtube.com/watch?v=oAye4hI_sis
 * https://www.tutorialkart.com/cpp/cpp-vector-remove-first-element/
 */
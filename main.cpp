/*
 *  CMSC170: INTRODUCTION TO ARTIFICIAL INTELLIGENCE
 *  RAZONABLE, ROSALIE S.
 *
 *  AI SEARCH PROBLEM - 8 PUZZLE
 *  USING A* ALGORITHM
 *
 */

#include <iostream>
#include "State.h"
#include "Neighbour.h"
#include "Board.h"
#include "Node.h"

using namespace std;

bool isGoalState(State& s, State& goalState);
map<unsigned int, vector<int>> Neighbour::neighbourMap = {};
map<unsigned int, vector<int>> Board::BoardIdxMap = {};

int main() {
//    Neighbour neighbour;
    State goalState(3, {0, 1, 2, 3, 4, 5, 6, 7, 8}); //default goal state

    State s;

    s.createBoard();
    cout << endl;
    Node *root = new Node(s);
    root->level = 0;
    root->child = new Node(s.swapTiles(1));
  /*  cout << "Hamming: " << root->calculateHammingCost(goalState) << endl;
    cout  << "Manhattan: " << root->calculateManhattanCost(goalState) << endl;
    root->setPathCostValue(goalState);
    cout << "PathCost: " << root->getPathCostValue() << endl;
*/
    root->child->level = 1;
    Node::printKthChild(root, s, 1);
    root->child->sibling = new Node(s.swapTiles(3));
    root->child->sibling->level = 1;
    Node::printKthChild(root, s, 2);
    root->child->sibling->sibling = new Node(s.swapTiles(5));
    root->child->sibling->sibling->level = 1;
    Node::printKthChild(root, s, 3);
    root->child->sibling->sibling->sibling = new Node(s.swapTiles(7));
    root->child->sibling->sibling->sibling->level = 1;
    Node::printKthChild(root, s, 4);

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
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
#include "Node.h"

using namespace std;

bool isGoalState(State& s, State& goalState);

int main() {
    Neighbour neighbour;
    State goalState(3, {0, 1, 2, 3, 4, 5, 6, 7, 8}); //default goal state

    State s;
//    State s1(3, {0, 1, 2, 3, 4, 5, 6, 7, 8});

//    s.displayStateConfig();
//    s.createBoard();
//    cout << s.locateEmptyTile() << endl;
//    s.swapTiles(7).createBoard();
//    cout << isGoalState(s, goalState) << endl;

    Node *root = new Node(s);
    root->child = new Node(s.swapTiles(1));
    Node::printKthChild(root, s, 1);
    root->child->sibling = new Node(s.swapTiles(3));
    Node::printKthChild(root, s, 2);
    root->child->sibling->sibling = new Node(s.swapTiles(5));
    Node::printKthChild(root, s, 3);
    root->child->sibling->sibling->sibling = new Node(s.swapTiles(7));
    Node::printKthChild(root, s, 4);
    root->child->sibling->sibling->sibling->sibling = new Node(s.swapTiles(6));
    Node::printKthChild(root, s, 5);

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
 */
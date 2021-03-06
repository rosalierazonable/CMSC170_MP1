//
// Created by Rosalie Razonable on 5/11/2021.
//

#ifndef MP1_SOLVER_H
#define MP1_SOLVER_H

#include <vector>
#include <iostream>
#include <queue>
#include "Node.h"
#include "Neighbour.h"

class Solver {
    vector<Node*> openList; // list of Nodes with state that have already been generated
//    vector<Node*> closedList; // list of nodes that must be explored or expanded

    vector<vector<int>> frontier; // list of to be explored states
    vector<vector<int>> exploredList; // list of the states that have been explored already or expanded

public:
    explicit Solver(Node* initialNode) {
        this->openList.push_back(initialNode); // to be removed
        this->frontier.push_back(initialNode->getState().getState());
    }

   /*  static vector<Node*> actions(Node* n);  // given a certain node, returns the child nodes (new state after the valid actions are applied)
     void solvePuzzle(Node* initialNode, State& goalState);
     static vector<Node*> getMinPathCost(Node* currNode);
     vector<vector<int>> getOpenListStates();
     void expandNode(Node* currNode, Node* neighbour, State &goalState);
     bool hasBeenTraversed(Node* node);
    bool hasBeenExplored(Node* currNode);
     bool hasBeenExplored(const vector<int>& stateArr);
     bool hasBeenExpanded(Node* currNode);
     void removeFromOpenList(Node* currNode);*/

    static bool goalTest(Node *currNode, State &goalState);
    bool isInFrontier(const vector<int>& stateArr); // check whether the given state is in the frontier
    bool isInExplored(const vector<int>& stateArr); // check whether the given state has already been explored
    bool removeFromFrontier(Node *currNode); // remove the current node from the frontier
    queue<Node*> setMinNode(queue<Node*> toBeExplored, int size, int minPathCost);
    static Node* result(Node* node, int idx, int level, State goalState);
    static vector<int> action(Node* n);

    void solve(Node* initialNode, State& goalState);
    void displayPattern(int dimension);
};



#endif //MP1_SOLVER_H

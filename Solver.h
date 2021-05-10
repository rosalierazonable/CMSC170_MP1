//
// Created by Rosalie Razonable on 5/10/2021.
//

#ifndef MP1_SOLVER_H
#define MP1_SOLVER_H


#include <queue>
#include <iostream>
#include "Node.h"

//Overload the < operator.
bool operator< (const Node& node1, const Node& node2)
{
    return node1.heurestic > node2.heurestic;
}
//Overload the > operator.
bool operator> (const Node& node1, const Node& node2)
{
    return node1.heurestic < node2.heurestic;
}

class Solver {
    priority_queue<Node, vector<Node>, less<>> openList; //Ascending
    queue<Node> closedList;

public:
    Solver();
    Solver(const priority_queue<Node, vector<Node>, less<>>& openL, const queue<Node>& closedL){
        this->openList = openL;
        this->closedList = closedL;
    }
};


#endif //MP1_SOLVER_H

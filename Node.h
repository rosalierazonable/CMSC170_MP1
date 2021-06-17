//
// Created by Rosalie Razonable on 5/6/2021.
//

/*
 *
 * N-ary Tree Implementation
 * Using the Left Child - Right Sibling representation
 *
 */

#ifndef MP1_NODE_H
#define MP1_NODE_H

#include "State.h"
#include "Board.h"

class Node {
public:
    State state;
    Node *child; // left child
    Node *sibling; // right sibling
    unsigned int pathCost{}; // manhattan + hamming + level
    unsigned int level; // level from root

public:
    // Default Constructor
    Node() {
        State s;
        this->state = s;
        this->child = nullptr;
        this->sibling = nullptr;
        this->level = 0;
    };

    // Overloaded Constructor
    explicit Node(const State& s8) { // marked explicit to avoid unnecessary implicit conversions
        this->state = s8;
        this->child = nullptr;
        this->sibling = nullptr;
        this->level = 0;
    }

    // Copy Constructor
    Node(Node& n) {
        this->state = n.state;
        this->level = n.level;
        this->pathCost = n.pathCost;
        this->sibling = n.sibling;
        this->child = n.child;
    }

    // Helper Functions
    static void printKthChild(Node* root, State& state1, unsigned int k);
    unsigned int calculateManhattanCost(State goalState); // calculate manhattan cost by comparing the distances of the goal state and the current node
//    unsigned int calculateHammingCost(State goalState);

    // Mutator Methods
    void setPathCostValue(State goalState);
    void setSibling(Node *sib);
    void setChild(Node *c);
    void setLevel(unsigned int lvl);

    // Accessor Methods
    State getState(){
        return this->state;
    }
    unsigned int getPathCostValue() const;
    Node* getSibling() const;
    Node* getChild() const;
    unsigned int getLevel() const;

};


#endif //MP1_NODE_H



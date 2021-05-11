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

class Node {
public:
    State state;
    Node *child; // left child
    Node *sibling; // right sibling
    unsigned int heurestic{};
    unsigned int level;

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
        this->heurestic = n.heurestic;
        this->sibling = n.sibling;
        this->child = n.child;
    }

    // Helper Functions
    static void printKthChild(Node* root, State& state1, unsigned int k);
    State getState(){
        return this->state;
    }
};


#endif //MP1_NODE_H



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

public:
    Node() {
        State s;
        this->state = s;
    };

    // Overloaded Constructor
    explicit Node(State& state) { // marked explicit to avoid unnecessary implicit conversions
        this->state = state;
        this->child = nullptr;
        this->sibling = nullptr;
    }

    explicit Node(const State& s8) { // marked explicit to avoid unnecessary implicit conversions
        this->state = s8;
        this->child = nullptr;
        this->sibling = nullptr;
    }

    // Helper Functions
    static void printKthChild(Node* root, State& state1, unsigned int k) {

        if(root == nullptr)
            return;

        if(root->state.isEqual(state1)) {
            // Traverse children of root starting
            // from left child
            Node *n = root->child;
            int i = 1;
            while(n != nullptr && i < k) {
                n = n->sibling;
                i++;
            }

            if(n == nullptr)
                cout << "Node doesn't exist\n";
            else {
                n->state.createBoard();
                cout << endl;
            }
            return;
        }

        printKthChild(root->child, state1, k);
        printKthChild(root->sibling, state1, k);

        cout << "State does not exist" << endl;
    }
};


#endif //MP1_NODE_H

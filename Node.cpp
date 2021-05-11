//
// Created by Rosalie Razonable on 5/6/2021.
//

#include "Node.h"

void Node::printKthChild(Node *root, State &state1, unsigned int k) {

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


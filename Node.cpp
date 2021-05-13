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

unsigned int Node::calculateManhattanCost(State goalState) {
    int manhattanCost = 0;
    Board b;
    vector<vector<int>> curStateCoord, goalStateCoord;

    curStateCoord = Board::getBoardCoordinatesByValue(this->state);
    goalStateCoord = Board::getBoardCoordinatesByValue(goalState);

    unsigned int size = curStateCoord.size();

    for(unsigned int i = 0; i < size; i++) {
        manhattanCost += (abs(curStateCoord.at(i).at(0) - goalStateCoord.at(i).at(0)) +
                          abs(curStateCoord.at(i).at(1) - goalStateCoord.at(i).at(1)));
    }

    return manhattanCost;
}

unsigned int Node::calculateHammingCost(State goalState) {
    unsigned int hamming = 0;
    for(int i = 0; i < goalState.getState().size(); i++) {

        if(goalState.getState().at(i) == 0)
            continue;
        else if(this->state.getState().at(i) != goalState.getState().at(i))
            hamming++;
    }
    return hamming;
}

void Node::setPathCostValue(State goalState) {
    unsigned int manhattan, hamming;

    manhattan = this->calculateManhattanCost(goalState);
    hamming = this->calculateHammingCost(goalState);

    this->pathCost = manhattan + hamming + this->level;
}

unsigned int Node::getPathCostValue() const {
    return this->pathCost;
}

void Node::setSibling(Node *sib) {

}

void Node::getSibling() {

}

void Node::setChild(Node *c) {

}

void Node::getChild() {

}

void Node::setLevel(unsigned int lvl) {

}

void Node::getLevel() {

}



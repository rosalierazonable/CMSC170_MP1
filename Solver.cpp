//
// Created by Rosalie Razonable on 5/11/2021.
//

#include "Solver.h"
#include <algorithm>

using namespace std;

bool Solver::goalTest(Node *currNode, State &goalState) {
    return currNode->getState().getState() == goalState.getState();
}

bool Solver::removeFromFrontier(Node *currNode) {
    auto it = find(this->frontier.begin(), this->frontier.end(), currNode->getState().getState());

    if(it != this->frontier.end()) {
        this->frontier.erase(it);
        return true;
    }

    return false;
}

// returns resulting node after a move is made
Node *Solver::result(Node* node, int idx, int level, State goalState) {
    Node* newNode = new Node(node->getState().swapTiles(idx));
    newNode->setLevel(level);
    newNode->setPathCostValue(goalState);

    return newNode;
}

// get the neighbouring index of the blank tile for actions / moves
vector<int> Solver::action(Node* n) {
    Neighbour nb;
    vector<int> neighbours = nb.getNeighbours(n->getState().locateEmptyTile());

    return neighbours;
}

void Solver::solve(Node *initialNode, State& goalState) {
    bool stop = false;
    int level, idx;

    vector<int> moves, pathCosts; // vectors for moves / actions, and their path costs
    queue<Node*> toBeExplored; // vectors of to be explored nodes
    Node* currNode, *sibling; // temporary variable holder for current node / sibling

    initialNode->setPathCostValue(goalState); // calculate and set the path cost value of the initial state
    currNode = initialNode; // initialize with the initial configuration of the puzzle
    level = idx = 0;

    cout << "Initial Puzzle Configuration: " << endl << endl;
    currNode->getState().createBoard();

    while(!stop) {
        if(this->frontier.empty()) { // if the frontier is empty then there is no solution to the puzzle
            cout << "No Solution to the Puzzle Configuration" << endl;
            stop = true;
        } else {
            if(this->removeFromFrontier(currNode)) { // remove from frontier: currNode must be the node with the lowest path cost
                if(!this->goalTest(currNode, goalState)) { // if the currNode is the goal test
                    this->exploredList.push_back(currNode->getState().getState()); // add the node to be expanded to the explored list of nodes

                    moves = this->action(currNode); // moves contain the vector of indices to which the index of the blank tie must be switched upon

                    for(int move: moves) { // make each move
                        if(currNode->getChild() == nullptr) { // if the child is already set, that means the next node shall be set as a sibling
                            currNode->setChild(this->result(currNode, move, ++level, goalState));
                            currNode->getChild()->setPathCostValue(goalState);
                            sibling = currNode->getChild(); // set the child as the initial value of the sibling variable
                        } else {
                            // set the new node as the sibling of the current Node
                            sibling->setSibling(this->result(currNode, move, (int) currNode->getChild()->getLevel(), goalState));
                            sibling = sibling->getSibling();
                            sibling->setPathCostValue(goalState);
                        }

                        if(!isInFrontier(sibling->getState().getState()) && !isInExplored(sibling->getState().getState())) {
                            this->openList.push_back(sibling); // add in the list of nodes
                            this->frontier.push_back(sibling->getState().getState()); // add in the list of states
                            pathCosts.push_back((int) sibling->getPathCostValue()); // add in the list of path costs
                        }
                    }

                    if(toBeExplored.empty()) {
                        toBeExplored = this->setMinNode(toBeExplored,idx, *min_element(pathCosts.begin(), pathCosts.end()));
                        pathCosts.clear();

                        idx = (int) this->openList.size() - 1;
                    }

                    currNode = toBeExplored.front();
                    toBeExplored.pop();

                }  else {
                    cout << "Solution set: (All expanded or explored nodes)" << endl << endl;

                    this->exploredList.push_back(currNode->getState().getState());
                    this->displayPattern(this->openList.at(0)->getState().getDimension());

                    cout << "Goal State: " << endl << endl;
                    goalState.createBoard();

                    cout << "==================================" << endl << endl;
                    cout << "The puzzle has been solved! " << endl;
                    cout << "Total Number of Explored/Expanded Nodes: " << this->exploredList.size() << endl;
                    stop = true;
                }
            }
        }
    }
}

bool Solver::isInFrontier(const vector<int>& stateArr) {
    for(const vector<int>& state: this->frontier) {
        if(stateArr == state)
            return true;
    }
    return false;
}

bool Solver::isInExplored(const vector<int> &stateArr) {
    for(const vector<int>& state: this->exploredList) {
        if(stateArr == state)
            return true;
    }
    return false;
}

queue<Node*> Solver::setMinNode(queue<Node*> toBeExplored, int idx, int minPathCost) {

    for(int i = idx+1; i < this->openList.size(); i++) {
        if(this->openList.at(i)->getPathCostValue() == minPathCost)
            toBeExplored.push(this->openList.at(i));
    }

    if(toBeExplored.empty())
        return queue<Node*>();
    else
        return toBeExplored;
}

void Solver::displayPattern(int dimension) {
    int idx = 0;

    for(vector<int> stateArr: this->exploredList) {

        if(idx == this->exploredList.size()-1)
            cout << "Final State: " << endl << endl;

        if(idx > 0) {
            for(unsigned int i = 1; i <= dimension; i++) {
                for(unsigned int j = (i*dimension) - (dimension-1); j <= (dimension*i); j++) {

                    if(stateArr.at(j-1) == 0) {
                        if(dimension> 3) {
                            cout << " | __";
                        } else
                            cout << " | _";
                    } else if(stateArr.at(j-1) >= 10) {
                        cout << " | " << stateArr.at(j - 1);
                    } else {
                        if( dimension > 3)
                            cout << " | 0" << stateArr.at(j - 1);
                        else
                            cout << " | " << stateArr.at(j - 1);
                    }
                }
                cout << " | " << endl;
            }
            cout << endl;
        }
        idx++;
    }
}





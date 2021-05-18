//
// Created by Rosalie Razonable on 5/11/2021.
//

#include "Solver.h"
#include <algorithm>

using namespace std;

vector<Node *> Solver::actions(Node* n) {
    Neighbour nb;
    vector<Node *> newNodes;

    vector<int> neighbours = nb.getNeighbours(n->getState().locateEmptyTile());
    newNodes.reserve(neighbours.size());

for(int neighbour: neighbours) {
        newNodes.push_back(new Node(n->getState().swapTiles(neighbour)));
    }

    return newNodes;
}

void Solver::solvePuzzle(Node *initialNode, State& goalState) {
    vector<Node*> neighbours, toBeExpanded;
    Node* currNode, *sibling = nullptr;
    unsigned int level = 0;

    currNode = initialNode;

    cout << currNode->getPathCostValue() << endl;

    bool stop = false;

//    while(!this->openList.empty()) {
    while(!stop) {
        this->removeFromOpenList(currNode);
        this->closedList.push_back(currNode);

        neighbours = actions(currNode); // holds the valid nodes

        currNode->getState().createBoard();
        cout << "=======================" << endl << endl;

        for(Node* neighbour : neighbours) { //for expanding node
            this->expandNode(currNode, neighbour, goalState);

            if(currNode->getChild() == nullptr) { // if no child
                level = currNode->getLevel();

                currNode->setChild(neighbour);
                currNode->getChild()->setLevel(++level);
                currNode->getChild()->setPathCostValue(goalState);

                if(!hasBeenTraversed(currNode->getChild())) {
                    this->openList.push_back(currNode->getChild());
                    cout << "Path Cost: " << currNode->getChild()->getPathCostValue() << endl;
                    currNode->getChild()->getState().createBoard();
                }
            } else {
                currNode->getChild()->setSibling(neighbour);
                currNode->getChild()->getSibling()->setLevel(level);
                currNode->getChild()->getSibling()->setPathCostValue(goalState);

                if (!this->hasBeenTraversed(currNode->getChild()->getSibling())) {
                    this->openList.push_back(currNode->getChild()->getSibling());
                    sibling = currNode->getChild()->getSibling();
                }

                if(sibling != nullptr) {
                    cout << "Path Cost: " << sibling->getPathCostValue() << endl;
                    sibling->getState().createBoard();
                }
            }

        }

        toBeExpanded = getMinPathCost(currNode); // returns the node with the minimum path_cost

            for(auto v: toBeExpanded) {
                v->getState().displayStateConfig();
                cout << endl;
            }

        // setting the next Node to be expanded
        if(!toBeExpanded.empty()) {
            if(!this->hasBeenTraversed(toBeExpanded.front())) {
                currNode = toBeExpanded.front();
                toBeExpanded.erase(toBeExpanded.begin());
            } else  {
                toBeExpanded.erase(toBeExpanded.begin());
                if(toBeExpanded.front() != nullptr)
                    currNode = toBeExpanded.front();
            }
            this->closedList.push_back(currNode);
        } else
//            toBeExpanded = getMinPathCost(currNode); // returns the node with the minimum path_cost

        if(goalTest(currNode, goalState)) {
            cout << "The puzzle is now solved!" << endl;
            return;
        }

       stop = true;
    }
    cout << "Initial State configuration of the puzzle is not solvable" << endl;
}

vector<Node*> Solver::getMinPathCost(Node* currNode) {
    vector<Node*> validNodes = actions(currNode);
    vector<Node*> nodeToBeExpanded;

    Node* minNode = validNodes.at(0);

    for(int i = 1; i < validNodes.size(); i++) {
        cout << minNode->getPathCostValue() << " vs " << validNodes.at(i)->getPathCostValue() << endl;
        if (minNode->getPathCostValue() == validNodes.at(i)->getPathCostValue()){
            if(nodeToBeExpanded.empty())
                nodeToBeExpanded.push_back(minNode);

            nodeToBeExpanded.push_back(validNodes.at(i));
        } else if(minNode->getPathCostValue() > validNodes.at(i)->getPathCostValue())
            minNode = validNodes.at(i);
    }

    if(nodeToBeExpanded.empty())
        nodeToBeExpanded.push_back(minNode);

    return nodeToBeExpanded;
//    if(currNode != nullptr) {
//
//    }
}

/*bool Solver::hasBeenExplored(Node *currNode) {
    auto it = find(this->openList.begin(), this->openList.end(), currNode);

    if(it != this->openList.end())
        return true;
    else
        return false;
}

bool Solver::hasBeenExpanded(Node *currNode) {
    auto it = find(this->closedList.begin(), this->closedList.end(), currNode);

    if(it != this->closedList.end())
        return true;
    else
        return false;
}

bool Solver::hasBeenExplored(const vector<int>& stateArr) {

    for(Node* n: this->openList) {
        if(n->getState().getState() == stateArr)
            return true;
    }
    return false;
}*/

void Solver::removeFromOpenList(Node *currNode) {
    auto it = find(this->openList.begin(), this->openList.end(), currNode);

    if(it != this->openList.end()) {
        this->openList.erase(it);
    }
}

bool Solver::hasBeenTraversed(Node* node) {

    for(const auto& stateArrays: this->getOpenListStates()) {
        if(node->getState().getState() == stateArrays) {
            return true;
        }
    }
    return false;
}

vector<vector<int>> Solver::getOpenListStates() {
    vector<vector<int>> states;
    for(Node* currNode: this->openList) {
        states.push_back(currNode->getState().getState());
    }
    return states;
}

void Solver::expandNode(Node *currNode, Node *neighbour, State &goalState) {
    Node* sibling = nullptr;
    unsigned int level = 0;

    if(currNode->getChild() == nullptr) {
        level = currNode->getLevel();

        currNode->setChild(neighbour);
        currNode->getChild()->setLevel(++level);
        currNode->getChild()->setPathCostValue(goalState);

        if(!hasBeenTraversed(currNode->getChild())) {
            this->openList.push_back(currNode->getChild());
            cout << "Path Cost: " << currNode->getChild()->getPathCostValue() << endl;
            currNode->getChild()->getState().createBoard();
        }
    } else {
        currNode->getChild()->setSibling(neighbour);
        currNode->getChild()->getSibling()->setLevel(level);
        currNode->getChild()->getSibling()->setPathCostValue(goalState);
        if (!this->hasBeenTraversed(currNode->getChild()->getSibling())) {
            this->openList.push_back(currNode->getChild()->getSibling());
            sibling = currNode->getChild()->getSibling();
        }

                if(sibling != nullptr) {
                    cout << "Path Cost: " << sibling->getPathCostValue() << endl;
                    sibling->getState().createBoard();
                }
    }
}


bool Solver::goalTest(Node *currNode, State &goalState) {
    return currNode->getState().getState() == goalState.getState();
}

//bool Solver::removeFromFrontier(Node *currNode) {
//    auto it = find(this->frontier.begin(), this->frontier.end(), currNode);
//
//    if(it != this->frontier.end()) {
//        this->frontier.erase(it);
//        return true;
//    }
//
//    return false;
//}
//
//Node *Solver::result(Node* node, int idx, int level, State goalState) {
//    Node* newNode = new Node(node->getState().swapTiles(idx));
//    newNode->setLevel(level);
//    newNode->setPathCostValue(goalState);
//
//    return newNode;
//}
//
//vector<int> Solver::action(Node* n) {
//    Neighbour nb;
//    vector<int> neighbours = nb.getNeighbours(n->getState().locateEmptyTile());
//
//    return neighbours;
//}
//
//void Solver::solve(Node *initialNode, State& goalState) {
//    bool stop = false;
//    vector<int> moves;
//    int level = 0;
//    Node* currNode, *sibling;
//
//    currNode = initialNode;
//
//    while(!stop) {
//        if(this->frontier.empty()) {
//            cout << "No Solution to the Puzzle Configuration" << endl;
//            stop = true;
//        } else {
//            if(this->removeFromFrontier(currNode)) {
//                if(!this->goalTest(currNode, goalState)) {
//                    this->exploredList.push_back(currNode->getState().getState());
//
//                    moves = this->action(currNode);
//
//                    for(int move: moves) {
//                        if(currNode->getChild() == nullptr) { // if the child is already set, that means the next node shall be set as a sibling
//                            currNode->setChild(this->result(currNode, move, ++level, goalState));
//                            sibling = currNode->getChild(); // set the child as the initial value of the sibling variable
//                        } else {
//                            // set the new node as the sibling of the current Node
//                            sibling->setSibling(this->result(currNode, move, (int) currNode->getChild()->getLevel(), goalState));
//                            sibling = sibling->getSibling();
//                        }
//
//                        sibling->getState().createBoard();
//
//                        if(!isInFrontier(sibling->getState().getState()) && !isInExplored(sibling->getState().getState()))
//                            this->exploredList.push_back(sibling->getState().getState());
//                    }
//                    stop = true;
//                }  else {
//                    cout << "The puzzle has been solved! " << endl;
//                    stop = true;
//                }
//            }
//        }
//    }
//}
//
//bool Solver::isInFrontier(const vector<int>& stateArr) {
//    for(const vector<int>& state: this->frontier) {
//        if(stateArr == state)
//            return true;
//    }
//    return false;
//}
//
//bool Solver::isInExplored(const vector<int> &stateArr) {
//    for(const vector<int>& state: this->exploredList) {
//        if(stateArr == state)
//            return true;
//    }
//    return false;
//}



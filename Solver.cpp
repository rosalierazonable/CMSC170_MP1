//
// Created by Rosalie Razonable on 5/11/2021.
//

#include "Solver.h"

vector<Node> Solver::actions(Node n) {
    vector<Node>& transitionModels{(new Node())};
    unsigned int emptyIdx = n.state.locateEmptyTile();
    vector<int> neighboursIdx = Neighbour::getNeighbours(emptyIdx);

    for(auto idx: neighboursIdx) {
        State s(n.state.swapTiles(idx));
        Node newNode(s);
        transitionModels.push_back(newNode);
    }
    return vector<Node>();
}

//
// Created by Rosalie Razonable on 5/6/2021.
//

#include "Neighbour.h"

//map<unsigned int, vector<int>> Neighbour::neighbourMap = {};

void Neighbour::buildMap() {
    neighbourMap.insert(make_pair(0, vector<int>{1,3}));
    neighbourMap.insert(make_pair(1, vector<int>{0,2,4}));
    neighbourMap.insert(make_pair(2, vector<int>{1,5}));
    neighbourMap.insert(make_pair(3, vector<int>{0,4,6}));
    neighbourMap.insert(make_pair(4, vector<int>{1,3,5,7}));
    neighbourMap.insert(make_pair(5, vector<int>{2,4,8}));
    neighbourMap.insert(make_pair(6, vector<int>{3,7}));
    neighbourMap.insert(make_pair(7, vector<int>{4,6,8}));
    neighbourMap.insert(make_pair(8, vector<int>{5,7}));
}

vector<int> Neighbour::getNeighbours(unsigned int idxEmpty) {
    Map::const_iterator itr(neighbourMap.find(idxEmpty));
    if(itr!=neighbourMap.end()) {
        return itr->second;
    }
    return vector<int>();
}

void Neighbour::displayNeighbours(unsigned int idx) {
    for(int neighbour: this->getNeighbours(idx))
        cout << neighbour << " ";
    cout <<  endl;
}


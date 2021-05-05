//
// Created by Rosalie Razonable on 5/6/2021.
//

#ifndef MP1_NEIGHBOUR_H
#define MP1_NEIGHBOUR_H

#include <iostream>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

class Neighbour {
    typedef map<unsigned int, vector<int>> Map;
    Map neighbourMap;

public:
    Neighbour() {
      buildMap();
    }

    void buildMap();
    vector<int> getNeighbours(unsigned int idxEmpty);
    void displayNeighbours(unsigned int idx);

};


#endif //MP1_NEIGHBOUR_H

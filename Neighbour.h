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
    static Map neighbourMap;

public:
    Neighbour() {
      Neighbour::buildMap();
    }

    static void buildMap();
    vector<int> getNeighbours(unsigned int idxEmpty);

};


#endif //MP1_NEIGHBOUR_H

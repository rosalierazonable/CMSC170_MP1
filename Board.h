//
// Created by Rosalie Razonable on 5/11/2021.
//

#ifndef MP1_BOARD_H
#define MP1_BOARD_H

#include <iostream>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

class Board {
    typedef map<unsigned int, vector<int>> Map; // state idx, coordinates
    static Map BoardIdxMap;

public:
    Board() {
        this->buildMap();
    }

    void buildMap();
    vector<int> getBoardCoordinates(unsigned int idx);
    void displayCoordinates(unsigned int idx);
};


#endif //MP1_BOARD_H

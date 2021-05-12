//
// Created by Rosalie Razonable on 5/11/2021.
//

#ifndef MP1_BOARD_H
#define MP1_BOARD_H

#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include "State.h"

using namespace std;

class Board {
    typedef map<unsigned int, vector<int>> Map; // state idx, coordinates
    static Map BoardIdxMap;

public:
    Board() {
        this->buildMap();
    }

    void buildMap();
    vector<int> getBoardCoordinatesByIdx(unsigned int idx); // get coordinate of the idx
    vector<vector<int>> getBoardCoordinatesByValue(State state); // returns the coordinate of the value passed
    map<unsigned int, vector<int>> getBoardCoordinatesByStateConfig(State state);
    void displayCoordinates(unsigned int idx);
    void displayConfigCoordinates(State state);
};



#endif //MP1_BOARD_H

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
        Board::buildMap();
    }

    static void buildMap();
    static vector<int> getBoardCoordinatesByIdx(unsigned int idx); // get coordinate of the idx
    static vector<vector<int>> getBoardCoordinatesByValue(State state); // returns the coordinate of the value passed
    static map<unsigned int, vector<int>> getBoardCoordinatesByStateConfig(State state);
    void displayCoordinates(unsigned int idx);
    static void displayConfigCoordinates(State state);
};



#endif //MP1_BOARD_H

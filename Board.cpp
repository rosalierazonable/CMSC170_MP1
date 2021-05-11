//
// Created by Rosalie Razonable on 5/11/2021.
//

#include "Board.h"

//map<unsigned int, vector<int>> Board::BoardIdxMap = {};

void Board::buildMap() {
    BoardIdxMap.insert(make_pair(0, vector<int>{0,0}));
    BoardIdxMap.insert(make_pair(1, vector<int>{0,1}));
    BoardIdxMap.insert(make_pair(2, vector<int>{0,2}));
    BoardIdxMap.insert(make_pair(3, vector<int>{1,0}));
    BoardIdxMap.insert(make_pair(4, vector<int>{1,1}));
    BoardIdxMap.insert(make_pair(5, vector<int>{1,2}));
    BoardIdxMap.insert(make_pair(6, vector<int>{2,0}));
    BoardIdxMap.insert(make_pair(7, vector<int>{2,1}));
    BoardIdxMap.insert(make_pair(8, vector<int>{2,2}));
}

vector<int> Board::getBoardCoordinates(unsigned int idx) {
    Map::const_iterator itr(BoardIdxMap.find(idx));
    if(itr!=BoardIdxMap.end()) {
        return itr->second;
    }
    return vector<int>();
}

void Board::displayCoordinates(unsigned int idx) {

    for(int i = 0; i < 2; i++) {

        if(i == 0)
            cout << "( ";

        cout << this->getBoardCoordinates(idx).at(i);

        if(i != 1)
            cout << ",";
        else
            cout << " )" << endl;
    }
}

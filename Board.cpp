//
// Created by Rosalie Razonable on 5/11/2021.
//

#include "Board.h"

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

vector<int> Board::getBoardCoordinatesByIdx(unsigned int idx) {
    Map::const_iterator itr(BoardIdxMap.find(idx));
    if(itr!=BoardIdxMap.end()) {
        return itr->second;
    }
    return vector<int>();
}

vector<vector<int>> Board::getBoardCoordinatesByValue(State state) {
    vector<vector<int>> coordinates;
    typedef map<unsigned int, vector<int>> BoardMap;
    BoardMap boardMap;

    boardMap = getBoardCoordinatesByStateConfig(state);

    for(int i = 1; i < 9; i++) {
        Map::const_iterator itr(boardMap.find(i));
        if(itr!=boardMap.end()) {
            coordinates.push_back(itr->second);
        }
    }
    return coordinates;
}

map<unsigned int, vector<int>> Board::getBoardCoordinatesByStateConfig(State state) {
    typedef map<unsigned int, vector<int>> BoardMap;
    BoardMap idxMap;

    for(int i = 0; i < state.getState().size(); i++) {
        if(state.getState().at(i) == 0) continue;

        idxMap.insert(make_pair(state.getState().at(i) ,getBoardCoordinatesByIdx(i)));
    }
    return idxMap;
}



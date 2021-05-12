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

    boardMap = this->getBoardCoordinatesByStateConfig(state);

    for(int i = 0; i < state.getState().size(); i++) {
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
        idxMap.insert(make_pair(state.getState().at(i) ,this->getBoardCoordinatesByIdx(i)));
    }
    return idxMap;
}

void Board::displayCoordinates(unsigned int idx) {

    for(int i = 0; i < 2; i++) {

        if(i == 0)
            cout << "( ";

        cout << this->getBoardCoordinatesByIdx(idx).at(i);

        if(i != 1)
            cout << ",";
        else
            cout << " )" << endl;
    }
}

void Board::displayConfigCoordinates(State state) {
    vector<vector<int>> idxMap;
    idxMap = this->getBoardCoordinatesByValue(state);

    int ctr, ctr1;
    ctr = 1;
    for(const auto& val: idxMap) {
        ctr1 = 1;
        cout << "( ";
       for(auto value: val) {
           cout << value;
           if(ctr1 == 1)
               cout << ",";
           ctr1++;
       }
       cout << " ) | ";
       if(ctr == 3) {
           cout << endl;
           ctr = 0;
       }
       ctr++;
    }
    cout << endl;
}



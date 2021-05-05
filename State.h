//
// Created by Rosalie Razonable on 5/6/2021.
//

#ifndef MP1_STATE_H
#define MP1_STATE_H

#include <vector>
#include <iostream>

using namespace std;

class State {
    unsigned int dimension; //State dimension (nxn)
    vector<int> state; //List of integers representing the state configuration

public:
    State() { //default constructor
        this->dimension = 3; // 3x3 dimension
        this->state.assign({7, 2, 4, 5, 0, 6, 8, 3, 1}); //default initial state of the puzzle
    }

    //overloaded constructor for instances where the size and the initial state are provided
    State (unsigned int dimension, const vector<int>& stateArray) {
        this->dimension = dimension;
        this->state = stateArray;
//        for (auto i: stateArray) {
//            this->state.push_back(i);
//        }
    }

    vector<int> getState();
    void displayStateConfig();
};


#endif //MP1_STATE_H

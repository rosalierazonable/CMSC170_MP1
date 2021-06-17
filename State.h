//
// Created by Rosalie Razonable on 5/6/2021.
//

#ifndef MP1_STATE_H
#define MP1_STATE_H

#include <vector>
#include <iostream>

using namespace std;

class State {
    unsigned int dimension{}; //State dimension (nxn)
    vector<int> state; //List of integers representing the state configuration

public:

    //default constructor
    State() {
        this->setDimension(3); // 3x3 dimension by default
        this->setState({7, 2, 4, 5, 0, 6, 8, 3, 1}); //default initial state configuration
    }

    //overloaded constructor for instances where the size and the initial state are provided
    State (unsigned int dimension, const vector<int>& stateArray) {
        this->setDimension(dimension);
        this->setState(stateArray);
    }

    //copy constructor
    State (State& otherState) {
        this->setState(otherState.state);
        this->setDimension(otherState.dimension);
    }

    // Accessor Methods
    vector<int> getState();
    int getDimension() const;

    // Mutator Methods
    void setDimension(unsigned int dmension);
    void setState(const vector<int>& s8);

    // Helper Methods
    void createBoard(); //create a board and display it
    unsigned int locateEmptyTile(); //find the empty tile [0]
    State swapTiles(int idxToSwap); //swaps empty location to the index provided and returns a state
    bool isEqual(State& state);
};


#endif //MP1_STATE_H

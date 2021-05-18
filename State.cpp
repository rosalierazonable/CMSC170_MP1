//
// Created by Rosalie Razonable on 5/6/2021.
//

#include "State.h"

vector<int> State::getState() {
    return this->state;
}

void State::displayStateConfig() {
    int c = 0;
    for (int s: this->getState()) {
        cout << "[ " << s << " ] ";
        c++;
        if(c == 3) {
            cout << endl;
            c = 0;
        }
    }
}

void State::setState(const vector<int>& s8) {
    this->state = s8;
}

void State::setDimension(unsigned int dmension) {
    this->dimension = dmension;
}

void State::createBoard() {
    for(unsigned int i = 1; i <= this->dimension; i++) {
        for(unsigned int j = (i*this->dimension) - (this->dimension-1); j <= (this->dimension*i); j++) {

            if(state.at(j-1) == 0) {
                if(this->dimension> 3) {
                    cout << " | __";
                } else
                    cout << " | _";
            } else if(state.at(j-1) >= 10) {
                cout << " | " << state.at(j - 1);
            } else {
                if( this->dimension > 3)
                    cout << " | 0" << state.at(j - 1);
                else
                    cout << " | " << state.at(j - 1);
            }
        }
        cout << " | " << endl;
    }
    cout << endl;
}

unsigned int State::locateEmptyTile() {
    for(int i = 0; i < this->getState().size() ; i++) {
        if(this->getState().at(i) == 0)
            return i;
    }

    return -1; //no empty tile, bizarre
}

State State::swapTiles(int idxToSwap) {
    unsigned int emptyIdx = this->locateEmptyTile();
    int newValue;

    vector<int> stateConfig;

    stateConfig = this->getState();

    newValue = stateConfig.at(idxToSwap);
    stateConfig.at(emptyIdx) = newValue;
    stateConfig.at(idxToSwap) = 0;

    State s(this->dimension, stateConfig);

    return s;
}

bool State::isEqual(State &s8) {
    if(this->getState() == s8.getState())
        return true;
    return false;
}


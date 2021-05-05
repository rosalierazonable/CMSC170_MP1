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

//wheel.h

#ifndef WHEEL_H
#define WHEEL_H

#include "direction.h"

#include <cassert>
#include <string>

static const int NUMCHARACTERSINALPHABET = 26;
static char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

class Wheel {
    std::string alphabet_permuation;
    int index;
    Wheel* leftNeighbor;
    Wheel* rightNeighbor;
    
    bool checkPermutation(std::string permutation);
    
    void nextChar(Direction direction, Wheel* originator);
    
    public:
    Wheel();
    Wheel(std::string alphabet_permutation);
    void setStartPosition(char start);
    void setNeighbors(Wheel* left, Wheel* right);

    char getCurrentChar();
    void goToChar(char toSearch);
    bool contains(char toSearch);
};

#endif

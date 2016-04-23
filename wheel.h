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
    char* currentChar;
    int index;
    Wheel* leftNeighbor;
    Wheel* rightNeighbor;
    
    void nextChar(Direction direction);
    
    public:
    bool checkPermutation(char permutation[]);
    
    Wheel();
    Wheel(char alphabet_permutation[]);
    void setStartPosition(char start);
    char getCurrentChar();
    void goToChar(char toSearch);
    bool contains(char toSearch);
};

#endif

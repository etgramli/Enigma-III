//wheel.h

#ifndef WHEEL_H
#define WHEEL_H

#include "direction.h"

#include <cassert>
#include <string>

static const int CHARACTERSINALPHABET = 26;

class Wheel {
    char alphabet_permuattion[CHARACTERSINALPHABET];
    char* currentChar;
    std::string id;
    int index;
    Wheel* leftNeighbor;
    Wheel* rightNeighbor;
    
    void nextChar(Direction& direction);
    
    public:
    Wheel(char alphabet_permutation[], Wheel* leftNeighbor, Wheel* rightNeighbor, std::string id);
    void setStartPosition(char start);
    char getCurrentChar();
    void goToChar(char toSearch);
    bool contains(char toSearch);
};

#endif

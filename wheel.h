//wheel.h

#ifndef WHEEL_H
#define WHEEL_H

#include "direction.h"

#include <cassert>
#include <string>

//{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
static char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

class Wheel {
    static const int NUMCHARACTERSINALPHABET = 26;

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

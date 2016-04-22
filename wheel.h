//wheel.h

#include "direction.h"

#include <assert.h>

static int CHARACTERSINALPHABET = 26;
class Wheel {
    char[CHARACTERSINALPHABET] alphabet_permuattion;
    char* currentChar;
    std::String id;
    int index;
    Wheel* leftNeighbor;
    Wheel* rightNeighbor;
    
    void nextChar(Direction& direction);
    
    public:
    Wheel(char[] alphabet_permutation, Wheel* leftNeighbor, Wheel* rightNeighbor, std::String id);
    void setStartPosition(char start);
    char getCurrentChar();
    void goToChar(char toSearch);
    bool contains(char toSearch);
};

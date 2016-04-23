//wheel.cpp

#include "wheel.h"

Wheel::Wheel() {
    alphabet_permuation = std::string(alphabet);
    leftNeighbor = NULL;
    rightNeighbor = NULL;
}

Wheel::Wheel(char alphabet_permutation[]) {
    // allocate memorey and copy values from parameter alphabet_permutation to local variable
    leftNeighbor = NULL;
    rightNeighbor = NULL;
}

char Wheel::getCurrentChar() {
    return alphabet_permuation[index];
}

void Wheel::goToChar(char toSearch) {
    assert(contains(toSearch));
    // Move this index clockwise until the character is found
    while (alphabet_permuation[index] != toSearch) {
        nextChar(Direction::CLOCKWISE);
        // Then move my neighbor by the opposite direction
        if (leftNeighbor != NULL) {
            leftNeighbor->nextChar(Direction::ANTICLOCKWISE);
        }
        if (rightNeighbor != NULL) {
            rightNeighbor->nextChar(Direction::ANTICLOCKWISE);
        }
    }
}

void Wheel::nextChar(Direction direction) {
    // First visit my next char
    if (direction == Direction::CLOCKWISE) {
        if (index < CHARACTERSINALPHABET - 1) {
            index++;
        } else {
            index = 0;
        }
    } else if (direction == Direction::ANTICLOCKWISE) {
        if (index > 0) {
            index--;
        } else {
            index = CHARACTERSINALPHABET - 1;
        }
    }
}

bool Wheel::contains(char toSearch) {
    bool contains = false;
    for (int i = 0; i < CHARACTERSINALPHABET; i++) {
        contains = alphabet_permuation[i] == toSearch;
        if (contains) {
            break;
        }
    }
    return contains;
}

void Wheel::setStartPosition(char start) {
    assert(contains(start));
    // Set the index without updating the neighbors
    while (alphabet_permuation[index] != start) {
        nextChar(Direction::CLOCKWISE);
    }
}

bool Wheel::checkPermutation(char permutation[]) {
    // IMPLEMENT THIS !
    return false;
}

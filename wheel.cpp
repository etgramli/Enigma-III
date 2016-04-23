//wheel.cpp

#include "wheel.h"

#include <list>

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
        if (index < NUMCHARACTERSINALPHABET - 1) {
            index++;
        } else {
            index = 0;
        }
    } else if (direction == Direction::ANTICLOCKWISE) {
        if (index > 0) {
            index--;
        } else {
            index = NUMCHARACTERSINALPHABET - 1;
        }
    }
}

bool Wheel::contains(char toSearch) {
    bool contains = false;
    for (int i = 0; i < NUMCHARACTERSINALPHABET; i++) {
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
    // Copy of the string
    std::string permut(permutation);

    // Permutation must have the exact size
    if (permut.length() != NUMCHARACTERSINALPHABET) {
        return false;
    } else {
        // This holds the remainig / unused character to make sure a letter is only used once
        std::list<char> charsLeft(alphabet, alphabet + NUMCHARACTERSINALPHABET);
        
        // Check all letters of the permutation
        for (int i = 0; i < NUMCHARACTERSINALPHABET; i++) {
            // Check if the letter is in the list of remaining letters
            for (char currentChar : charsLeft) {
                // If the letter was not used before remove it and proceed
                if (currentChar == permut[i]) {
                    charsLeft.remove(permut[i]);
                    break;
                // If end of list reached this means that the current character is used twice
                } else if (charsLeft.back() == currentChar) {
                    return false;
                }
            }
        }
    }
    return true;
}

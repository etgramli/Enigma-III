//wheel.cpp

#include "wheel.h"

#include <list>

Wheel::Wheel() {
    alphabet_permuation = std::string(alphabet);
    leftNeighbor = NULL;
    rightNeighbor = NULL;
    index = 0;
}

Wheel::Wheel(std::string alphabet_permutation) {
    if (!this->checkPermutation(alphabet_permutation)) {
        this->alphabet_permuation = std::string(alphabet, alphabet + NUMCHARACTERSINALPHABET);
        printf("\nPermutation is NOT correct!\n");
    } else {
        this->alphabet_permuation = std::string(alphabet_permutation);
    }
    leftNeighbor = NULL;
    rightNeighbor = NULL;
    index = 0;
}

void Wheel::setNeighbors(Wheel* left, Wheel* right) {
    this->leftNeighbor = left;
    this->rightNeighbor = right;
}

char Wheel::getCurrentChar() {
    return alphabet_permuation[index];
}

void Wheel::goToChar(char toSearch) {
    assert(contains(toSearch));
    // Move this index clockwise until the character is found
    while (alphabet_permuation[index] != toSearch) {
        nextChar(Direction::CLOCKWISE, this);
    }
}

void Wheel::nextChar(Direction direction, Wheel* originator) {
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
    
    // Move the other neighbors by the opposite direction
    Direction opposite = direction == Direction::ANTICLOCKWISE ?
                         Direction::CLOCKWISE : Direction::ANTICLOCKWISE;
    if (leftNeighbor != NULL) {
        if (leftNeighbor != originator) {
            leftNeighbor->nextChar(opposite, this);
        }
    }
    if (rightNeighbor != NULL) {
        if (rightNeighbor != originator) {
            rightNeighbor->nextChar(opposite, this);
        }
    }
}

bool Wheel::contains(char toSearch) {
    printf("\n%c\n", toSearch);
    bool contains = false;
    for (int i = 0; i < NUMCHARACTERSINALPHABET; i++) {
        contains = (alphabet_permuation[i] == toSearch);
        if (contains) {
            break;
        }
    }
    return contains;
}

void Wheel::setStartPosition(char start) {
    assert(contains(start));
    // Set the index without updating the neighbors
    for(int i = 0; i < NUMCHARACTERSINALPHABET; i++) {
        if (alphabet_permuation[i] == start) {
            index = i;
            return;
        }
    }
}

bool Wheel::checkPermutation(std::string permutation) {
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
                if (toupper(currentChar) == toupper(permut[i])) {
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

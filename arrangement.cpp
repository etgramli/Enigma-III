//arrangement.cpp

#include "arrangement.h"

#include "wheel.h"
#include <vector>

Arrangement::Arrangement(std::string permutation_one,
                         std::string permutation_two,
                         std::string permutation_three,
                         std::string startPositions) {
    this->wheels = std::vector<Wheel>(NUMWHEELS);
    this->permutations = {permutation_one, permutation_two, permutation_three};

    for (int i = 0; i < NUMWHEELS; i++) {
        wheels[i] = Wheel(permutations[i]);
        wheels[i].setStartPosition(startPositions[i]);
    }
    for (int i = 0; i < NUMWHEELS; i++) {
        wheels[i].setNeighbors(i > 0 ? &wheels[i - 1] : NULL,
                               i < NUMWHEELS - 1 ? &wheels[i + 1] : NULL);
    }
}

std::string Arrangement::encrypt(std::string plainText) {
    std::string cipher = std::string();

    for (unsigned int i = 0; i < plainText.length(); i++) {
        // Go to char (dispatch to gearwheel).
        wheels[i % 2].goToChar(plainText[i]);
        // Get char from 3d wheel
        cipher.push_back(wheels[2].getCurrentChar());
    }

    return cipher;
}

std::string Arrangement::decrypt(std::string cipher) {
    std::string plainText = std::string();

    for (unsigned int i = 0; i < cipher.length(); i++) {
        wheels[2].goToChar(cipher[i]);
        plainText.push_back(wheels[i % 2].getCurrentChar());
    }
    
    return plainText;
}

bool Arrangement::checkIfStartPositionsIsValid(std::string startPositions) {
    if (startPositions.empty() || startPositions.length() != 3) {
        return false;
    }
    // Must be three letters long
    char currentChar;
    for (int i = 0; i < 3; i++) {
        currentChar = startPositions[i];
        if ((currentChar >= 'a' && currentChar <= 'z') ||
            (currentChar >= 'A' && currentChar <= 'Z')) {
            continue;
        } else {
            return false;
        }
    }

    return true;
}

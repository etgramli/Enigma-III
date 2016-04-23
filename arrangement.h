//arrangement.h

#ifndef ARRANGEMENT_H
#define ARRANGEMENT_H


#include "wheel.h"

#include<vector>
#include<string>

class Arrangement {
    static const int NUMWHEELS = 3;

    std::vector<Wheel> wheels;
    std::vector<std::string> permutations;
    std::string startPositions;

    public:
    Arrangement(std::string permutation_one,
                std::string permutation_two,
                std::string permutation_three,
                std::string startPositions);
    std::string encrypt(std::string plainText);
    std::string decrypt(std::string cipher);
    
    static bool checkIfStartPositionsIsValid(std::string startPositions);
};


#endif

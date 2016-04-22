//main.cpp

#include "wheel.h"
#include "direction.h"
#include "gitversion.h"

#include <getopt.h>
#include <stdio.h>
#include <cstdlib>

void printHelp() {
    printf("This is made from commit: %s\n\n", gitversion);
    printf("\nThis Enigma-III consists of three \"gearwheels\", every with a\n");
    printf("(seperate) permutataion of the letters of the alphabet. - Just to\n");
    printf("make it clear: A permutataion in this case is a list of the\n");
    printf("characters of the alphabet (all 26) with a order, that may be\n");
    printf("different from the normal order. The program assumes that all\n");
    printf("letters are only once in the permutataion.\n");
    printf("You can set a start position of every gearwheel seperately. If you\n");
    printf("did not, the first letter is the start position.\n\n");

    printf("Encryption\n");
    printf("The message is encrypted letter by letter; the letters on even\n");
    printf("positions will be enrypted by the first gearwheel and the odd\n");
    printf("positions will be encrypted by the second one. The final encrypted\n");
    printf("letter can be read from the third gearwheel. If the currently\n");
    printf("encrypted letter is not on the start position of the active\n");
    printf("gearwheel, the gearwheel rotates to the letter to search. This\n");
    printf("causes the left and right neighbor gearwheels to rotate in the\n");
    printf("opposite direction, of course.\n\n");

    printf("Decryption\n");
    printf("An encrypted message has to be processed letter by letter, too. All\n");
    printf("encrypted lettershave to be the input of gearwheel three. The even\n");
    printf("position letters have to be read from the first gearwheel and the\n");
    printf("odd letters from the second gearwheel respectively.\n\n");
}

static int NUMWHEELS = 3;
static struct option long_options[] = {
    {"gear1", required_argument, NULL, 0},
    {"gear2", required_argument, NULL, 0},
    {"gear2", required_argument, NULL, 0},
    {NULL, 0, NULL, 0}
};

int main(int argc, char* argv[]) {
    char *startPositions = NULL;
    startPositions = (char *)malloc(sizeof(char) * 3);

    // parse options
    char c;
    int option_index = 0;
    while ((c = getopt_long(argc, argv, "hs:",
                            long_options, &option_index)) != -1) {
        switch (c) {
        case 'h':
            printHelp();
            break;
        case 's':
            c = 's';    // Replace
            break;
        default:
            printf("Argument not recognized!!!");
            break;
        }
    }
    
    
    // init
    
    // calculate
    
    // print result
    
}

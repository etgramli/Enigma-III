//main.cpp

#include "wheel.h"
#include "direction.h"
#include "gitversion.h"

#include <getopt.h>
#include <stdio.h>
#include <cstdlib>

void printHelp() {
    printf("\nThis is made from commit: %s\n\n", gitversion);
    
    printf("Options:\n");
    printf("\t-h\n");
    printf("\t\tHelp text with the git commit hash and this ecplanation of the command line options.\n");
    printf("\t-gear1 <alphabet permutation>\n");
    printf("\t-gear2 <alphabet permutation>\n");
    printf("\t-gear3 <alphabet permutation>\n");
    printf("\t\tPermutations of the alphabet for the first, second and third gearwheel. (i.e. \"ADCBEHFGILJKMPNOQTRSUXVWZY\")\n");
    printf("\t-s <start positions>\n");
    printf("\t\tStart positions of the three gearwheels. (i.e. \"SEC\")\n\n");

    printf("Introduction\n");
    printf("\tThis Enigma-III consists of three \"gearwheels\", every with a\n");
    printf("\t(seperate) permutataion of the letters of the alphabet. - Just to\n");
    printf("\tmake it clear: A permutataion in this case is a list of the\n");
    printf("\tcharacters of the alphabet (all 26) with a order, that may be\n");
    printf("\tdifferent from the normal order. The program assumes that all\n");
    printf("\tletters are only once in the permutataion.\n");
    printf("\tYou can set a start position of every gearwheel seperately. If you\n");
    printf("\tdid not, the first letter is the start position.\n\n");

    printf("Encryption\n");
    printf("\tThe message is encrypted letter by letter; the letters on even\n");
    printf("\tpositions will be enrypted by the first gearwheel and the odd\n");
    printf("\tpositions will be encrypted by the second one. The final encrypted\n");
    printf("\tletter can be read from the third gearwheel. If the currently\n");
    printf("\tencrypted letter is not on the start position of the active\n");
    printf("\tgearwheel, the gearwheel rotates to the letter to search. This\n");
    printf("\tcauses the left and right neighbor gearwheels to rotate in the\n");
    printf("\topposite direction, of course.\n\n");

    printf("Decryption\n");
    printf("\tAn encrypted message has to be processed letter by letter, too. All\n");
    printf("\tencrypted lettershave to be the input of gearwheel three. The even\n");
    printf("\tposition letters have to be read from the first gearwheel and the\n");
    printf("\todd letters from the second gearwheel respectively.\n\n");
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

//main.cpp

#include "gitversion.h"
#include "direction.h"
#include "wheel.h"
#include "arrangement.h"

#include <getopt.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

bool checkIfStartPositionsIsValid(std::string startPositions);

static int NUMWHEELS = 3;

void printHelp() {
    printf("\nThis is made from commit: %s\n\n", gitversion);
    
    printf("Options:\n");
    printf("\t-h\n");
    printf("\t\tHelp text with the git commit hash and this ecplanation of the\n");
    printf("\t\tcommand line options.\n");
    printf("\t-gear1 <alphabet permutation>\n");
    printf("\t-gear2 <alphabet permutation>\n");
    printf("\t-gear3 <alphabet permutation>\n");
    printf("\t\tPermutations of the alphabet for the first, second and third\n");
    printf("\t\tgearwheel.(i.e. \"ADCBEHFGILJKMPNOQTRSUXVWZY\")\n");
    printf("\t-s <start positions>\n");
    printf("\t\tStart positions of the three gearwheels. (i.e. \"SEC\")\n");
    printf("\t-m <message>\n");
    printf("\t\tThe message string in quotes.\n");
    printf("\t-d\n");
    printf("\t\tFlag: decryprion instead of encryption.\n\n");

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
    
    printf("This program is licensed under GPLv3 (see LICENSE).\n\n");
}

static struct option long_options[] = {
    {"gear1", required_argument, NULL, 'a'},
    {"gear2", required_argument, NULL, 'b'},
    {"gear3", required_argument, NULL, 'c'},
    {NULL, 0, NULL, 0}
};

int main(int argc, char* argv[]) {
    std::string startPositions;
    std::string message;
    std::vector<std::string> permutations(NUMWHEELS);


    // parse options
    char c;
    int option_index = 0;
    bool decryption = false;
    while ((c = getopt_long(argc, argv, "a:b:c:dhm:s:",
                            long_options, &option_index)) != -1) {
        switch (c) {
        case 'a':
            permutations[0] = std::string(optarg);
            break;
        case 'b':
            permutations[1] = std::string(optarg);
            break;
        case 'c':
            permutations[2] = std::string(optarg);
            break;
        case 'd':
            decryption = true;
            break;
        case 'h':
            printHelp();
            break;
        case 'm':
            message = std::string(optarg);
            break;
        case 's':
            startPositions = std::string(optarg);
            if (!Arrangement::checkIfStartPositionsIsValid(startPositions)) {
                printf("Start positions are NOT valid!\tMust be three characters (i.e. \"-sabc\").\n\n");
                exit(-1);
            }
            break;
        default:
            printf("Argument not recognized!!!\n");
            break;
        }
    }
    
    
    // init
    Arrangement arrangement = Arrangement(permutations[0],
                                          permutations[1],
                                          permutations[2],
                                          startPositions);
    
    printf("Input: \"%s\"\n", message.c_str());
    
    // calculate
    std::string target = decryption ? arrangement.decrypt(message) :
                                      arrangement.encrypt(message);

    printf("The result is:%s\n\n", target.c_str());

    return 0;
}

#include "util.h"
#include "bomb.h"

void menu();
char getCommand();
void exeCommand(char cmd, Bomb& bomb);

int main() {
    char cmd;
    cout << "Welcome to Bomb Diffusal Assistant v241" << endl;
    Bomb bomb;
    
    menu();
    cmd = getCommand();
    while (cmd != 'q') {
        exeCommand(cmd, bomb);
        menu();
        cmd = getCommand();
    }
    
    cout << "Thank you for using the Bomb Diffusal Assistant v241! :)" << endl
         << "Have a nice day." << endl;
    
    return 0;
}

void menu() {
    cout << "Select from the options below:" << endl << endl;
    
    cout << "(a) Redo the bomb setup" << endl
         << "(b) Defuse a Simple Wires module" << endl
         << "(c) Defuse a Button module" << endl
         << "(d) Defuse a Keypad module" << endl
         << "(e) Defuse a Simon Says module" << endl
         << "(f) Defuse a Who's On First module" << endl
         << "(g) Defuse a Memory module" << endl
         << "(h) Defuse a Morse Code module" << endl
         << "(i) Defuse a Complex Wires module" << endl
         << "(j) Defuse a Sequence of Wires module" << endl
         << "(k) Defuse a Maze module" << endl
         << "(l) Defuse a Password module" << endl
         << "(q) Quit the Bomb Diffusal Assistant" << endl
         << endl;
}

char getCommand() {
    cout << "Enter your choice (a-l): ";
    return tolower(getChar());
}

void exeCommand(char cmd, Bomb& bomb) {
    switch (cmd) {
        case 'a':
            cout << endl << "----------Bomb Setup----------" << endl << endl;
            bomb.setBomb();
            break;
        case 'b':
            cout << endl << "----------Simple Wires----------" << endl << endl;
            bomb.defuseWiresSimple();
            break;
        case 'c':
            cout << endl << "----------Button----------" << endl << endl;
            bomb.defuseButton();
            break;
        case 'd':
            cout << endl << "----------Keypad----------" << endl << endl;
            bomb.defuseKeypad();
            break;
        case 'e':
            cout << endl << "----------Simon Says----------" << endl << endl;
            bomb.defuseSimonSays();
            break;
        case 'f':
            cout << endl << "----------Who's On First----------" << endl << endl;
            bomb.defuseWhosOnFirst();
            break;
        case 'g':
            cout << endl << "----------Memory----------" << endl << endl;
            bomb.defuseMemory();
            break;
        case 'h':
            cout << endl << "----------Morse Code----------" << endl << endl;
            bomb.defuseMorseCode();
            break;
        case 'i':
            cout << endl << "----------Complex Wires----------" << endl << endl;
            bomb.defuseWiresComplex();
            break;
        case 'j':
            cout << endl << "----------Sequence Of Wires----------" << endl << endl;
            bomb.defuseWiresSequence();
            break;
        case 'k':
            cout << endl << "----------Maze----------" << endl << endl;
            bomb.defuseMaze();
            break;
        case 'l':
            cout << endl << "----------Password----------" << endl << endl;
            bomb.defusePassword();
            break;
        case 'q': //Program should never reach this case
            cout << endl << "----------Quit----------" << endl << endl;
            break;
        default:
            cout << "Error. Invalid command." << endl;
            break;
    }
}
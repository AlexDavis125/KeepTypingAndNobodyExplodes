#include "bomb.h"

Bomb::Bomb() {
    init();
}

Bomb::Bomb(const Bomb& other) {
    destroy();
    init();
    *this = other;
}

Bomb::~Bomb() {
    destroy();
}

void Bomb::init() {
    setBomb();
}

void Bomb::destroy() {
    return;
}

const Bomb& Bomb::operator=(const Bomb& other) {
    if (this == &other)
        return *this;
    
    indicatorFrq = other.indicatorFrq;
    indicatorCar = other.indicatorCar;
    serialVowel = other.serialVowel;
    serialEven = other.serialEven;
    portParallel = other.portParallel;
    batteries = other.batteries;
    return *this;
}

ostream& operator<<(ostream& out, const Bomb& bomb) {
    bomb.display();
    return out;
}

void Bomb::display() const {
    cout << "FRQ Indicator: ";
    if (indicatorFrq)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    cout << "CAR Indicator: ";
    if (indicatorCar)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    cout << "There is ";
    if (!serialVowel)
        cout << "not ";
    cout << "a vowel in the serial number" << endl;
    
    cout << "The last digit of the serial number is ";
    if (serialEven)
        cout << "even" << endl;
    else
        cout << "odd" << endl;
    
    cout << "The bomb does ";
    if (!portParallel)
        cout << "not ";
    cout << "have a parallel port." << endl;
    
    cout << "Batteries: " << batteries << endl << endl;
}

void Bomb::setBomb() {
    bool correct;
    
    do {
        cout << "Is there a lit indicator labeled FRQ? (y or n): ";
        indicatorFrq = getBool();
        cout << "Is there a lit indicator labeled CAR? (y or n): ";
        indicatorCar = getBool();
        cout << "Is there a vowel in the serial number? (y or n): ";
        serialVowel = getBool();
        cout << "Is the last digit of the serial number even? (y or n): ";
        serialEven = getBool();
        cout << "Is there a parallel port? (y or n): ";
        portParallel = getBool();
        cout << "How many batteries are there?: ";
        batteries = getInt();
        cout << endl;
        cout << "Confirm this info is accurate: " << endl << *this;
        cout << "Is this information accurate? (y or n): ";
        correct = getBool();
        cout << endl;
    } while (!correct);
}

void Bomb::defuseWiresSimple() const {
    //Read in wire colors in order
    char module[7];
    
    cout << "(r) Red" << endl
         << "(w) White" << endl
         << "(l) Blue" << endl
         << "(k) Black" << endl
         << "(y) Yellow" << endl
         << endl;
    cout << "Enter the wire colors from top to bottom: ";
    getString(module);
    lowerAll(module);
    
    //Read out instruction
    switch (strlen(module)) {
        case 3:
            if (countRed(module) == 0) {
                cout << "Cut the second wire." << endl << endl;
                break;
            }
            if (module[2] == 'w') {
                cout << "Cut the last wire." << endl << endl;
                break;
            }
            if (countBlue(module) > 1) {
                cout << "Cut the last blue wire." << endl << endl;
                break;
            }
            cout << "Cut the last wire." << endl << endl;
            break;
        case 4:
            if (countRed(module) > 1 && !serialEven) {
                cout << "Cut the last red wire." << endl << endl;
                break;
            }
            if (countRed(module) == 0 && module[3] == 'y') {
                cout << "Cut the first wire." << endl << endl;
                break;
            }
            if (countBlue(module) == 1) {
                cout << "Cut the first wire." << endl << endl;
                break;
            }
            if (countYellow(module) > 1) {
                cout << "Cut the last wire.";
                break;
            }
            cout << "Cut the second wire." << endl << endl;
            break;
        case 5:
            if (module[4] == 'k' && !serialEven) {
                cout << "Cut the fourth wire." << endl << endl;
                break;
            }
            if (countRed(module) == 1 && countYellow(module) > 1) {
                cout << "Cut the first wire." << endl << endl;
                break;
            }
            if (countBlack(module) == 0) {
                cout << "Cut the second wire." << endl << endl;
                break;
            }
            cout << "Cut the first wire." << endl << endl;
            break;
        case 6:
            if (countYellow(module) == 0 && !serialEven) {
                cout << "Cut the third wire." << endl << endl;
                break;
            }
            if (countYellow(module) == 1 && countWhite(module) > 1) {
                cout << "Cut the fourth wire." << endl << endl;
                break;
            }
            if (countRed(module) == 0) {
                cout << "Cut the last wire." << endl << endl;
                break;
            }
            cout << "Cut the fourth wire." << endl << endl;
            break;
        default:
            cout << "Incorrect input." << endl << endl;
            break;
    }
}
        
void Bomb::defuseButton() const {
    //Get word and color of button
    char color;
    char word;
    
    cout << "(b) Blue" << endl
         << "(w) White" << endl
         << "(y) Yellow" << endl
         << "(r) Red" << endl
         << endl;
    cout << "Enter the color of the button: ";
    color = getChar();
    
    cout << "(a) Abort" << endl
         << "(d) Detonate" << endl
         << "(h) Hold" << endl
         << endl;
    cout << "Enter the word on the button: ";
    word = getChar();
    
    //Evaluate and read out instruction
    if (color == 'b' && word == 'a') {
        holdInstructions();
        return;
    }
    if (batteries > 1 && word == 'd') {
        cout << "Press and immediately release the button." << endl << endl;
        return;
    }
    if (color == 'w' && indicatorCar) {
        holdInstructions();
        return;
    }
    if (batteries > 2 && indicatorFrq) {
        cout << "Press and immediately release the button." << endl << endl;
        return;
    }
    if (color == 'y') {
        holdInstructions();
        return;
    }
    if (color == 'r' && word == 'h') {
        cout << "Press and immediately release the button." << endl << endl;
        return;
    }
    holdInstructions();
}

void Bomb::defuseKeypad() const {
    cout << "Defusing keypad." << endl;
}

void Bomb::defuseSimonSays() const {
    //Currently assumes no strikes acquired while solving
    int strikes;
    char simon[7];
    char color = 'z';
    int i = 0;
    
    cout << "How many strikes do you have?: ";
    strikes = getInt();
    
    do {
        cout << "(r) Red" << endl
             << "(b) Blue" << endl
             << "(g) Green" << endl
             << "(y) Yellow" << endl
             << "(d) Done" << endl
             << endl;
        cout << "Enter the most recent color: ";
        color = getChar();
        
        switch (color) {
            case 'r':
                if (strikes == 0) {
                    simon[i] = 'b';
                }
                if (strikes == 1) {
                    if (serialVowel)
                        simon[i] = 'y';
                    else
                        simon[i] = 'r';
                }
                if (strikes == 2) {
                    if (serialVowel)
                        simon[i] = 'g';
                    else
                        simon[i] = 'y';
                }
                i++;
                cout << "Enter " << simon << endl;
                break;
            case 'b':
                if (strikes == 0) {
                    if (serialVowel)
                        simon[i] = 'r';
                    else
                        simon[i] = 'y';
                }
                if (strikes == 1) {
                    if (serialVowel)
                        simon[i] = 'g';
                    else
                        simon[i] = 'b';
                }
                if (strikes == 2) {
                    if (serialVowel)
                        simon[i] = 'r';
                    else
                        simon[i] = 'g';
                }
                i++;
                cout << "Enter " << simon << endl;
                break;
            case 'g':
                if (strikes == 0) {
                    if (serialVowel)
                        simon[i] = 'y';
                    else
                        simon[i] = 'g';
                }
                if (strikes == 1) {
                    if (serialVowel)
                        simon[i] = 'b';
                    else
                        simon[i] = 'y';
                }
                if (strikes == 2) {
                    if (serialVowel)
                        simon[i] = 'y';
                    else
                        simon[i] = 'b';
                }
                i++;
                cout << "Enter " << simon << endl;
                break;
            case 'y':
                if (strikes == 0) {
                    if (serialVowel)
                        simon[i] = 'g';
                    else
                        simon[i] = 'r';
                }
                if (strikes == 1) {
                    if (serialVowel)
                        simon[i] = 'r';
                    else
                        simon[i] = 'g';
                }
                if (strikes == 2) {
                    if (serialVowel)
                        simon[i] = 'b';
                    else
                        simon[i] = 'r';
                }
                i++;
                cout << "Enter " << simon << endl;
                break;
            case 'd':
                break;
            default:
                cout << "Invalid color." << endl;
                break;
        }
    } while (color != 'd');
}

void Bomb::defuseWhosOnFirst() const {
    cout << "Defusing who's on first." << endl;
}
void Bomb::defuseMemory() const {
    int pos[5];
    char val[5];
    char current[5];
    int counter;
    
    //Stage 1
    cout << "Enter the five digits in order: ";
    for (int i = 0; i < 5; i++) {
        current[i] = cin.get();
    }
    cin.ignore(MAX_CHAR, '\n');
    
    switch (current[0]) {
        case '1':
            cout << "Press label " << current[2] << endl;
            pos[0] = 2;
            val[0] = current[2];
            break;
        case '2':
            cout << "Press label " << current[2] << endl;
            pos[0] = 2;
            val[0] = current[2];
            break;
        case '3':
            cout << "Press label " << current[3] << endl;
            pos[0] = 3;
            val[0] = current[3];
            break;
        case '4':
            cout << "Press label " << current[4] << endl;
            pos[0] = 4;
            val[0] = current[4];
            break;
        default:
            cout << "Invalid entry." << endl << endl;
            return;
    }
    
    //Stage 2
    cout << "Enter the five digits in order: ";
    for (int i = 0; i < 5; i++) {
        current[i] = cin.get();
    }
    cin.ignore(MAX_CHAR, '\n');
    
    switch (current[0]) {
        case '1':
            cout << "Press label 4" << endl;
            counter = 1;
            while (current[counter] != '4')
                counter++;
            pos[1] = counter;
            val[1] = '4';
            break;
        case '2':
            cout << "Press label " << current[pos[0]] << endl;
            pos[1] = pos[0];
            val[1] = current[pos[0]];
            break;
        case '3':
            cout << "Press label " << current[1] << endl;
            pos[1] = 1;
            val[1] = current[1];
            break;
        case '4':
            cout << "Press label " << current[pos[0]] << endl;
            pos[1] = pos[0];
            val[1] = current[pos[0]];
            break;
        default:
            cout << "Invalid entry." << endl << endl;
            return;
    }
    
    //Stage 3
    cout << "Enter the five digits in order: ";
    for (int i = 0; i < 5; i++) {
        current[i] = cin.get();
    }
    cin.ignore(MAX_CHAR, '\n');
    
    switch (current[0]) {
        case '1':
            cout << "Press label " << val[1] << endl;
            counter = 1;
            while (current[counter] != val[1])
                counter++;
            pos[2] = counter;
            val[2] = val[1];
            break;
        case '2':
            cout << "Press label " << val[0] << endl;
            counter = 1;
            while (current[counter] != val[0])
                counter++;
            pos[2] = counter;
            val[2] = val[0];
            break;
        case '3':
            cout << "Press label " << current[3] << endl;
            pos[2] = 3;
            val[2] = current[3];
            break;
        case '4':
            cout << "Press label 4" << endl;
            counter = 1;
            while (current[counter] != '4')
                counter++;
            pos[2] = counter;
            val[2] = '4';
            break;
        default:
            cout << "Invalid entry." << endl << endl;
            return;
    }
    
    //Stage 4
    cout << "Enter the five digits in order: ";
    for (int i = 0; i < 5; i++) {
        current[i] = cin.get();
    }
    cin.ignore(MAX_CHAR, '\n');
    
    switch (current[0]) {
        case '1':
            cout << "Press label " << current[pos[0]] << endl;
            pos[3] = pos[0];
            val[3] = current[pos[0]];
            break;
        case '2':
            cout << "Press label " << current[1] << endl;
            pos[3] = 1;
            val[3] = current[1];
            break;
        case '3':
            cout << "Press label " << current[pos[1]] << endl;
            pos[3] = pos[1];
            val[3] = current[pos[1]];
            break;
        case '4':
            cout << "Press label " << current[pos[1]] << endl;
            pos[3] = pos[1];
            val[3] = current[pos[1]];
            break;
        default:
            cout << "Invalid entry." << endl << endl;
            return;
    }
    
    //Stage 5
    cout << "Enter the five digits in order: ";
    for (int i = 0; i < 5; i++) {
        current[i] = cin.get();
    }
    cin.ignore(MAX_CHAR, '\n');
    
    switch (current[0]) {
        case '1':
            cout << "Press label " << val[0] << endl;
            break;
        case '2':
            cout << "Press label " << val[1] << endl;
            break;
        case '3':
            cout << "Press label " << val[3] << endl;
            break;
        case '4':
            cout << "Press label " << val[2] << endl;
            break;
        default:
            cout << "Invalid entry." << endl << endl;
            return;
    }
    
}

void Bomb::defuseMorseCode() const {
    cout << "Defusing morse code." << endl;
}
void Bomb::defuseWiresComplex() const {
    cout << "Defusing complex wires." << endl;
}
void Bomb::defuseWiresSequence() const {
    cout << "Defusing sequence of wires." << endl;
}
void Bomb::defuseMaze() const {
    cout << "Defusing maze." << endl;
}
void Bomb::defusePassword() const {
    cout << "Defusing password." << endl;
}


//PRIVATE FUNCTIONS
void Bomb::lowerAll(char * str) const {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int Bomb::countRed(const char * str) const {
    int result = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'r')
            result++;
    }
    return result;
}

int Bomb::countBlue(const char * str) const {
    int result = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'l')
            result++;
    }
    return result;
}

int Bomb::countYellow(const char * str) const {
    int result = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'y')
            result++;
    }
    return result;
}

int Bomb::countBlack(const char * str) const {
    int result = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'k')
            result++;
    }
    return result;
}

int Bomb::countWhite(const char * str) const {
    int result = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'w')
            result++;
    }
    return result;
}

void Bomb::holdInstructions() const {
    char color;
    cout << "Hold the button down." << endl;
    cout << "(b) Blue" << endl
         << "(w) White" << endl
         << "(y) Yellow" << endl
         << "(o) Other" << endl
         << endl;
    cout << "What color is the strip?: ";
    color = getChar();
    
    switch (color) {
        case 'b':
            cout << "Release when the timer has a 4 in any position." << endl << endl;
            break;
        case 'w':
            cout << "Release when the timer has a 1 in any position." << endl << endl;
            break;
        case 'y':
            cout << "Release when the timer has a 5 in any position." << endl << endl;
            break;
        case 'o': //Irrelevant code
            cout << "Release when the timer has a 1 in any position." << endl << endl;
            break;
        default:
            cout << "Release when the timer has a 1 in any position." << endl << endl;
            break;
    }
}
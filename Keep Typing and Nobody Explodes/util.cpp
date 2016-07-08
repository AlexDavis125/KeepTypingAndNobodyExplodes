#include "util.h"

bool getBool() {
    char result;
    
    do {
        cin >> result;
        while (!cin) {
            cin.clear();
            cin.ignore(MAX_CHAR, '\n');
            cout << "Error. Enter 'y' or 'n': ";
            cin >> result;
        }
        cin.ignore(MAX_CHAR, '\n');
        result = tolower(result);
        if (result != 'y' && result != 'n')
            cout << "Error. Enter 'y' or 'n': ";
    } while (result != 'y' && result != 'n');

    if (result == 'y')
        return true;
    else
        return false;
}

int getInt() {
    int result;
    
    cin >> result;
    while (!cin) {
        cin.clear();
        cin.ignore(MAX_CHAR, '\n');
        cout << "Error. Enter a valid integer: ";
        cin >> result;
    }
    cin.ignore(MAX_CHAR, '\n');
    
    return result;
}

char getChar() {
    char result;
    
    cin >> result;
    while (!cin) {
        cin.clear();
        cin.ignore(MAX_CHAR, '\n');
        cout << "Error. Enter a valid character: ";
        cin >> result;
    }
    cin.ignore(MAX_CHAR, '\n');
    
    return tolower(result);
}

void getString(char * str) {
    cin.get(str, MAX_CHAR, '\n');
    while (!cin) {
        cin.clear();
        cin.ignore(MAX_CHAR, '\n');
        cout << "Error. Please re-enter: ";
        cin.get(str, MAX_CHAR, '\n');
    }
    cin.ignore(MAX_CHAR, '\n');
}
#ifndef BOMB_H
#define BOMB_H

#include "util.h"

class Bomb {
public:
    Bomb();
    Bomb(const Bomb& other);
    ~Bomb();
    void init();
    void destroy();
    
    const Bomb& operator=(const Bomb& other);
    friend ostream& operator<<(ostream& out, const Bomb& bomb);
    void display() const;
    
    void setBomb();
    void defuseWiresSimple() const;
    void defuseButton() const;
    void defuseKeypad() const;
    void defuseSimonSays() const;
    void defuseWhosOnFirst() const;
    void defuseMemory() const;
    void defuseMorseCode() const;
    void defuseWiresComplex() const;
    void defuseWiresSequence() const;
    void defuseMaze() const;
    void defusePassword() const;
    
private:
    void lowerAll(char * str) const;
    int countRed(const char * str) const;
    int countBlue(const char * str) const;
    int countYellow(const char * str) const;
    int countBlack(const char * str) const;
    int countWhite(const char * str) const;
    void holdInstructions() const;

    bool indicatorFrq;
    bool indicatorCar;
    bool serialVowel;
    bool serialEven;
    bool portParallel;
    int batteries;
};

#endif // BOMB_H
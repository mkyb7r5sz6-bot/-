#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
private:
    int number; 
    int suit;   

public:
    Player();
   
    void hit(int* deck, int* currentCardIndex);
    int getNumber() const;
    int getSuit() const;
    void showCard(const char* playerName) const; 
};

#endif
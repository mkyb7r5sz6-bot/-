#include "Player.h"


Player::Player()
{
    number = 0;
    suit = 0;
}


void Player::hit(int* deck, int* currentCardIndex) 
{
   
    int cardID = deck[*currentCardIndex];

    
    suit = cardID / 13;          
    number = (cardID % 13) + 1; 

    
    (*currentCardIndex)++;
}

int Player::getNumber() const 
{
    return number;
}

int Player::getSuit() const 
{
    return suit;
}


void Player::showCard(const char* playerName) const 
{
    const char* suitMarks[] = { "ハート", "ダイヤ", "スペード", "クローバー" };
    std::cout << playerName << " のカード: " << suitMarks[suit] << " の " << number << std::endl;
}
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player {
private:
    int number; // カードの数字 (1〜13)
    int suit;   // カードのスート (0:ハート, 1:ダイヤ, 2:スペード, 3:クローバー)

public:
    Player();
    // 山札の配列（ポインタ）と、次に引くカードのインデックス（ポインタ）を渡す
    void hit(int* deck, int* currentCardIndex);
    int getNumber() const;
    int getSuit() const;
    void showCard(const char* playerName) const; // 名前は表示時のみ外部から渡す
};

#endif
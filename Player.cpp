#include "Player.h"

// コンストラクタ
Player::Player() {
    number = 0;
    suit = 0;
}

// 山札からカードを1枚引く
void Player::hit(int* deck, int* currentCardIndex) {
    // 山札から通し番号（0〜51）を取得
    int cardID = deck[*currentCardIndex];

    // 通し番号をスートと数字に変換
    suit = cardID / 13;          // 0〜3
    number = (cardID % 13) + 1;  // 1〜13

    // 次のカードへインデックスを進める
    (*currentCardIndex)++;
}

int Player::getNumber() const {
    return number;
}

int Player::getSuit() const {
    return suit;
}

// カードの表示
void Player::showCard(const char* playerName) const {
    const char* suitMarks[] = { "ハート", "ダイヤ", "スペード", "クローバー" };
    std::cout << playerName << " のカード: " << suitMarks[suit] << " の " << number << std::endl;
}
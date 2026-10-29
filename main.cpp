#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"

using namespace std;


void resetDeck(int* deck, int* currentCardIndex) 
{
    
    for (int i = 0; i < 52; i++) 
    {
        deck[i] = i;
    }
    
    for (int i = 51; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    
    *currentCardIndex = 0;
    cout << "--- 山札がリセット（シャッフル）されました ---" << endl << endl;
}

int main() 
{
    srand(static_cast<unsigned int>(time(0)));

    int deck[52];             
    int currentCardIndex = 0; 
    
    resetDeck(deck, &currentCardIndex);

    cout << "=== ハイカードゲーム 開始 ===" << endl << endl;

    Player playerA;
    Player playerB;

    
    if (currentCardIndex >= 51)
    {
        resetDeck(deck, &currentCardIndex);
    }

    
    playerA.hit(deck, &currentCardIndex);
    playerB.hit(deck, &currentCardIndex);

    playerA.showCard("プレイヤーA");
    playerB.showCard("プレイヤーB");
    cout << endl;

    
    if (playerA.getNumber() > playerB.getNumber())
    {
        cout << "【結果】プレイヤーA の勝ち！" << endl;
    }
    else if (playerA.getNumber() < playerB.getNumber())
    {
        cout << "【結果】プレイヤーB の勝ち！" << endl;
    }
    else 
    {
        cout << "【結果】引き分け！" << endl;
    }

    cout << endl << "=== ゲーム終了 ===" << endl;
    return 0;
}
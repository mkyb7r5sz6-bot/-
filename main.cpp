#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"

using namespace std;

// 山札を初期化してシャッフルする関数
void resetDeck(int* deck, int* currentCardIndex) {
    // 0〜51の連番を入れる
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }
    // フィッシャー・イェーツのシャッフルアルゴリズム
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    // インデックスを先頭（0）に戻す
    *currentCardIndex = 0;
    cout << "--- 山札がリセット（シャッフル）されました ---" << endl << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int deck[52];             // 52枚のカード配列
    int currentCardIndex = 0; // 次に引くカードのインデックス

    // 最初の山札生成
    resetDeck(deck, &currentCardIndex);

    cout << "=== ハイカードゲーム 開始 ===" << endl << endl;

    Player playerA;
    Player playerB;

    // 残り枚数が足りない（今回は1ゲーム2枚消費）場合はリセット
    // ※もし52枚ぴったり引ききったタイミングを検知したい場合は 「== 52」で判定します
    if (currentCardIndex >= 51) {
        resetDeck(deck, &currentCardIndex);
    }

    // 配列とインデックスをポインタ渡し
    playerA.hit(deck, &currentCardIndex);
    playerB.hit(deck, &currentCardIndex);

    playerA.showCard("プレイヤーA");
    playerB.showCard("プレイヤーB");
    cout << endl;

    // 勝敗判定（今回はシンプルに数字のみで比較）
    if (playerA.getNumber() > playerB.getNumber()) {
        cout << "【結果】プレイヤーA の勝ち！" << endl;
    }
    else if (playerA.getNumber() < playerB.getNumber()) {
        cout << "【結果】プレイヤーB の勝ち！" << endl;
    }
    else {
        cout << "【結果】引き分け！" << endl;
    }

    cout << endl << "=== ゲーム終了 ===" << endl;
    return 0;
}
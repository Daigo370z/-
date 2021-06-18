#include <iostream>
#include <string>
#include <Windows.h>
#include "game.h"
#include "human.h"
#include "computer.h"
#include <sstream>
using namespace std;

void main_play() {
    int choice, replay;
    cout << "選擇模式\n 1.玩家1 vs. 玩家2 \n 2.Computer vs. Human(1 Player)\n 3.Exit\n\n";
    cin >> choice;
    if (choice < 4) {
        switch (choice) {
        case 1:
        {
            human two_player;
            two_player.play();
            break;
        }

        case 2:
        {
            computer one_player;
            one_player.play();
            break;
        }
        case 3:
        {
            SetColor(GREEN);
            cout << "謝謝遊玩 :)\n\n";
            SetColor(WHITE);
            return;
        }
        }

        SetColor(DARKTEAL);
        cout << "還想繼續玩嗎?\n 1.Yes \n 2.No \n";
        SetColor(WHITE);
        cin >> replay;
        if (replay == 1) {
            main_play();
        }
        else {
            SetColor(GREEN);
            cout << "謝謝遊玩 :)\n\n";
            SetColor(WHITE);
            return;
        }
    }
    SetColor(RED);
    cout << "請勿亂輸入\n 請選擇有效的格子\n\n";
    SetColor(WHITE);
    main_play();
}
int main() {

    SetColor(DARKGREEN);
    cout << "井字遊戲" << std::endl;
    cout << "預設 Player 1 為 'O' & Player 2 為 'X'\n";
    cout << "選擇的格子會在下列表格中列出\n\n\n";
    cout << " 1  | 2  | 3  \n||\n 4  | 5  | 6  \n||\n 7  | 8  | 9  \n    |    |    \n\n";
    cout << "**\n";
    SetColor(WHITE);

    main_play();
    return 0;
}



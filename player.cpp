#include "player.h"

using namespace std;

void player::play() {
    int i = 1, player_choice;
    char mark;
    string current_palyer;
    SetColor(DARKYELLOW);
    cout << "輸入玩家 1名字:\n";
    getline(cin, dummy);
    getline(cin, player1);
    cout << "輸入玩家 2名字:\n";
    getline(cin, player2);
    SetColor(WHITE);

    while (state_of_game() == KEEP_PLAYING) {
        if (i % 2 != 0) {
            current_palyer = player1;
            mark = 'O';
        }
        else if (i % 2 == 0) {
            current_palyer = player2;
            mark = 'X';
        }
        cout << current_palyer << ":輸入你的位置....\n";
        cin >> player_choice;

        if (is_the_move_valid(player_choice - 1) == true) {
            board[player_choice - 1] = mark;
            display_board();
        }
        else {
            i--;
        }
        i++;
    }

    if (state_of_game() == DRAW) {
        SetColor(PINK);
        cout << "平局\n";
        SetColor(WHITE);
    }

    else if (state_of_game() == WIN) {
        win_display();
    }

}

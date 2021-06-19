#include "game.h"

HANDLE hCon;
void SetColor(Color c) {
    if (hCon == NULL)
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, c);
}


game::game() {

    for (int k = 0; k < 9; k++) {
        board[k] = '-';
    }

    
    p = board;    
    row1[0] = p; row1[1] = p + 1; row1[2] = p + 2; 
    row2[0] = p + 3; row2[1] = p + 4; row2[2] = p + 5;
    row3[0] = p + 6; row3[1] = p + 7; row3[2] = p + 8;
    col1[0] = p; col1[1] = p + 3; col1[2] = p + 6;
    col2[0] = p + 1; col2[1] = p + 4; col2[2] = p + 7;
    col3[0] = p + 2; col3[1] = p + 5; col3[2] = p + 8;
    diag1[0] = p; diag1[1] = p + 4; diag1[2] = p + 8;
    diag2[0] = p + 2; diag2[1] = p + 4; diag2[2] = p + 6;
}


bool game::is_the_move_valid(int move) {
    if (board[move] == '-') {
        return true;
    }
    if (move < 9 && board[move] != '-') {
        SetColor(RED);
        cout << "已重複!\n\n";
        SetColor(WHITE);
    }

    if (move > 9) {
        SetColor(RED);
        cout << "That is an illegal choice!\n\n";
        SetColor(WHITE);
    }

    return false;
}

bool game::are_elements_equal(std::array<char*, 3> k) {
    array<char*, 3>::iterator p;
    p = k.begin();
    if (**p == **(p + 1) && **(p + 1) == **(p + 2)) {
        return true;
    }

    else {
        return false;
    }
}

state game::state_of_game() {
    if ((are_elements_equal(row1) == true && *row1[0] != '-')
        || (are_elements_equal(row2) == true && *row2[0] != '-')
        || (are_elements_equal(row3) == true && *row3[0] != '-')
        || (are_elements_equal(col1) == true && *col1[0] != '-')
        || (are_elements_equal(col2) == true && *col2[0] != '-')
        || (are_elements_equal(col3) == true && *col3[0] != '-')
        || (are_elements_equal(diag1) == true && *diag1[0] != '-')
        || (are_elements_equal(diag2) == true && *diag2[0] != '-')) {

        return WIN;
    }

    else if (board_full() == true) {
        return DRAW;
    }

    else {
        return KEEP_PLAYING;
    }

}

bool game::board_full() {
    for (int i = 0; i < 9; i++) {
        if (board[i] == '-') {
            return false;
        }
    }
    return true;
}
void game::display_board() {
    cout << " " << board[0] << "  | " << board[1] << "  | " << board[2] << "  \n____|____|____\n " << board[3] << "  | " << board[4] << "  | " << board[5] << "  \n____|____|____\n " << board[6] << "  | " << board[7] << "  | " << board[8] << "  \n    |    |    \n\n";
}

void game::win_display() {
    if (are_elements_equal(row1) == true) {
        cout << " ";
        color_conv(board[0]);
        cout << "  | ";
        color_conv(board[1]);
        cout << "  | ";
        color_conv(board[2]);
        cout << "  \n____|____|____\n " << board[3] << "  | " << board[4] << "  | " << board[5] << "  \n____|____|____\n " << board[6] << "  | " << board[7] << "  | " << board[8] << "  \n    |    |    \n\n";
        Winner(*row1[0]);
    }

    else if (are_elements_equal(row2) == true) {
        cout << " " << board[0] << "  | " << board[1] << "  | " << board[2] << "  \n____|____|____\n ";
        color_conv(board[3]);
        cout << "  | ";
        color_conv(board[4]);
        cout << "  | ";
        color_conv(board[5]);
        cout << "  \n____|____|____\n " << board[6] << "  | " << board[7] << "  | " << board[8] << "  \n    |    |    \n\n";
        Winner(*row2[0]);
    }

    else if (are_elements_equal(row3) == true) {
        cout << " " << board[0] << "  | " << board[1] << "  | " << board[2] << "  \n____|____|____\n " << board[3] << "  | " << board[4] << "  | " << board[5] << "  \n____|____|____\n ";
        color_conv(board[6]);
        cout << "  | ";
        color_conv(board[7]);
        cout << "  | ";
        color_conv(board[8]);
        cout << "  \n    |    |    \n\n";
        Winner(*row3[0]);
    }

    else if (are_elements_equal(col1) == true) {
        cout << " ";
        color_conv(board[0]);
        cout << "  | " << board[1] << "  | " << board[2] << "  \n____|____|____\n ";
        color_conv(board[3]);
        cout << "  | " << board[4] << "  | " << board[5] << "  \n____|____|____\n ";
        color_conv(board[6]);
        cout << "  | " << board[7] << "  | " << board[8] << "  \n    |    |    \n\n";
        Winner(*col1[0]);
    }

    else if (are_elements_equal(col2) == true) {
        cout << " " << board[0] << "  | ";
        color_conv(board[1]);
        cout << "  | " << board[2] << "  \n____|____|____\n " << board[3] << "  | ";
        color_conv(board[4]);
        cout << "  | " << board[5] << "  \n____|____|____\n " << board[6] << "  | ";
        color_conv(board[7]);
        cout << "  | " << board[8] << "  \n    |    |    \n\n";
        Winner(*col2[0]);
    }

    else if (are_elements_equal(col3) == true) {
        cout << " " << board[0] << "  | " << board[1] << "  | ";
        color_conv(board[2]);
        cout << "  \n____|____|____\n " << board[3] << "  | " << board[4] << "  | ";
        color_conv(board[5]);
        cout << "  \n____|____|____\n " << board[6] << "  | " << board[7] << "  | ";
        color_conv(board[8]);
        cout << "  \n    |    |    \n\n";
        Winner(*col3[0]);
    }

    else if (are_elements_equal(diag1) == true) {
        cout << " ";
        color_conv(board[0]);
        cout << "  | " << board[1] << "  | " << board[2] << "  \n____|____|____\n " << board[3] << "  | ";
        color_conv(board[4]);
        cout << "  | " << board[5] << "  \n____|____|____\n " << board[6] << "  | " << board[7] << "  | ";
        color_conv(board[8]);
        cout << "  \n    |    |    \n\n";
        Winner(*diag1[0]);
    }

    else if (are_elements_equal(diag2) == true) {
        cout << " " << board[0] << "  | " << board[1] << "  | ";
        color_conv(board[2]);
        cout << "  \n____|____|____\n " << board[3] << "  | ";
        color_conv(board[4]);
        cout << "  | " << board[5] << "  \n____|____|____\n ";
        color_conv(board[6]);
        cout << "  | " << board[7] << "  | " << board[8] << "  \n    |    |    \n\n";
        Winner(*diag2[0]);
    }

}
void game::color_conv(char c) {
    SetColor(TEAL);
    cout << c;
    SetColor(WHITE);
}
void game::Winner(char c) {
    if (c == 'O') {
        SetColor(YELLOW);
        cout << player1 << "恭喜贏了....\n";
        SetColor(WHITE);
    }
    else if (c == 'X') {
        SetColor(YELLOW);
        cout << player2 << "恭喜贏了....\n";
        SetColor(WHITE);
    }
}

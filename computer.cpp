#include "computer.h"


computer::computer() {
    srand((time(NULL)));
    list.push_back(row1);
    list.push_back(row2);
    list.push_back(row3);
    list.push_back(col1);
    list.push_back(col2);
    list.push_back(col3);
    list.push_back(diag1);
    list.push_back(diag2);
    corners[0] = p; corners[1] = p + 2; corners[2] = p + 6; corners[3] = p + 8;
    middle_corners[0] = p + 1; middle_corners[1] = p + 3; middle_corners[2] = p + 5; middle_corners[3] = p + 7;
}

void computer::play() {
    int i = 1, player_choice;
    char mark;
    SetColor(DARKYELLOW);
    cout << "輸入玩家名字:\n";
    getline(cin, dummy);
    getline(cin, player1);
    player2 = "電腦";
    SetColor(WHITE);

    while (state_of_game() == KEEP_PLAYING) {
        if (i % 2 != 0) {
            mark = 'O';
            cout << player1 << ":選擇你的位置....\n";
            cin >> player_choice;
            if (is_the_move_valid(player_choice - 1) == true) {
                board[player_choice - 1] = mark;
                display_board();
            }
            else {
                i--;
            }
        }

        else if (i % 2 == 0) {
            cout << player2 << ":電腦選擇位置....\n";
            comp_choice();
            display_board();
        }
        i++;
    }

    if (state_of_game() == DRAW) {
        SetColor(PINK);
        cout << "平局!!!\n";
        SetColor(WHITE);
    }

    else if (state_of_game() == WIN) {
        win_display();
    }
}

void computer::comp_choice() {
    win_block_info status;
    corner_info corner_status;
    status = possible_wins_or_blocks();
    if (status.wins == true) {
        for (int k = 0; k < 3; k++) {
            if (*list[status.place][k] == '-') {
                *list[status.place][k] = 'X';
                list.erase(list.begin() + status.place);
                return;
            }
        }
    }

    if (status.blocks == true) {
        for (int k = 0; k < 3; k++) {
            if (*list[status.place][k] == '-') {
                *list[status.place][k] = 'X';
                list.erase(list.begin() + status.place);
                return;
            }
        }
    }

    if (board[4] == '-') {
        board[4] = 'X';
        return;
    }

    corner_status = corner_placement();
    if (corner_status.corners == true) {
        int ran = rand() % corner_status.empty_pos.size();
        *corner_status.empty_pos[ran] = 'X';
        corner_status.empty_pos.clear();
        return;
    }

    if (corner_status.mid_corners == true) {
        int ran = rand() % corner_status.empty_pos.size();
        *corner_status.empty_pos[ran] = 'X';
        corner_status.empty_pos.clear();
        return;
    }
}

computer::win_block_info computer::possible_wins_or_blocks() {
    win_block_info status;
    status.blocks = false;
    status.wins = false;
    status.place = 10000;
    for (int i = 0; i < list.size(); i++) {
        if (any_two_elements_equal(list[i]) == true) {
            status.blocks = true;
            status.place = i;
            if (*list[i][0] == 'X' || *list[i][1] == 'X') {
                status.wins = true;
                status.blocks = false;
                status.place = i;
                return status;
            }
        }
    }

    return status;
}



bool computer::any_two_elements_equal(array<char*, 3> current) {

    if ((*current[0] == *current[1] && *current[0] != '-')
        || (*current[1] == *current[2] && *current[1] != '-')
        || (*current[2] == *current[0] && *current[2] != '-')) {
        if (*current[0] == '-' || *current[1] == '-' || *current[2] == '-') {
            return true;
        }
    }

    return false;
}

computer::corner_info computer::corner_placement() {
    corner_info status;
    status.corners = false;
    status.mid_corners = false;
    for (int i = 0; i < 4; i++) {
        if (*corners[i] == '-') {
            status.corners = true;
            status.empty_pos.push_back(corners[i]);
        }
    }
    if (status.corners == true) {
        return status;
    }

    for (int i = 0; i < 4; i++) {
        if (*middle_corners[i] == '-') {
            status.mid_corners = true;
            status.empty_pos.push_back(corners[i]);
        }
    }

    return status;
}

void computer::test() {
    cout << possible_wins_or_blocks().wins << " " << possible_wins_or_blocks().place << endl;
    comp_choice();
    display_board();
}

computer::~computer() {
    list.clear();
}

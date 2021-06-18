#include <iostream>
#include <string>
#include <Windows.h>
#include "game.h"
#include "human.h"
#include "computer.h"
#include <sstream>

void main_play();
int main() {

    SetColor(DARKGREEN);
    std::cout << "~~~~~~~~Tic-Tac-Taoe~~~~~~~~" << std::endl;
    std::cout << "By Default Player 1 is 'O' and Player 2 is 'X'\n";
    std::cout << "The choice of cells is mapped out in the following legend\n\n\n";
    std::cout << " 1  | 2  | 3  \n||\n 4  | 5  | 6  \n||\n 7  | 8  | 9  \n    |    |    \n\n";
    std::cout << "**\n";
    SetColor(WHITE);

    main_play();
    return 0;
}

void main_play() {
    int choice, replay;
    std::cout << "What do You want to Do?\n 1.Play Human vs. Human(2 Player) \n 2.Computer vs. Human(1 Player)\n 3.Exit\n\n";
    std::cin >> choice;
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
            std::cout << "Thank You for Playing :)\n\n";
            SetColor(WHITE);
            return;
        }
        }

        SetColor(DARKTEAL);
        std::cout << "Do You Want to Play Another Game?\n 1.Yes \n 2.No \n";
        SetColor(WHITE);
        std::cin >> replay;
        if (replay == 1) {
            main_play();
        }
        else {
            SetColor(GREEN);
            std::cout << "Thank You for Playing :)\n\n";
            SetColor(WHITE);
            return;
        }
    }
    SetColor(RED);
    std::cout << "That is not a Valid Choice....\n Please Make a Valid Choice....\n\n";
    SetColor(WHITE);
    main_play();
}
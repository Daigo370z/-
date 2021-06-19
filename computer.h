#ifndef COMPUTER_H
#define COMPUTER_H
#include "game.h"
#include <vector>
#include <time.h>
using namespace std;

enum specifier { CORNERS = 0, MIDDLE_CORNERS };
enum status { WINS, BLOCK, NONE };

class computer :
    public game
{
protected:
    struct win_block_info {
        bool wins;
        bool blocks;
        int place;
    };
    struct corner_info {
        bool corners;
        bool mid_corners;
        vector<char> empty_pos;
    };
    vector<std::array<char, 3>> list;
    vector<status> status_list;
    array<char, 4> corners;
    array<char, 4> middle_corners;
public:
    computer();
    void play();
    void comp_choice();
    win_block_info possible_wins_or_blocks();
    corner_info corner_placement();
    bool any_two_elements_equal(array<char, 3>);
    void test();
    vector<char> empty_places_list(specifier);
    ~computer();

};
#endif

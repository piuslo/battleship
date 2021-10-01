#include <iostream>
#include <vector>
#include <cstdlib>

#include "Board.h"
#include "OpponentBoard.h"
#include "PlayerBoard.h"

using namespace std;

const int NUM_ROWS = 10;
const int NUM_COLS = 10;
const int SHIP_LENGTH = 3;
const int NUM_SHIPS = 4;


int main() {
    srand(time(0));
    PlayerBoard player;
    OpponentBoard opponent;
    for (int i = 0; i < NUM_SHIPS; i++)
        opponent.assign_ships();
    int input_x, input_y;
    int ships_left = NUM_SHIPS * SHIP_LENGTH;
    // int ships_left2 = NUM_SHIPS * SHIP_LENGTH;
    while (ships_left != 0) {
        cout << "Your board:" << endl;
        player.print();
        cout << "Opponent's board:" << endl;
        opponent.print();
        cout << "Between 0 and 9, input X coordinate: ";
        cin >> input_x;
        cout << "Between 0 and 9, input Y coordinate: ";
        cin >> input_y;
        if (opponent.play(input_x, input_y)) {
            player.hit(input_x, input_y);
            ships_left--;
        } else {
            player.miss(input_x, input_y);
        }
    }
    cout << "Success! All ships have been sunk." << endl;
    return 0;
}

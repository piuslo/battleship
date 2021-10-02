/*
@author Pius Lo
@file battleship.cpp
@date October 1, 2021
To play: give valid inputs and don't hit the same ship twice otherwise in different
spots otherwise the program will think you've hit multiple ships when you've just
hit two blocks of the ship.
*/
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

//Controls the operation of the program.
int main() {
    srand(time(0));
    PlayerBoard ocean1;
    OpponentBoard target_2;
    PlayerBoard ocean2;
    OpponentBoard target_1;
    for (int i = 0; i < NUM_SHIPS; i++) {
        target_2.assign_ships();
        target_1.assign_ships();
    }
    int input_x, input_y = 0;
    int ships_left1 = NUM_SHIPS;
    int ships_left2 = NUM_SHIPS;
    while (ships_left1 != 0 && ships_left2 != 0) {
        cout << "Player 1's ocean grid" << endl;
        ocean1.print();
        cout << "Player 1's targets (Player 2's ships)" << endl;
        target_2.print();
        cout << "Player 2's ocean grid" << endl;
        ocean2.print();
        cout << "Player 2's targets (Player 1's ships)" << endl;
        target_1.print();
        cout << "Player 1's move. Between 0 and 9, input X coordinate:";
        cin >> input_x;
        cout << "Between 0 and 9, input Y coordinate:";
        cin >> input_y;
        if (target_2.play(input_x, input_y)) {
            ocean1.hit(input_x, input_y);
            ships_left1--;
            cout << "Hit! Ships left for player 1 to sink: " << ships_left1 << endl;
        } else {
            ocean1.miss(input_x, input_y);
        }
        if (ships_left1 == 0) {
            cout << "Game is over. Player 1 has sunk all of Player 2's ships."
            << endl;
            return 0;
        }
        cout << "Player 1's ocean grid" << endl;
        ocean1.print();
        cout << "Player 1's targets (Player 2's ships)" << endl;
        target_2.print();
        cout << "Player 2's ocean grid" << endl;
        ocean2.print();
        cout << "Player 2's targets (Player 1's ships)" << endl;
        target_1.print();
        cout << "Player 2's move. Between 0 and 9, input X coordinate:";
        cin >> input_x;
        cout << "Between 0 and 9, input Y coordinate:";
        cin >> input_y;
        if (target_1.play(input_x, input_y)) {
            ocean2.hit(input_x, input_y);
            ships_left2--;
            cout << "Hit! Ships left for player 2 to sink: " << ships_left2 << endl;
        } else {
            ocean2.miss(input_x, input_y);
        }
        if (ships_left2 == 0) {
            cout << "Game is over. Player 2 has sunk all of Player 1's ships."
            << endl;
            return 0;
        }
    }
    return 0;
}

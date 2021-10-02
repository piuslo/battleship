#include "OpponentBoard.h"
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;
const int NUM_ROWS = 10;
const int NUM_COLS = 10;
const int SHIP_LENGTH = 3;
const int NUM_SHIPS = 4;
/*
* Assigns locations of the ships of the opponents board
*/
void OpponentBoard::assign_ships() {
    int x, y;
    x = rand() % 8;
    y = rand() % 8;

    int orientation;
    orientation = rand() % 2;
    while (!check_valid(x, y)) {
        x = rand() % 8;
        y = rand() % 8;
    }
    if (orientation == 0) {
        for (int i = 0; i < SHIP_LENGTH; i++) {
            board_vector[x + i][y] = 'S';
        }
    }
    if (orientation == 1) {
        for (int i = 0; i < SHIP_LENGTH; i++) {
            board_vector[x][y + i] = 'S';
        }
    }
}

/*
* Provides pop-up when the player chooses a spot thats been hit
*/
void OpponentBoard::hit_already() {
    cout << "You've hit this spot already!" << endl;
}

/*
* Provides pop-up when the player misses the ship
*/
void OpponentBoard::missed_ship() {
    cout << "You've missed your opponent's ship!" << endl;

}

/*
* Provides pop-up when the player hits the ship
*/
void OpponentBoard::hit_ship() {
    cout << "You've hit your opponent's ship!" << endl;
}

/*
* Plays the game
* @param input_x the inputted x value
* @param input_y the inputted y value
* @return true if ship is hit, else false
*/
bool OpponentBoard::play(int input_x, int input_y) {
    if (board_vector[input_x][input_y] == 'S') {
        board_vector[input_x][input_y] = 'X';
        return true;
    } else if (board_vector[input_x][input_y] == '-') {
        return false;
    } else if (board_vector[input_x][input_y] == 'X' || board_vector[input_x][input_y] == '0') {
        return false;
    }
    return true;
}

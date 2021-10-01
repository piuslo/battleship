#include <iostream>
#include <vector>
#include <cstdlib>
#include "Board.h"
using namespace std;

const int NUM_ROWS = 10;
const int NUM_COLS = 10;
const int SHIP_LENGTH = 3;
const int NUM_SHIPS = 4;


/*
* Default constructor for Board class
*/
Board::Board() {
    board_vector.resize(NUM_ROWS);
    for (int row = 0; row < NUM_ROWS; row++) {
        board_vector[row].assign(10, '-');
    }
}

/*
* Prints the board
*/
void Board::print() {
    cout << "  0  1  2  3  4  5  6  7  8  9" << endl;
    for (int col = 0; col < NUM_COLS; col++) {
        cout << col << " ";
        for (int row = 0; row < NUM_ROWS; row++)
            cout << board_vector[row][col] << "  ";
        cout << endl;
    }
}

/*
* Virtual method for PlayerBoard
* @param input_x the inputted x value
* @param input_y the inputted y value
*/
void Board::miss(int input_x, int input_y) {
    board_vector[input_x][input_y] = 'N';
}

/*
* Virtual method for PlayerBoard
* @param input_x the inputted x value
* @param input_y the inputted y value
*/
void Board::hit(int input_x, int input_y) {
    board_vector[input_x][input_y] = 'N'; //for never print
    cout << "This should never print";
}

/*
* Virtual method for PlayerBoard
* @param input_x the inputted x value
* @param input_y the inputted y value
*/
bool Board::play(int input_x, int input_y) {
    board_vector[input_x][input_y] = 'N'; //This will never print
    return false;
}

/*
* Checks if theres not a ship present within a 3 x 3 distance
* @param x the x value
* @param y the y value
* @return false if 'S' is present, otherwise true
*/
bool Board::check_valid(int & x, int & y) {
    for (int col = 0; col < SHIP_LENGTH; col++) {
        for (int row = 0; row < SHIP_LENGTH; row++) {
            if (board_vector[x + col][y + row] == 'S')
                return false;
        }
    }
    return true;
}

/*
* Virtual method for OpponentBoard
*/
void Board::assign_ships() {
}

/*
@author Pius Lo
@file PlayerBoard.cpp
@date October 1, 2021
*/
#include "PlayerBoard.h"

/*
* Changes the '-' to a '0' when the player misses
* @param input_x the inputted x value
* @param input_y the inputted y value
*/
void PlayerBoard::miss(int input_x, int input_y) {
    if (board_vector[input_x][input_y] == '-') {
        board_vector[input_x][input_y] = '0';
    } else {
        return;
    }
}

/*
* Changes the '-' to a 'X' when the player hits
* @param input_x the inputted x value
* @param input_y the inputted y value
*/
void PlayerBoard::hit(int input_x, int input_y) {
    if (board_vector[input_x][input_y] == '-') {
        board_vector[input_x][input_y] = 'X';
    } else {
        return;
    }
}

/*
@author Pius Lo
@file PlayerBoard.h
@date October 1, 2021
*/
#ifndef PLAYERBOARD_H
#define PLAYERBOARD_H
#include "Board.h"

class PlayerBoard : public Board {
public:
    void miss(int input_x, int input_y);
    void hit(int input_x, int input_y);
};

#endif

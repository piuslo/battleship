#ifndef OPPONENTBOARD_H
#define OPPONENTBOARD_H
#include "Board.h"
class OpponentBoard : public Board {
public:
    void assign_ships();
    bool play(int input_x, int input_y);
    void hit_ship();
    void hit_already();
    void missed_ship();

};

#endif

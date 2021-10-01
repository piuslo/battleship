#ifndef BOARD_H
#define BOARD_H
#include <cstdlib>
#include <vector>


class Board {
protected:
    std::vector<std::vector<char> > board_vector;
public:
    Board();
    void print();
    bool check_valid(int & x, int & y);
    virtual bool play(int input_x, int input_y);
    virtual void assign_ships();
    virtual void miss(int input_x, int input_y);
    virtual void hit(int input_x, int input_y);
};




#endif

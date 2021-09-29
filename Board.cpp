#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int NUM_ROWS = 10;
const int NUM_COLS = 10;
const int SHIP_LENGTH = 3;
const int NUM_SHIPS = 4;

class Board {
protected:
    vector<vector<char> > board_vector;
public:
    Board();
    void print();
    bool check_valid(int & x, int & y);
    virtual bool play(int input_x, int input_y);
    virtual void assign_ships();
    virtual void miss(int input_x, int input_y);
    virtual void hit(int input_x, int input_y);
};

class PlayerBoard : public Board {
public:
    void miss(int input_x, int input_y);
    void hit(int input_x, int input_y);
};

class OpponentBoard : public Board {
public:
    void assign_ships();
    bool play(int input_x, int input_y);
    void hit_ship();
    void hit_already();
    void missed_ship();

};

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
    // start_color();
    // init_pair(1, COLOR_WHITE, COLOR_GREEN);
    // attron(COLOR_PAIR(1));
    // addstr("You have hit this spot already!");
    cout << "You've hit this spot already!" << endl;
    // attroff(COLOR_PAIR(1));
    // refresh();
    // getch();
    // endwin();
}

/*
* Provides pop-up when the player misses the ship
*/
void OpponentBoard::missed_ship() {
    // start_color();
    // init_pair(1, COLOR_WHITE, COLOR_RED);
    // attron(COLOR_PAIR(1));
    // addstr("You missed your opponent's ship!");
    cout << "You've missed your opponent's ship!" << endl;
    // attroff(COLOR_PAIR(1));
    // refresh();
    // getch();
    // endwin();
}

/*
* Provides pop-up when the player hits the ship
*/
void OpponentBoard::hit_ship() {
    // start_color();
    // init_pair(1, COLOR_WHITE, COLOR_BLUE);
    // attron(COLOR_PAIR(1));
    // addstr("You've hit your opponent's ship!");
    cout << "You've hit your opponent's ship!" << endl;
    // attroff(COLOR_PAIR(1));
    // refresh();
    // getch();
    // endwin();
}

/*
* Plays the game
* @param input_x the inputted x value
* @param input_y the inputted y value
* @return true if ship is hit, else false
*/
bool OpponentBoard::play(int input_x, int input_y) {
    // initscr();
    if (board_vector[input_x][input_y] == 'S') {
        // hit_ship();
        // delwin(win);
        board_vector[input_x][input_y] = 'X';
        return true;
    } else if (board_vector[input_x][input_y] == '-') {
        // missed_ship();
        // delwin(win);
        return false;
    } else if (board_vector[input_x][input_y] == 'X' || board_vector[input_x][input_y] == '0') {
        // hit_already();
        // delwin(win);
        return false;
    }
    return true;
}

int main (){
    return 0;
}

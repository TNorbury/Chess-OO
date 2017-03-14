#ifndef _BOARD_H
#define _BOARD_H

#define FILE "      a    b    c    d    e    f    g    h    "
#define BOARD_LINE "   -----------------------------------------  "

#include <iostream>
#include "Square.h"

using namespace std;

class Board
{
public:

    /**
     * @return the current board instance
     */
    static Board& getInstance();

    static int getDimensions();

    /**
     * @param rank
     * @param file
     */
    Square& getSquareAt(int rank, int file);

    /**
     * @param from
     * @param to
     */
    bool isClearRank(Square& from, Square& to);

    /**
     * @param from
     * @param to
     */
    bool isClearFile(Square& from, Square& to);

    /**
     * @param from
     * @param to
     */
    bool isClearDiagonal(Square& from, Square& to);

    /**
     * @param os
     */
    void display(ostream& os);
private:
    static const int DIMENSION = 8;
    static Board& instance;
    Square boardSquares[8][8];
    Board();
};

#endif //_BOARD_H
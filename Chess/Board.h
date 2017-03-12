/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include "Square.h"

using namespace std;

class Board
{
public:

    static Board& getInstance();

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
    int DIMENSION = 8;
    static Board& instance;
    Square boardSquares[8][8];
    Board();
};

#endif //_BOARD_H
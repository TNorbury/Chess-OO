#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
#include "Square.h"

#define FILE "      a    b    c    d    e    f    g    h    "
#define BOARD_LINE "   +----+----+----+----+----+----+----+----+  "

using namespace std;

class Board
{
public:

    /**
     * @return the current board instance
     */
    static Board& getInstance();

    /**
     * @return the dimensions of the board
     */
    static int getDimensions();

    /**
     * @return True if the rank and file are within the bounds of the board.
     */
    static bool inBounds(int rank, int file);

    /**
     * @param rank The rank (row) of the square
     * @param file The file (column) of the square
     * @return Square* A pointer to the square at the given rank and file
     */
    Square* getSquareAt(int rank, int file);

    /**
     * Check if the board is clear from one square to another, in the rank 
     * (vertical) direction
     * @param from The starting square
     * @param to The ending square
     * @return True if it's clear
     */
    bool isClearRank(Square& from, Square& to);

    /**
     * Check if the board is clear from one square to another, in the file
     * (horizontal) direction
     * @param from The starting square
     * @param to The ending square
     * @return True if it's clear
     */
    bool isClearFile(Square& from, Square& to);

    /**
     * Check if the board is clear from one square to another, in the diagonal
     * direction
     * @param from The starting square
     * @param to The ending square
     * @return True if it's clear
     */
    bool isClearDiagonal(Square& from, Square& to);


    /**
     * @param os The output stream to output to
     */
    void display(ostream& os);
private:
    static const int DIMENSION = 8;
    static Board& _instance;
    Board();
    Square* _boardSquares[DIMENSION][DIMENSION];
};

#endif //_BOARD_H

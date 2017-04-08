#ifndef _QUEEN_H
#define _QUEEN_H

#include "Piece.h"


class Queen : public Piece
{
public:

    /**
     * Create a new Queen at the given square and for the specified color
     * @param location The square that the Queen will sit on
     * @param color The color of the piece
     */
    Queen(Square* location, string color);

    /**
     * @return the value of the piece
     */
    int getValue();

    /**
     * Checks if the piece can move to the given square
     * @param location The square that the piece is checking if it can move to
     * @return true, if the piece can move to the given square, otherwise false
     */
    bool canMoveTo(Square* location);

    /**
     * Prints out the Queen
     * @param os The ostream that the Queen should be printed to.
     */
    void display(ostream & os);
};

#endif //_QUEEN_H
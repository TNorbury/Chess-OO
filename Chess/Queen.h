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
    Queen(Square& location, string color);

    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square& location);

    /**
     * Prints out the Queen
     * @param os The ostream that the Queen should be printed to.
     */
    void display(ostream & os);
};

#endif //_QUEEN_H
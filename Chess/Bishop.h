#ifndef _BISHOP_H
#define _BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
public:

    /**
     * Create a new Bishop at the given square and for the specified color
     * @param location The square that the Bishop will sit on
     * @param color The color of the piece
     */
    Bishop(Square& location, string color);

    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square& location);

    /**
     * Prints out the Bishop
     * @param os The ostream that the bishop should be printed to.
     */
    void display(ostream& os);
};

#endif //_BISHOP_H
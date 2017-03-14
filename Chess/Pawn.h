#ifndef _PAWN_H
#define _PAWN_H

#include <iostream>
#include "RestrictedPiece.h"
class Square;


class Pawn : public RestrictedPiece
{
public:

    /**
     * Create a new Pawn at the given square and for the specified color
     * @param location The square that the Pawn will sit on
     * @param color The color of the piece
     */
    Pawn(Square& location, string color);

    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square& location);

    /**
     * Prints out the Pawn
     * @param os The ostream that the Pawn should be printed to.
     */
    void display(ostream& os);

private:
    Piece* delegate;
};

#endif //_PAWN_H
#ifndef _ROOK_H
#define _ROOK_H

#include "RestrictedPiece.h"


class Rook : public RestrictedPiece
{
public:

    /**
     * Create a new Rook at the given square and for the specified color
     * @param location The square that the rook will sit on
     * @param color The color of the piece
     */
    Rook(Square& location, string color);

    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square& location);

    /**
     * Prints out the Rook
     * @param os The ostream that the Rook should be printed to.
     */
    void display(ostream& os);
};

#endif //_ROOK_H
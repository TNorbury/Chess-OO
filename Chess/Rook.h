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
    Rook(Square* location, string color);

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
     * Prints out the Rook
     * @param os The ostream that the Rook should be printed to.
     */
    void display(ostream& os);
};

#endif //_ROOK_H
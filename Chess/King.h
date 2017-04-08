#ifndef _KING_H
#define _KING_H

#include "RestrictedPiece.h"
//#include "Square.h"
class Square;


class King : public RestrictedPiece
{
public:

    /**
     * Create a new King at the given square and for the specified color
     * @param location The square that the King will sit on
     * @param color The color of the piece
     */
    King(Square* location, string color);

    /**
     * @return the value of the piece
     */
    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square* location);

    /**
     * Prints out the King
     * @param os The ostream that the King should be printed to.
     */
    void display(ostream& os);
};

#endif //_KING_H
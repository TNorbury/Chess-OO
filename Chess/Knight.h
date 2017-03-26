#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "Piece.h"
//#include "Square.h"
class Square;


class Knight : public Piece
{
public:

    /**
     * Create a new Knight at the given square and for the specified color
     * @param location The square that the knight will sit on
     * @param color The color of the piece
     */
    Knight(Square& location, string color);
    
    /**
     * @return the value of the piece
     */
    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square& location);

    /**
     * Prints out the Knight
     * @param os The ostream that the Knight should be printed to.
     */
    void display(ostream& os);
};

#endif //_KNIGHT_H
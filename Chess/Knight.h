/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "Piece.h"
//#include "Square.h"
class Square;


class Knight : public Piece
{
public:

    Knight(Square& location, string color);

    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square& location);

    void display(ostream& os);
};

#endif //_KNIGHT_H
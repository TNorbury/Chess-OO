#ifndef _BISHOP_H
#define _BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
public:

    Bishop(Square& location, string color);

    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square& location);

    void display(ostream& os);
};

#endif //_BISHOP_H
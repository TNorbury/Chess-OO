/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _QUEEN_H
#define _QUEEN_H

#include "Piece.h"


class Queen : public Piece
{
public:

    Queen(Square& location, string color);

    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square& location);


    void display(ostream & os);
};

#endif //_QUEEN_H
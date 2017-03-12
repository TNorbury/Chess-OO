/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _PAWN_H
#define _PAWN_H

#include <iostream>
#include "RestrictedPiece.h"
class Square;


class Pawn : public RestrictedPiece
{
public:

    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square& location);

    /**
     * @param os
     */
    void display(ostream& os);

private:
    Piece* delegate;
};

#endif //_PAWN_H
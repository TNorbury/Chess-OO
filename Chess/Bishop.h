/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _BISHOP_H
#define _BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
public:

    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square& location);
};

#endif //_BISHOP_H
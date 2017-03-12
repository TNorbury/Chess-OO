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

    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square& location);
};

#endif //_QUEEN_H
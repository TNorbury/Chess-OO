/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _KING_H
#define _KING_H

#include "RestrictedPiece.h"
//#include "Square.h"
class Square;


class King : public RestrictedPiece
{
public:

    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square& location);
};

#endif //_KING_H
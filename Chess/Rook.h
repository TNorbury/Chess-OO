/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _ROOK_H
#define _ROOK_H

#include "RestrictedPiece.h"


class Rook : public RestrictedPiece
{
public:

    Rook(Square& location, string color);

    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square& location);

    void display(ostream& os);
};

#endif //_ROOK_H
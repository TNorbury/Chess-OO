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

    int getValue();

    /**
     * @param location
     */
    bool canMoveTo(Square& location);
};

#endif //_ROOK_H
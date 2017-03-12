/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _RESTRICTEDPIECE_H
#define _RESTRICTEDPIECE_H

#include "Piece.h"
class Player;
class Square;

class RestrictedPiece : public Piece
{
public:

    /**
     * @param location
     * @param byPlayer
     */
    virtual bool moveTo(Square& location, Player& byPlayer);
protected:

    bool hasMoved();
private:
    bool moved = false;
};

#endif //_RESTRICTEDPIECE_H
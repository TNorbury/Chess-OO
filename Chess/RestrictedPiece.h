/**
 * 1851366
 * Assignment 7
 * 2017-04-13
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
     * Create a new Restricted Piece at the given square and for the specified
     * color
     * @param location The square that the Restricted Piece will sit on
     * @param color The color of the piece
     */
    RestrictedPiece(Square* location, string color);

    /**
     * Move the piece to the given location
     * @param location The location to be moved to
     * @param byPlayer The player making the move
     */
    virtual bool moveTo(Square* location, Player& byPlayer);
protected:

    /**
     * @return true, if this piece has moved. Otherwise false
     */
    bool hasMoved();
private:
    bool _moved = false;
};

#endif //_RESTRICTEDPIECE_H
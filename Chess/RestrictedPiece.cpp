/**
 * 1851366
 * Assignment 7
 * 2017-04-11
 */

#include "RestrictedPiece.h"
#include "Square.h"
#include "Player.h"
#include "Piece.h"
#include "Board.h"

/**
 * RestrictedPiece implementation
 */


RestrictedPiece::RestrictedPiece(Square * location, string color): Piece(location, color){}

bool RestrictedPiece::moveTo(Square* location, Player& byPlayer)
{
    // Move the piece
    Piece::moveTo(location, byPlayer);

    // Now that this piece has moved, set the flag.
    _moved = true;
    return _moved;
}


bool RestrictedPiece::hasMoved()
{
    return _moved;
}


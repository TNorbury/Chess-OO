/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#include "Board.h"
#include "Piece.h"
#include "Player.h"
#include "RestrictedPiece.h"
#include "Square.h"

 /**
  * RestrictedPiece implementation
  */

RestrictedPiece::RestrictedPiece(Square * location, string color)
    : Piece(location, color)
{
}


bool RestrictedPiece::moveTo(Square* location, Player& byPlayer)
{
    // Since this piece is going to move, set the flag
    _moved = true;

    // Defer movement to Piece
    return Piece::moveTo(location, byPlayer);;
}


bool RestrictedPiece::hasMoved()
{
    return _moved;
}


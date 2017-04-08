#include "RestrictedPiece.h"
#include "Square.h"
#include "Player.h"
#include "Piece.h"
#include "Board.h"

/**
 * RestrictedPiece implementation
 */



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


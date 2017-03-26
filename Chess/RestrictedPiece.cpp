#include "RestrictedPiece.h"
#include "Square.h"
#include "Player.h"
#include "Piece.h"
#include "Board.h"

/**
 * RestrictedPiece implementation
 */



bool RestrictedPiece::moveTo(Square& location, Player& byPlayer)
{
    Square* toMoveTo = &Board::getInstance()
        .getSquareAt(location.getRank(), location.getFile());

    // If the square is occupied then capture the piece that currently occupies
    // it
    if (location.isOccupied())
    {
        // Have the moving player capture the piece and then remove it from the
        // board
        byPlayer.capture(location.getOccupant());
        location.setOccupant(NULL);
    }

    // Remove the piece from its current spot on the board
    getLocation().setOccupant(NULL);

    // Tell the piece about its new location
    setLocation(toMoveTo);

    // Move the piece to its new location on the board
    //Board::getInstance().getSquareAt(location.getRank(), location.getFile())
    //    .setOccupant(this);
    toMoveTo->setOccupant(this);

    // Now that this piece has moved, set the flag.
    _moved = true;
    return _moved;
}


bool RestrictedPiece::hasMoved()
{
    return _moved;
}


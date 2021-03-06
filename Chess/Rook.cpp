/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#include "Rook.h"
#include "Square.h"

 /**
  * Rook implementation
  */

Rook::Rook(Square* location, string color) : RestrictedPiece(location, color)
{
}


int Rook::getValue()
{
    // Value for chess pieces taken from http://chess.stackexchange.com/a/4218
    return 5;
}


bool Rook::canMoveTo(Square* location)
{
    bool pathClear = false;
    bool canMoveTo = false;

    // Determine if the destination square is to the side, or above/below the
    // current piece
    // If the piece and destination square are on the same file, then they are
    // above/below one another
    if (_location->getFile() == location->getFile())
    {
        pathClear = Board::getInstance()->isClearFile(_location, location);
    }

    // Otherwise, if the piece and destination square are on the same rank,
    // then they are to the side of one another
    else if (_location->getRank() == location->getRank())
    {
        pathClear = Board::getInstance()->isClearRank(_location, location);
    }

    // If neither of those are true, then we can't move to the given square

    // If the rank or file is clear, then check if this piece can actually 
    // move onto the destination square
    if (pathClear)
    {
        // If the square isn't occupied, or it's occupied by an opponent's
        // piece, then we can move there
        canMoveTo = (!location->isOccupied()) ||
            (location->getOccupant()->getColor() != _color);
    }

    return canMoveTo;
}


void Rook::display(ostream & os)
{
    // Print out something different depending on the color of the piece
    if (_color == WHITE_COLOR)
    {
        os << WHITE_ROOK;
    }
    else
    {
        os << BLACK_ROOK;
    }
}

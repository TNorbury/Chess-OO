/**
 * 1851366
 * Assignment 7
 * 2017-04-13
 */

#include "Queen.h"
#include "Square.h"

 /**
  * Queen implementation
  */

Queen::Queen(Square* location, string color) : Piece(location, color) {}


int Queen::getValue()
{
    // Value for chess pieces taken from http://chess.stackexchange.com/a/4218
    return 9;
}


bool Queen::canMoveTo(Square* location)
{
    bool canMoveTo = false;
    bool pathClear = false;

    // Start by checking if there is a clear path between the queen and the 
    // destination location.
    // If the queen and destination are on the same file, then check if a file 
    // (vertical) path is clear
    if (_location->getFile() == location->getFile())
    {
        pathClear = Board::getInstance().isClearFile(_location, location);
    }

    // Otherwise, if the queen and destination are on the same rank, then check 
    // if a rank (horizontal) path is clear
    else if (_location->getRank() == location->getRank())
    {
        pathClear = Board::getInstance().isClearRank(_location, location);
    }

    // Otherwise, if the queen and destiation aren't on the same rank or file, 
    // then we'll check if there is a clear diagonal path
    else
    {
        pathClear = Board::getInstance().isClearDiagonal(_location, location);
    }

    // If there was a clear path between the queen and the destination, then 
    // check if the queen can occupy the square
    if (pathClear)
    {
        // If the square isn't occupied, or it's occupied by an opponent's 
        // piece, then we can move to that square
        canMoveTo = (!location->isOccupied())
            || (location->getOccupant()->getColor() != _color);
    }

    return canMoveTo;
}


void Queen::display(ostream & os)
{
    // Print out something different depending on the color of the piece
    if (_color == WHITE_COLOR)
    {
        os << WHITE_QUEEN;
    }
    else
    {
        os << BLACK_QUEEN;
    }
}

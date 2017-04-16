/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#include "Bishop.h"
#include "Square.h"

 /**
  * Bishop implementation
  */

Bishop::Bishop(Square* location, string color) : Piece(location, color) {}

int Bishop::getValue()
{
    // Value for chess pieces taken from http://chess.stackexchange.com/a/4218
    return 3;
}


bool Bishop::canMoveTo(Square* location)
{
    bool canMoveTo = false;
    bool pathClear = false;

    // Determine if their is a clear path diagonally from the bishop to the 
    // destination location
    pathClear = Board::getInstance().isClearDiagonal(_location, location);

    // If the path to the destination square is clear, then check if it's 
    // possible to occupy said square
    if (pathClear)
    {
        // If the square isn't occupied, or it's occupied by an opponent's 
        // piece, then we can move there
        canMoveTo = (!location->isOccupied()) ||
            (location->getOccupant()->getColor() != _color);
    }

    return canMoveTo;
}


void Bishop::display(ostream & os)
{
    if (_color == WHITE_COLOR)
    {
        os << WHITE_BISHOP;
    }
    else
    {
        os << BLACK_BISHOP;
    }
}

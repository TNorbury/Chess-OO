/**
 * 1851366
 * Assignment 7
 * 2017-04-13
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
    return false;
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

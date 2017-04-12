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
    return 0;
}


bool Queen::canMoveTo(Square* location)
{
    return false;
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

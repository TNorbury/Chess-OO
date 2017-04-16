/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#include "King.h"
#include "Square.h"

 /**
  * King implementation
  */

// From the king's current location, these are the rank/file offsets of the 
// squares that the king can move to.
vector<pair<int, int>> King::_movementOffsets = { {-1, -1}, {-1, 0}, {-1, 1},
{0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

King::King(Square* location, string color) : RestrictedPiece(location, color)
{
}


int King::getValue()
{
    // King will never actually be "captured" so no need for a point value
    return 0;
}


void King::display(ostream & os)
{
    // Print out something different depending on the color of the piece
    if (_color == WHITE_COLOR)
    {
        os << WHITE_KING;
    }
    else
    {
        os << BLACK_KING;
    }
}

vector<pair<int, int>>& King::getMovementOffsets()
{
    return _movementOffsets;
}

#include "King.h"
#include "Square.h"

/**
 * King implementation
 */

 // From the king's current location, these are the rank/file offsets of the 
 // squares that the king can move to.
vector<pair<int, int>> King::_movementOffsets = { {-1, -1}, {-1, 0}, {-1, 1},
{0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

King::King(Square* location, string color)
{
    _location = location;
    _color = color;

    // Tell the square that it's now occupied
    _location->setOccupant(this);
}


int King::getValue()
{
    return 0;
}


bool King::canMoveTo(Square* location)
{
    return false;
}

void King::display(ostream & os)
{
    // Print out something different depending on the color of the piece
    if (_color == "White")
    {
        os << "WK";
    }
    else
    {
        os << "BK";
    }
}

vector<pair<int, int>>& King::getMovementOffsets()
{
    return _movementOffsets;
}

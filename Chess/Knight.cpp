#include "Knight.h"
#include "Square.h"

 /**
  * Knight implementation
  */

Knight::Knight(Square & location, string color)
{
    _location = &location;
    _color = color;

    // Tell the square that it's now occupied
    _location->setOccupant(this);
}

/**
   * @return int
   */
int Knight::getValue()
{
    return 0;
}

/**
 * @param location
 * @return bool
 */
bool Knight::canMoveTo(Square& location)
{
    return false;
}

void Knight::display(ostream & os)
{
    // Print out something different depending on the color of the piece
    if (_color == "White")
    {
        os << "WN";
    }
    else
    {
        os << "BN";
    }
}

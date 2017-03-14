#include "King.h"
#include "Square.h"

 /**
  * King implementation
  */


King::King(Square & location, string color)
{
    _location = &location;
    _color = color;

    // Tell the square that it's now occupied
    _location->setOccupant(this);
}

/**
   * @return int
   */
int King::getValue()
{
    return 0;
}

/**
 * @param location
 * @return bool
 */
bool King::canMoveTo(Square& location)
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

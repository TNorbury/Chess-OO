#include "Rook.h"
#include "Square.h"

 /**
  * Rook implementation
  */

  /**
   * Create a new Rook at the given square and for the specified color
   * @param location The square that the rook will sit on
   * @param color The color of the piece
   */
Rook::Rook(Square& location, string color)
{
    _location = &location;
    _color = color;

    // Tell the square that it's now occupied
    _location->setOccupant(this);
}

/**
   * @return int
   */
int Rook::getValue()
{
    return 0;
}

/**
 * @param location
 * @return bool
 */
bool Rook::canMoveTo(Square& location)
{
    return false;
}

void Rook::display(ostream & os)
{
    // Print out something different depending on the color of the piece
    if (_color == "White")
    {
        os << "WR";
    }
    else
    {
        os << "BR";
    }
}

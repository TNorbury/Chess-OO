#include "Rook.h"
#include "Square.h"

 /**
  * Rook implementation
  */

  /**
   * Create a new Rook at the given square and for the specified color
   * @param location The square that the rook will set on
   * @param color The color of the piece
   */
Rook::Rook(Square& location, string color)
{
    _location = &location;
    _color = color;
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
}

#include "Bishop.h"
#include "Square.h"

 /**
  * Bishop implementation
  */

  /**
   * Create a new King at the given square and for the specified color
   * @param location The square that the King will set on
   * @param color The color of the piece
   */
Bishop::Bishop(Square & location, string color)
{
    _location = &location;
    _color = color;
}

/**
   * @return int
   */
int Bishop::getValue()
{
    return 0;
}

/**
 * @param location
 * @return bool
 */
bool Bishop::canMoveTo(Square& location)
{
    return false;
}

void Bishop::display(ostream & os)
{
}

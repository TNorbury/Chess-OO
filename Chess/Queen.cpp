#include "Queen.h"
#include "Square.h"

 /**
  * Queen implementation
  */

  /**
   * Create a new Queen at the given square and for the specified color
   * @param location The square that the Queen will set on
   * @param color The color of the piece
   */
Queen::Queen(Square & location, string color)
{
    _location = &location;
    _color = color;
}

/**
   * @return int
   */
int Queen::getValue()
{
    return 0;
}

/**
 * @param location
 * @return bool
 */
bool Queen::canMoveTo(Square& location)
{
    return false;
}

void Queen::display(ostream & os)
{
}

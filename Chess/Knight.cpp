/**
 * Project Chess
 * @author Brian R. Snider
 */


#include "Knight.h"
#include "Square.h"

 /**
  * Knight implementation
  */

  /**
   * Create a new Rook at the given square and for the specified color
   * @param location The square that the rook will set on
   * @param color The color of the piece
   */
Knight::Knight(Square & location, string color)
{
    _location = &location;
    _color = color;
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
}

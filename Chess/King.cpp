/**
 * Project Chess
 * @author Brian R. Snider
 */


#include "King.h"
#include "Square.h"

 /**
  * King implementation
  */

  /**
   * Create a new King at the given square and for the specified color
   * @param location The square that the King will set on
   * @param color The color of the piece
   */
King::King(Square & location, string color)
{
    _location = &location;
    _color = color;
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
}

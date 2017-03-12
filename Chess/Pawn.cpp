#include <iostream>
#include "Pawn.h"
#include "Square.h"

 /**
  * Pawn implementation
  */

  /**
   * Create a new Pawn at the given square and for the specified color
   * @param location The square that the Pawn will set on
   * @param color The color of the piece
   */
Pawn::Pawn(Square & location, string color)
{
    _location = &location;
    _color = color;
}

/**
   * @return int
   */
int Pawn::getValue()
{
    return 0;
}

/**
 * @param location
 * @return bool
 */
bool Pawn::canMoveTo(Square& location)
{
    return false;
}

/**
 * @param os
 */
void Pawn::display(ostream& os)
{

}
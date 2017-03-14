#include <iostream>
#include "Pawn.h"
#include "Square.h"

 /**
  * Pawn implementation
  */


Pawn::Pawn(Square & location, string color)
{
    _location = &location;
    _color = color;

    // Tell the square that it's now occupied
    _location->setOccupant(this);
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
    // Print out something different depending on the color of the piece
    if (_color == "White")
    {
        os << "WP";
    }
    else
    {
        os << "BP";
    }
}
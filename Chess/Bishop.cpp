#include "Bishop.h"
#include "Square.h"

 /**
  * Bishop implementation
  */


Bishop::Bishop(Square & location, string color)
{
    _location = &location;
    _color = color;

    // Tell the square that it's now occupied
    _location->setOccupant(this);
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
    if (_color == "White")
    {
        os << "WB";
    }
    else
    {
        os << "BB";
    }
}

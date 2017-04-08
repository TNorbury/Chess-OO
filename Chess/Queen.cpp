#include "Queen.h"
#include "Square.h"

 /**
  * Queen implementation
  */


Queen::Queen(Square* location, string color)
{
    _location = location;
    _color = color;

    // Tell the square that it's now occupied
    _location->setOccupant(this);
}


int Queen::getValue()
{
    return 0;
}


bool Queen::canMoveTo(Square* location)
{
    return false;
}

void Queen::display(ostream & os)
{
    // Print out something different depending on the color of the piece
    if (_color == "White")
    {
        os << "WQ";
    }
    else
    {
        os << "BQ";
    }
}

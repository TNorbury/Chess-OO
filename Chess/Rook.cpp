#include "Rook.h"
#include "Square.h"

 /**
  * Rook implementation
  */


Rook::Rook(Square& location, string color)
{
    _location = &location;
    _color = color;

    // Tell the square that it's now occupied
    _location->setOccupant(this);
}


int Rook::getValue()
{
    return 0;
}


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

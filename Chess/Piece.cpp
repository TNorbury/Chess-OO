#include "Piece.h" 
#include "Square.h"
#include "Player.h"

 /**
  * Piece implementation
  */



int Piece::getValue()
{
    return 0;
}


string Piece::getColor()
{
    return _color;
}


Square& Piece::getLocation()
{
    return *_location;
}


void Piece::setLocation(Square* location)
{
    _location = location;
}


bool Piece::isOnSquare()
{
    return false;
}


bool Piece::canMoveTo(Square& location)
{
    return false;
}


bool Piece::moveTo(Square& location, Player& byPlayer)
{
    return false;
}


void Piece::display(ostream& os)
{

}


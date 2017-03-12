/**
 * Project Chess
 * @author Brian R. Snider
 */


#include "Piece.h" 
#include "Square.h"
#include "Player.h"

 /**
  * Piece implementation
  */


  /**
   * @return int
   */
int Piece::getValue()
{
    return 0;
}

/**
 * @return string
 */
string Piece::getColor()
{
    return _color;
}

/**
 * @return Square&
 */
Square& Piece::getLocation()
{
    return *_location;
}

/**
 * @param location
 */
void Piece::setLocation(Square* location)
{
    _location = location;
}

/**
 * @return bool
 */
bool Piece::isOnSquare()
{
    return false;
}

/**
 * @param location
 * @return bool
 */
bool Piece::canMoveTo(Square& location)
{
    return false;
}

/**
 * @param location
 * @param byPlayer
 * @return bool
 */
bool Piece::moveTo(Square& location, Player& byPlayer)
{
    return false;
}

/**
 * @param os
 */
void Piece::display(ostream& os)
{

}
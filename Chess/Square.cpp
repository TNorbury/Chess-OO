/**
 * Project Chess
 * @author Brian R. Snider
 */


#include "Square.h"
#include "Piece.h"

 /**
  * Square implementation
  */


  /**
   * @param rank
   * @param file
   */
Square::Square(int rank, int file)
{

}

/**
 * @return int
 */
int Square::getRank()
{
    return rank;
}

/**
 * @return int
 */
int Square::getFile()
{
    return file;
}

/**
 * @return bool
 */
bool Square::isOccupied()
{
    return false;
}

/**
 * @return Piece&
 */
Piece& Square::getOccupant()
{
    return *occupant;
}

/**
 * @param occupant
 */
void Square::setOccupant(Piece* occupant)
{

}

 Square::Square()
 {
 }

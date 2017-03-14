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
    _rank = rank;
    _file = file;
}

/**
 * @return int
 */
int Square::getRank()
{
    return _rank;
}

/**
 * @return int
 */
int Square::getFile()
{
    return _file;
}

/**
 * @return bool
 */
bool Square::isOccupied()
{
    return (_occupant != NULL);
}

/**
 * @return Piece&
 */
Piece& Square::getOccupant()
{
    return *_occupant;
}

/**
 * @param occupant
 */
void Square::setOccupant(Piece* occupant)
{
    _occupant = occupant;
}

 Square::Square()
 {
 }

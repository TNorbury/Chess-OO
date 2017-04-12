/**
 * 1851366
 * Assignment 7
 * 2017-04-13
 */

#include "Square.h"
#include "Piece.h"

 /**
  * Square implementation
  */

Square::Square(int rank, int file)
{
    _rank = rank;
    _file = file;
}


int Square::getRank()
{
    return _rank;
}


int Square::getFile()
{
    return _file;
}


bool Square::isOccupied()
{
    return (_occupant != NULL);
}


Piece& Square::getOccupant()
{
    return *_occupant;
}


void Square::setOccupant(Piece* occupant)
{
    _occupant = occupant;
}

bool Square::operator==(Square& otherSquare)
{
    // If the rank and file are the same, then the squares are equal
    return ((_rank == otherSquare.getRank())
        && (_file == otherSquare.getFile()));
}

Square::Square()
{
}

#include "Board.h"
#include "Piece.h" 
#include "Player.h"
#include "Square.h"

/**
 * Piece implementation
 */


string Piece::getColor()
{
    return _color;
}


Square* Piece::getLocation()
{
    return _location;
}


void Piece::setLocation(Square* location)
{
    _location = location;
}


bool Piece::isOnSquare()
{
    return false;
}


bool Piece::canMoveTo(Square* location)
{
    bool canMoveTo = false;

    // Get the movement offsets of this piece
    vector<pair<int, int>> movementOffsets = getMovementOffsets();

    // Iterate over each pair in the vector, checking each offset until either 
    // a valid square is found, or all offsets have been checked.
    for (auto iter = movementOffsets.begin(); iter != movementOffsets.end()
        && !canMoveTo; ++iter)
    {
        canMoveTo = checkSquare(_location->getRank() + iter->first, 
            _location->getFile() + iter->second, location);
    }

    return canMoveTo;
}


bool Piece::moveTo(Square* location, Player& byPlayer)
{
    // If the square is occupied, then capture the piece that currently occupies
    // it
    if (location->isOccupied())
    {
        // Have the player making the move capture the piece, and then remove 
        // it from the board
        byPlayer.capture(location->getOccupant());
    }

    // Remove the piece from its current spot on the board
    getLocation()->setOccupant(NULL);

    // Tell the piece about the location is now occupies
    setLocation(location);

    // Move the piece to its new location on the board
    location->setOccupant(this);

    return true;
}


vector<pair<int, int>>& Piece::getMovementOffsets()
{
    return _movementOffsets;
}

/**
 * Checks if the square at the given rank and file is the same as the square
 * the piece is trying to move to, and if that square to valid to move to.
 *
 * @param rank The rank of the square to check
 * @param file The file of the square to check
 * @param toMoveTo The square that the piece is trying to move to.
 * @return True if the square is valid to move to, otherwise false.
 */
bool Piece::checkSquare(int rank, int file, Square* toMoveTo)
{
    bool squareValid = false;

    // Make sure that the given rank and file is in bounds
    if (Board::inBounds(rank, file))
    {
        // If the square at the given rank and file is the same as the square 
        // the piece wants to move to, then check its occupancy
        if (Board::getInstance().getSquareAt(rank, file) == toMoveTo)
        {
            // If the square isn't occupied OR it's occupied by an opponent's 
            // piece, then we can move there
            squareValid = (!Board::getInstance().getSquareAt(rank, file)
                ->isOccupied()) ||
                (Board::getInstance().getSquareAt(rank, file)->getOccupant()
                    .getColor() != _color);
        }
    }

    return squareValid;
}


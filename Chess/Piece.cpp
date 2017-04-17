/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#include "Board.h"
#include "Game.h"
#include "Piece.h" 
#include "Player.h"
#include "Square.h"

 /**
  * Piece implementation
  */

Piece::Piece(Square * location, string color)
{
    _location = location;
    _color = color;

    // Tell the square that it's now occupied
    _location->setOccupant(this);
}

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
    Piece* toBeCaptured = NULL;
    bool capturedPiece = false;
    bool inCheck;

    // Make note of this piece's original location, in case it needs to be 
    // reset.
    Square* originalLocation = _location;

    // If the square is occupied, then capture the piece that currently
    // occupies it
    if (location->isOccupied())
    {
        // Make note of the piece that needs to be captured, in case we need to 
        // reset the board in the event of a check
        toBeCaptured = location->getOccupant();
        toBeCaptured->setLocation(NULL);
        location->setOccupant(NULL);
        capturedPiece = true;
    }

    // Remove the piece from its current spot on the board
    getLocation()->setOccupant(NULL);

    // Tell the piece about the location is now occupies
    setLocation(location);

    // Move the piece to its new location on the board
    location->setOccupant(this);

    // Now check if the move would put the moving player in check.
    inCheck = Game::isInCheck(&byPlayer);

    // If the move doesn't put the moving player into check, and there is a 
    // piece to be captured, then go ahead and capture the piece that 
    // originally occupied this square
    if (!inCheck && capturedPiece)
    {
        byPlayer.capture(toBeCaptured);
    }

    // Otherwise, if the move would put the player into check then "reset" the 
    // board to its setup before this method.
    else if (inCheck)
    {
        // Remove this piece from the destination location
        location->setOccupant(NULL);

        // If there was a piece occupying the square originally, "reset" it to 
        // the square
        if (capturedPiece)
        {
            toBeCaptured->setLocation(location);
            location->setOccupant(toBeCaptured);
        }

        // Reset this piece to its original position
        setLocation(originalLocation);
        originalLocation->setOccupant(this);
    }

    // If this move didn't put the player in check, then it was a valid move.
    return !(inCheck);
}


vector<pair<int, int>>& Piece::getMovementOffsets()
{
    return _movementOffsets;
}

/**
 * Checks if the square at the given rank and file is the same as the square
 * the piece is trying to move to, and if that square is valid to move to.
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
                    ->getColor() != _color);
        }
    }

    return squareValid;
}


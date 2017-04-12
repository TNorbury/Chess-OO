/**
 * 1851366
 * Assignment 7
 * 2017-04-13
 */

#include "Pawn.h"
#include "Square.h"
#include "Board.h"

 /**
  * Pawn implementation
  */

Pawn::Pawn(Square* location, string color) : RestrictedPiece(location, color)
{
    // Set the rank modifier based upon the pawn's color
    if (color == WHITE_COLOR)
    {
        _rankModifier = -1;
    }
    else
    {
        _rankModifier = 1;
    }
}


int Pawn::getValue()
{
    return 0;
}


bool Pawn::canMoveTo(Square* location)
{
    bool canMoveTo = false;
    int rank = _location->getRank();
    int file = _location->getFile();

    // Checking the square immediately in front of the pawn
    rank = _location->getRank() + (1 * _rankModifier);
    canMoveTo = checkFront(rank, file, location);

    // Check the squares to the immediate diagonals of the pawn
    // Only check the diagonal if the pawn hasn't found a square to move to
    if (!canMoveTo)
    {
        // Start by checking the left (if white, otherwise it's the right) 
        // diagonal
        rank = _location->getRank() + (1 * _rankModifier);
        file = _location->getFile() - 1;
        canMoveTo = checkDiagonal(rank, file, location);
    }

    // Only check the other diagonal if the pawn hasn't found a square to move 
    // to
    if (!canMoveTo)
    {
        // Now check the other diagonal (right if white, otherwise left).
        rank = _location->getRank() + (1 * _rankModifier);
        file = _location->getFile() + 1;
        canMoveTo = checkDiagonal(rank, file, location);
    }

    // If the pawn hasn't moved yet and the pawn hasn't found a square then 
    // check the square that is two squares in front of it
    if (!hasMoved() && !canMoveTo)
    {
        rank = _location->getRank() + (2 * _rankModifier);
        file = _location->getFile();
        canMoveTo = checkFront(rank, file, location);
    }

    return canMoveTo;
}


void Pawn::display(ostream& os)
{
    // Print out something different depending on the color of the piece
    if (_color == WHITE_COLOR)
    {
        os << WHITE_PAWN;
    }
    else
    {
        os << BLACK_PAWN;
    }
}


/**
 * Checks if the squares to diagonal of the pawn are valid
 *
 * @param rank The Rank of the diagonal
 * @param file The File of the diagonal
 * @param location The square that the pawn wants to move to.
 * @return True if the diagonal is valid. Otherwise false.
 */
bool Pawn::checkDiagonal(int rank, int file, Square* location)
{
    bool diagonalValid = false;

    // Ensure that the rank and file are in bounds
    if (Board::inBounds(rank, file))
    {
        // If the diagonal square is the same as the square to check, then 
        // check if it's occupied
        if (Board::getInstance().getSquareAt(rank, file) == location)
        {
            // If the square is occupied by an opponent, then the pawn can move
            // there (and capture the currently occupying piece)
            diagonalValid = ((Board::getInstance().getSquareAt(rank, file)
                ->isOccupied()) && (Board::getInstance().getSquareAt(rank, file)
                    ->getOccupant().getColor() != _color));
        }
    }

    return diagonalValid;
}

/**
* Checks if the squares to front of the pawn are valid
*
* @param rank The Rank of the square
* @param file The File of the square
* @param location The square that the pawn wants to move to.
* @return True if the square is valid to move to. Otherwise false.
*/
bool Pawn::checkFront(int rank, int file, Square* location)
{
    bool frontValid = false;

    // Make sure that the rank is in bounds. If it is then get the square
    if (Board::inBounds(rank, file))
    {
        // If the square right in front of the pawn is the same as the given 
        // location, then check if it's occupied.
        if (Board::getInstance().getSquareAt(rank, file) == location)
        {
            // If the square isn't occupied and the path to the square is clear
            // then the pawn can move there
            frontValid = (!Board::getInstance().getSquareAt(rank, file)
                ->isOccupied())
                && Board::getInstance().isClearFile(_location, location);
        }
    }

    return frontValid;
}

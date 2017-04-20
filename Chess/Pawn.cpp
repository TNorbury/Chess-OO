/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#define BOARD_TOP 0
#define BOARD_BOTTOM 7

#include "Board.h"
#include "Game.h"
#include "Pawn.h"
#include "Square.h"
#include "Queen.h"

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
    // Value for chess pieces taken from http://chess.stackexchange.com/a/4218
    return 1;
}


bool Pawn::canMoveTo(Square* location)
{
    bool canMoveTo = false;
    int rank;
    int file;

    // If the pawn isn't delegated, then check for valid movement based on pawn
    // rules
    if (_delegate == NULL)
    {
        rank = _location->getRank();
        file = _location->getFile();

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

        // Only check the other diagonal if the pawn hasn't found a square to 
        // move to
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
    }

    // Otherwise, defer movement checking to the delegate
    else
    {
        canMoveTo = _delegate->canMoveTo(location);
    }

    return canMoveTo;
}


bool Pawn::moveTo(Square* location, Player& byPlayer)
{
    bool canMove;
    bool endReached = false;

    // Since a pawn is being moved, tell the game to reset the turn counter.
    Game::resetTurnCount();

    if (_delegate != NULL)
    {
        // Defer movement to RestrictedPiece
        canMove = _delegate->moveTo(location, byPlayer);
    }
    else
    {
        canMove = RestrictedPiece::moveTo(location, byPlayer);
    }

    // If the move was successful and the pawn hasn't been delegated yet, see 
    // if the pawn reached the end of the board
    if (canMove && _delegate == NULL)
    {
        if (_color == WHITE_COLOR && _location->getRank() == BOARD_TOP)
        {
            endReached = true;
        }
        else if (_color == BLACK_COLOR && _location->getRank() == BOARD_BOTTOM)
        {
            endReached = true;
        }

        // If the end of the board was reached, then create a new Queen 
        // delegate
        if (endReached)
        {
            // Create a new queen at the location of the pawn.
            _delegate = new Queen(_location, _color);
        }
    }

    // Otherwise, if the move was successful, and the pawn has a delegate, then 
    // also update the pawns's location
    else if (canMove && _delegate != NULL)
    {
        setLocation(location);
    }

    return canMove;
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
        if (Board::getInstance()->getSquareAt(rank, file) == location)
        {
            // If the square is occupied by an opponent, then the pawn can move
            // there (and capture the currently occupying piece)
            diagonalValid = ((Board::getInstance()->getSquareAt(rank, file)
                ->isOccupied()) &&
                (Board::getInstance()->getSquareAt(rank, file)->getOccupant()
                    ->getColor() != _color));
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
        if (Board::getInstance()->getSquareAt(rank, file) == location)
        {
            // If the square isn't occupied and the path to the square is clear
            // then the pawn can move there
            frontValid = (!Board::getInstance()->getSquareAt(rank, file)
                ->isOccupied())
                && Board::getInstance()->isClearFile(_location, location);
        }
    }

    return frontValid;
}

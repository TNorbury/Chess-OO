/**
 * 1851366
 * Assignment 7
 * 2017-04-11
 */

#include <iostream>
#include "Board.h"
#include "Square.h"
#include "Piece.h"

 /**
  * Board implementation
  */

  // Initialize the board
Board& Board::_instance = *(new Board());

Board::Board()
{
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            _boardSquares[i][j] = (new Square(i, j));
        }
    }
}


Board& Board::getInstance()
{
    return _instance;
}


int Board::getDimensions()
{
    return Board::DIMENSION;
}


bool Board::inBounds(int rank, int file)
{
    return ((rank >= 0) && (rank < DIMENSION) && (file >= 0)
        && (file < DIMENSION));
}


Square* Board::getSquareAt(int rank, int file)
{
    return _boardSquares[rank][file];
}


bool Board::isClearRank(Square* from, Square* to)
{
    bool isClear = false;
    bool endOfPath = false;
    int verticalModifier;

    // This will keep track of the square we're currently looking as we walk 
    // the path. We'll start at the from square
    Square* squareOnPath = from;

    // Set the vertical modifier depending on if the destination square is 
    // above or below the source square
    // If from is below to, then we need to move up
    if (from->getRank() > to->getRank())
    {
        verticalModifier = -1;
    }

    // Otherwise, we need to move down
    else
    {
        verticalModifier = 1;
    }

    // Walk a vertical path along the board starting at from and going until 
    // either an obstacle is found, or to is reached
    while (!endOfPath)
    {
        // See if moving vertically one square would still be on the board, 
        // if it is, then get the next square on the path
        if (Board::inBounds(squareOnPath->getRank() + (1 * verticalModifier),
            squareOnPath->getFile()))
        {
            squareOnPath = Board::getInstance().getSquareAt(
                squareOnPath->getRank() + (1 * verticalModifier),
                squareOnPath->getFile());

            // Check to see if this square is the one we're looking for. If it 
            // is, then we can stop walking the path
            if (squareOnPath == to)
            {
                endOfPath = true;
                isClear = true;
            }

            // If it's not the one we're looking for, check to see if it's 
            // occupied, which would mean that the path isn't clear
            else if (squareOnPath->isOccupied())
            {
                endOfPath = true;
            }
        }

        // Otherwise, if it's not in-bounds then we've reached the end of the 
        // path
        else
        {
            endOfPath = true;
        }
    }

    return isClear;
}


bool Board::isClearFile(Square* from, Square* to)
{
    bool isClear = false;
    bool endOfPath = false;
    int horizontalModifier;

    // This will keep track of the square we're currently looking as we walk 
    // the path. We'll start at the from square
    Square* squareOnPath = from;

    // Set the horizontal modifier depending on if the destination square is 
    // to the left or right of the source square
    // If "from" is to the right of "to" then we need to move to the left.
    if (from->getFile() > to->getFile())
    {
        horizontalModifier = -1;
    }

    // Otherwise, we move to the right.
    else
    {
        horizontalModifier = 1;
    }

    // Walk a horizontal path along the board starting at from and going until 
    // either an obstacle is found, or to is reached
    while (!endOfPath)
    {
        // See if moving horizontally one square would still be on the board, 
        // if it is then get the next square on the path
        if (Board::inBounds(squareOnPath->getRank(), squareOnPath->getFile()
            + (1 * horizontalModifier)))
        {
            squareOnPath = Board::getInstance().getSquareAt(
                squareOnPath->getRank(),
                squareOnPath->getFile() + (1 * horizontalModifier));

            // Check to see if this square is the one we're looking for. If it 
            // is then we can stop walking the path
            if (squareOnPath == to)
            {
                endOfPath = true;
                isClear = true;
            }

            // If it's not the one we're looking for, check to see if it's 
            // occupied, which would mean that the path isn't clear
            else if (squareOnPath->isOccupied())
            {
                endOfPath = true;
            }
        }

        // Otherwise, if it's not inbounds, then we've reach the end of the 
        // path
        else
        {
            endOfPath = true;
        }
    }

    return isClear;
}


bool Board::isClearDiagonal(Square* from, Square* to)
{
    bool isClear = false;
    return isClear;
}


void Board::display(ostream& os)
{
    // Start by printing the file letters at the top
    os << FILE << endl;

    // Print the dotted line at the top of the board
    os << BOARD_LINE << endl;

    // Iterate through all the rows on the board
    for (int i = 0; i < DIMENSION; i++)
    {
        // Print the Rank number of the board
        os << " " << DIMENSION - i << " |";

        // Iterate through all the columns within the row
        for (int j = 0; j < DIMENSION; j++)
        {
            os << " ";

            // If the board is occupied at the ith - jth square, then print out
            // what it's occupied by
            if (getSquareAt(i, j)->isOccupied())
            {
                getSquareAt(i, j)->getOccupant().display(os);
            }

            // Otherwise, just print whitespace
            else
            {
                os << "  ";
            }

            // Print the vertical bar on the right hand side of the square.
            os << " |";
        }

        // Print the Rank number again and then move to a new line.
        os << " " << DIMENSION - i << endl;

        // Print the line in between rows.
        os << BOARD_LINE << endl;
    }

    // Finally, print the file letters at the bottom of the board.
    os << FILE << endl;
}

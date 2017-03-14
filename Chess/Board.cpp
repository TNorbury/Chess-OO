#include <iostream>
#include "Board.h"
#include "Square.h"
#include "Piece.h"

/**
 * Board implementation
 */

Board& Board::instance = *(new Board());

/**
 * @return Board&
 */
Board& Board::getInstance()
{
    return instance;
}

int Board::getDimensions()
{
    return Board::DIMENSION;
}


Square& Board::getSquareAt(int rank, int file)
{
    return boardSquares[rank][file];
}

/**
 * @param from
 * @param to
 * @return bool
 */
bool Board::isClearRank(Square& from, Square& to)
{
    return false;
}

/**
 * @param from
 * @param to
 * @return bool
 */
bool Board::isClearFile(Square& from, Square& to)
{
    return false;
}

/**
 * @param from
 * @param to
 * @return bool
 */
bool Board::isClearDiagonal(Square& from, Square& to)
{
    return false;
}

/**
 * @param os
 */
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
            if (getSquareAt(i, j).isOccupied())
            {
                getSquareAt(i, j).getOccupant().display(os);
                //os << "PC";
            }

            // Otherwise, just print whitespace
            else
            {
                os << "  ";
            }

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


Board::Board()
{
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            boardSquares[i][j] = *(new Square(i, j));
        }
    }
}

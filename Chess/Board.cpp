#include <iostream>
#include "Board.h"
#include "Square.h"

 /**
  * Board implementation
  */

Board& Board::instance = Board();

  /**
   * @return Board&
   */
Board& Board::getInstance()
{
    Board();
    return instance;
}

int Board::getDimensions()
{
    return Board::DIMENSION;
}

/**
 * @param rank
 * @param file
 * @return Square&
 */
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

}


Board::Board()
{
    boardSquares[DIMENSION][DIMENSION];

    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
        {
            boardSquares[i][j] = *(new Square(i, j));
        }
    }
}

/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#include "Knight.h"
#include "Square.h"

 /**
  * Knight implementation
  */

  // From the knight's current location, these are the rank/file offsets of the 
  // squares that the knight can move to.
vector<pair<int, int>> Knight::_movementOffsets = { {-2, -1}, {-2, 1},
{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1} };


Knight::Knight(Square* location, string color) : Piece(location, color) {}


int Knight::getValue()
{
    // Value for chess pieces taken from http://chess.stackexchange.com/a/4218
    return 3;
}


void Knight::display(ostream & os)
{
    // Print out something different depending on the color of the piece
    if (_color == WHITE_COLOR)
    {
        os << WHITE_KNIGHT;
    }
    else
    {
        os << BLACK_KNIGHT;
    }
}

vector<pair<int, int>>& Knight::getMovementOffsets()
{
    return _movementOffsets;
}

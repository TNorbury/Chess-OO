/**
 * 1851366
 * Assignment 7
 * 2017-04-11
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


Knight::Knight(Square* location, string color)
{
    _location = location;
    _color = color;

    // Tell the square that it's now occupied
    _location->setOccupant(this);


}


int Knight::getValue()
{
    return 0;
}


void Knight::display(ostream & os)
{
    // Print out something different depending on the color of the piece
    if (_color == "White")
    {
        os << "WN";
    }
    else
    {
        os << "BN";
    }
}

vector<pair<int, int>>& Knight::getMovementOffsets()
{
    return _movementOffsets;
}

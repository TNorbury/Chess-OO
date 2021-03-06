/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#ifndef _KING_H
#define _KING_H

#define WHITE_KING "WK"
#define BLACK_KING "BK"

#include "RestrictedPiece.h"
class Square;

class King : public RestrictedPiece
{
public:

    /**
     * Create a new King at the given square and for the specified color
     * @param location The square that the King will sit on
     * @param color The color of the piece
     */
    King(Square* location, string color);

    /**
     * @return the value of the piece
     */
    int getValue();

    /**
     * Checks if the piece can move to the given square
     * @param location The square that the piece is checking if it can move to
     * @return true, if the piece can move to the given square, otherwise false
     */
    bool canMoveTo(Square* location);

    /**
     * Prints out the King
     * @param os The ostream that the King should be printed to.
     */
    void display(ostream& os);

    /**
     * @return A vector of the pairs of rank,file offsets that the king can
     * move to
     */
    vector<pair<int, int>>& getMovementOffsets();

private:
    static vector<pair<int, int>> _movementOffsets;
};

#endif //_KING_H
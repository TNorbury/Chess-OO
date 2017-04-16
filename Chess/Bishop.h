/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#ifndef _BISHOP_H
#define _BISHOP_H

#define WHITE_BISHOP "WB"
#define BLACK_BISHOP "BB"

#include "Piece.h"

class Bishop : public Piece
{
public:

    /**
     * Create a new Bishop at the given square and for the specified color
     * @param location The square that the Bishop will sit on
     * @param color The color of the piece
     */
    Bishop(Square* location, string color);

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
     * Prints out the Bishop
     * @param os The ostream that the bishop should be printed to.
     */
    void display(ostream& os);
};

#endif //_BISHOP_H
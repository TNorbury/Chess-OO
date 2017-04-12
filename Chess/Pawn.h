/**
 * 1851366
 * Assignment 7
 * 2017-04-13
 */

#ifndef _PAWN_H
#define _PAWN_H

#define WHITE_PAWN "WP"
#define BLACK_PAWN "BP"

#include "RestrictedPiece.h"
class Square;

class Pawn : public RestrictedPiece
{
public:

    /**
     * Create a new Pawn at the given square and for the specified color
     * @param location The square that the Pawn will sit on
     * @param color The color of the piece
     */
    Pawn(Square* location, string color);

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
     * Move the piece to the given location
     * @param location The location to be moved to
     * @param byPlayer The player making the move
     */
    bool moveTo(Square* location, Player& byPlayer);

    /**
     * Prints out the Pawn
     * @param os The ostream that the Pawn should be printed to.
     */
    void display(ostream& os);

private:
    Piece* delegate;

    // Since a pawn's movement is based upon its color, the rank movement needs
    // to be either positive (black) or negative (white) to ensure that the
    // pawn moves in the right direction
    int _rankModifier;

    bool checkDiagonal(int rank, int file, Square* location);
    bool checkFront(int rank, int file, Square* location);
};

#endif //_PAWN_H
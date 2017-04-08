#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "Piece.h"
class Square;


class Knight : public Piece
{
public:

    /**
     * Create a new Knight at the given square and for the specified color
     * @param location The square that the knight will sit on
     * @param color The color of the piece
     */
    Knight(Square* location, string color);
    
    /**
     * @return the value of the piece
     */
    int getValue();

    /**
     * Prints out the Knight
     * @param os The ostream that the Knight should be printed to.
     */
    void display(ostream& os);

    /**
     * @return A vector of the pairs of rank,file offsets that the Knight can
     * move to
     */
    vector<pair<int, int>>& getMovementOffsets();

private:
    static vector<pair<int, int>> _movementOffsets;
};

#endif //_KNIGHT_H
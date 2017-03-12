#ifndef _SQUARE_H
#define _SQUARE_H

 //#include "Piece.h"
class Piece;

class Square
{
public:

    /**
     * @param rank
     * @param file
     */
    Square(int rank, int file);

    int getRank();

    int getFile();

    bool isOccupied();

    Piece& getOccupant();

    /**
     * @param occupant
     */
    void setOccupant(Piece* occupant);

    Square();

private:
    int rank;
    int file;
    Piece* occupant;
};

#endif //_SQUARE_H
#ifndef _SQUARE_H
#define _SQUARE_H

class Piece;

class Square
{
public:

    /**
     * Creates a new square with the given rank and file
     * @param rank The rank of the square
     * @param file The file of the square
     */
    Square(int rank, int file);

    /**
     * @return The Rank of the square
     */
    int getRank();

    /**
     * @return The File of the square
     */
    int getFile();

    /**
     * @return true, if the square is occupied. Otherwise false
     */
    bool isOccupied();

    /**
     * @return The piece that currently occupies the square
     */
    Piece& getOccupant();

    /**
     * Sets the occupant of the square to the given piece
     * @param occupant The new occupant of the board
     */
    void setOccupant(Piece* occupant);


    /**
     * Compares two squares to one another
     * @param otherSquare The square to compare to
     * @return true if the two squares are equal, otherwise false.
     */
    bool operator==(Square& otherSquare);


    Square();
private:
    int _rank;
    int _file;
    Piece* _occupant;
};

#endif //_SQUARE_H
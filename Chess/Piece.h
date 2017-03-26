#ifndef _PIECE_H
#define _PIECE_H

#include <string>
#include <iostream>
class Square;
class Player;


using namespace std;


class Piece
{
public:

    /**
     * @return the value of the piece
     */
    virtual int getValue();

    /**
     * @return The piece's color
     */
    string getColor();

    /**
     * @return the piece's location
     */
    Square& getLocation();

    /**
     * Set the location of the piece to the given square
     * @param location The piece's new location
     */
    void setLocation(Square* location);

    /**
     * @return If the piece is currently on a square (i.e. in play)
     */
    bool isOnSquare();

    /**
     * Checks if the piece can move to the given square
     * @param location The square that the piece is checking if it can move to
     * @return true, if the piece can move to the given square, otherwise false
     */
    virtual bool canMoveTo(Square& location);

    /**
     * Move the piece to the given location 
     * @param location The location to be moved to
     * @param byPlayer The player making the move
     */
    virtual bool moveTo(Square& location, Player& byPlayer);

    /**
     * Prints out the piece
     * @param os The ostream that the piece will be output to.
     */
    virtual void display(ostream& os);
protected:
    string _color;
    Square* _location;
};

#endif //_PIECE_H
/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#ifndef _PIECE_H
#define _PIECE_H

#define WHITE_COLOR "White"
#define BLACK_COLOR "Black"

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "Board.h"
class Square;
class Player;

using namespace std;

class Piece
{
public:

    /**
     * Create a new Piece at the given square and for the specified color
     * @param location The square that the Piece will sit on
     * @param color The color of the piece
     */
    Piece(Square* location, string color);

    /**
     * @return the value of the piece
     */
    virtual int getValue() = 0;

    /**
     * @return The piece's color
     */
    string getColor();

    /**
     * @return the piece's location
     */
    Square* getLocation();

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
    virtual bool canMoveTo(Square* location);

    /**
     * Move the piece to the given location
     * @param location The location to be moved to
     * @param byPlayer The player making the move
     * @return True if the move was processed, otherwise false.
     */
    virtual bool moveTo(Square* location, Player& byPlayer);

    /**
     * Prints out the piece
     * @param os The ostream that the piece will be output to.
     */
    virtual void display(ostream& os) = 0;

protected:
    Square* _location;
    string _color;
    vector<pair<int, int>> _movementOffsets;

    virtual vector<pair<int, int>>& getMovementOffsets();
    bool checkSquare(int rank, int file, Square* toMoveTo);
};

#endif //_PIECE_H
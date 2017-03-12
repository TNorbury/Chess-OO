/**
 * Project Chess
 * @author Brian R. Snider
 */


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

    virtual int getValue();

    string getColor();

    Square& getLocation();

    /**
     * @param location
     */
    void setLocation(Square* location);

    bool isOnSquare();

    /**
     * @param location
     */
    virtual bool canMoveTo(Square& location);

    /**
     * @param location
     * @param byPlayer
     */
    bool moveTo(Square& location, Player& byPlayer);

    /**
     * @param os
     */
    virtual void display(ostream& os);
private:
    string color;
    Square* location;
};

#endif //_PIECE_H
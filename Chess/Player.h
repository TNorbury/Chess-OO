/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <set>
#include <string>
class King;
class Piece;

using namespace std;

class Player
{
public:

    /**
     * @param name The Player's name
     * @param king The player's king
     * @param pieces The set of pieces owned by this player
     */
    Player(string name, King* king, set<Piece*>& pieces);

    /**
     * @return the Player's name
     */
    string getName();

    /**
     * @return the Player's king
     */
    King* getKing();

    /**
     * @return the Player's pieces
     */
    set<Piece*>& getPieces();

    /**
     * Have the player make a move
     * @return True if the move was successful
     */
    bool makeMove(istream& is, ostream& os, ostream& err);

    /**
     * Capture the given piece
     * @param piece
     */
    void capture(Piece* piece);

    /**
     * Calculate the player's current score
     * @return the score
     */
    int calculateScore();
    
    /**
     * @return True if the player has resigned, otherwise false.
     */
    bool hasResigned();
    
    /**
     * Indicates that this player wishes to resign
     */
    void resign();

    Player();
private:
    string _name;
    King* _king;
    set<Piece*> _pieces;
    set<Piece*> _capturedPieces;
    bool _resigned = false;
    int parseRank(char inputCharacter, ostream& os);
    int parseFile(char inputCharacter, ostream& os);
};

#endif //_PLAYER_H
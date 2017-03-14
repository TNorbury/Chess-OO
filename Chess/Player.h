#ifndef _PLAYER_H
#define _PLAYER_H

#include <set>
#include <string>
class Piece;
class King;

using namespace std;

class Player
{
public:

    /**
     * @param name
     * @param king
     * @param pieces
     */
    Player(string name, King& king, set<Piece*>& pieces);

    string getName();

    King& getKing();

    set<Piece*>& getPieces();

    bool makeMove();

    /**
     * @param piece
     */
    void capture(Piece& piece);

    int calculateScore();

    Player();
private:
    string _name;
    King* _king;
    set<Piece*> _pieces;
    set<Piece*> _capturedPieces;
};

#endif //_PLAYER_H
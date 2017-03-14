#ifndef _GAME_H
#define _GAME_H

#include <set>
#include "Piece.h"
#include "King.h"
class Player;
class Board;

// The "File" letters and their numerical (0-based) equivalent.
#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7

// The "Rank" numbers and their numerical (0-based) equivalent
#define EIGHT 0
#define SEVEN 1
#define SIX   2
#define FIVE  3
#define FOUR  4
#define THREE 5
#define TWO   6
#define ONE   7

#define WHITE 0
#define BLACK 1

class Game
{
public:

    static void initialize();

    static Player& getNextPlayer();

    /**
     * @param player
     */
    static Player& getOpponentOf(Player& player);

private:

    /**
     * Places all of the black pieces on the board in their initial state
     *
     * @param board The board where the pieces will be placed
     *
     * @return The black King
     */
    static King& PlaceBlackPieces(Board& board);

    /**
     * Places all of the white pieces on the board in their initial state
     *
     * @param board The board where the pieces will be placed
     *
     * @return The white King
     */
    static King& PlaceWhitePieces(Board& board);
    static Player* _player[2];
    static int _currentPlayer;
    static Board& _board;
    static set<Piece*> _whitePieces;
    static set<Piece*> _blackPieces;
};

#endif //_GAME_H
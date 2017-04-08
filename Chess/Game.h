/**
 * 1851366
 * Assignment 7
 * 2017-04-11
 */


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

    /**
     * Set up a new game of chess.
     */
    static void initialize();


    /**
     * Gets the player that is supposed to go next.
     */
    static Player& getNextPlayer();

    /**
     * Gets the opponent of the given player
     * @param player
     */
    static Player& getOpponentOf(Player& player);

    /**
     * Gets the current player
     * @return The current player
     */
    static Player* getCurrentPlayer();

private:
    static Player* _white;
    static Player* _black;
    static Player* _currentPlayer;
    static Board& _board;
    static set<Piece*> _whitePieces;
    static set<Piece*> _blackPieces;

    static King& PlaceBlackPieces(Board& board);
    static King& PlaceWhitePieces(Board& board);
};

#endif //_GAME_H
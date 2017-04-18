/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#ifndef _GAME_H
#define _GAME_H

#include <set>
#include "King.h"
#include "Piece.h"
class Board;
class Player;

// The "Rank" letters and their numerical (0-based) equivalent.
#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7

// The "File" numbers and their numerical (0-based) equivalent
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

#define MAX_TURNS 50

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
    static Player* getNextPlayer();

    /**
     * Gets the opponent of the given player
     * @param player
     */
    static Player* getOpponentOf(Player* player);

    /**
     * Gets the current player
     * @return The current player
     */
    static Player* getCurrentPlayer();

    /**
     * Tells the game that a turn was performed. Returns true if the maximum
     * number of turns has been reached.
     * @return True, if the max number of turns have been performed
     */
    static bool turnPerformed();

    /**
     * Reset the turn counter to 0
     */
    static void resetTurnCount();

    /**
     * Checks if the given player is in check.
     * @param player The player to check if they're in check
     * @return True if the given player is in check, otherwise false.
     */
    static bool isInCheck(Player* player);

    /**
     * Checks if the given player is in checkmate.
     * @param player The player to check if they're in checkmate
     * @return True if the given player is in checkmate, otherwise false.
     */
    static bool isInCheckmate(Player* player);

    /**
     * @return True if a draw was offered, otherwise false
     */
    static bool drawOffered();

    /**
     * @return True if the draw was accepted, otherwise false
     */
    static bool drawAccepted();

    /**
     * Offer to end the game in a draw
     */
    static void offerDraw();

    /**
     * Reject an offer to end the game in a draw
     */
    static void rejectDraw();

    /**
     * Accept an offer to end the game in a draw
     */
    static void acceptDraw();

private:
    static Player* _white;
    static Player* _black;
    static Player* _currentPlayer;
    static Board& _board;
    static set<Piece*> _whitePieces;
    static set<Piece*> _blackPieces;
    static int _turnCounter;
    static bool _drawOffered;
    static bool _drawAccepted;

    static King* PlaceBlackPieces(Board& board);
    static King* PlaceWhitePieces(Board& board);
};

#endif //_GAME_H
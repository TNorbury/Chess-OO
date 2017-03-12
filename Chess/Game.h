/**
 * Project Chess
 * @author Brian R. Snider
 */


#ifndef _GAME_H
#define _GAME_H

 //#include "Player.h"
class Player;
class Board;

// The "rank" letters and their numerical (0-based) equivalent.
#define a 0
#define b 1
#define c 2
#define d 3
#define e 4
#define f 5
#define g 6
#define h 7

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
    static void PlaceBlackPieces(Board& board);
    static void PlaceWhitePieces(Board& board);
    static Player _player[2];
    static int _currentPlayer;
    static Board& _board;
};

#endif //_GAME_H
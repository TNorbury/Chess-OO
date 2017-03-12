/**
 * Project Chess
 * @author Brian R. Snider
 */


#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Board.h"

 /**
  * Game implementation
  */

Player Game::_player[2];
Board& Game::_board = Board::getInstance();

int main()
{
    // Initialize the game to start off with
    Game::initialize();
}


void Game::initialize()
{
    // Start by placing all the necessary pieces on the board.
}

/**
 * @return Player&
 */
Player& Game::getNextPlayer()
{
    // Actually get the next player 
    return _player[0];
}

/**
 * @param player
 * @return Player&
 */
Player& Game::getOpponentOf(Player& player)
{
    // Actually get the next player
    return _player[0];
}

void Game::PlaceBlackPieces(Board & board)
{
}

void Game::PlaceWhitePieces(Board & board)
{
}

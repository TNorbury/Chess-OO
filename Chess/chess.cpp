/**
 * 1851366
 * Assignment 7
 * 2017-04-08
 */

#include "Game.h"
#include "Player.h"
#include "Board.h"

int main()
{
    // When one of the two kings is checkmated/captured, then the game is over.
    bool gameOver = false;
    int moveCounter = 0;

    // Initialize the game
    Game::initialize();

    // Get the current player.
    Player* currentPlayer = Game::getCurrentPlayer();

    // While the game is not over, continue to alternate players and process 
    // their input
    while (!gameOver)
    {
        // Try to get the current player to enter a valid move
        while (!currentPlayer->makeMove(cin, cout, cerr))
        {
            cerr << "Input should be structured like:" << endl <<
                "FileRank FileRank" << endl << "Rank = 1-8. File = a-h" 
                << endl;
        }

        // Since a piece was moved on the board, display it again to reflect 
        // the changes
        Board::getInstance().display(cout);
        
        // If 10 moves have been played, then end the game
        if (++moveCounter == 10)
        {
            gameOver = true;
        }

        // Now get the next player
        currentPlayer = &Game::getNextPlayer();
    }
}
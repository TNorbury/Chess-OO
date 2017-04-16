/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#include "Board.h"
#include "Game.h"
#include "Player.h"

int main()
{
    // When one of the two kings is checkmated/captured, then the game is over.
    bool gameOver = false;

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
            cerr << endl << "Input should be structured like:" << endl <<
                "FileRank FileRank" << endl << "Rank = 1-8. File = a-h"
                << endl << endl;
        }

        // Since a piece was moved on the board, display it again to reflect 
        // the changes
        Board::getInstance().display(cout);

        // Tell the game that a turn was performed. If the maximum number of 
        // turns were performed, then the game is over
        if (Game::turnPerformed())
        {
            gameOver = true;
            cout << endl << MAX_TURNS << " turns were performed without a piece"
                << " being captured or a pawn moving, so the game is a DRAW!"
                << endl;
        }
        
        // Check if this move put the opposing player in check. If it did, then 
        // print out a message
        if (Game::isInCheck(Game::getOpponentOf(currentPlayer)))
        {
            cout << endl << Game::getOpponentOf(currentPlayer)->getName() << 
            " is now in CHECK" << endl;
        }

        // Now get the next player
        currentPlayer = Game::getNextPlayer();
    }
}
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
    bool validMove;

    // Initialize the game
    Game::initialize();

    // Get the current player.
    Player* currentPlayer = Game::getCurrentPlayer();

    // While the game is not over, continue to alternate players and process 
    // their input
    while (!gameOver)
    {
        validMove = false;

        // Check if the current player is in checkmate before asking for a move
        if (Game::isInCheckmate(currentPlayer))
        {
            cout << currentPlayer->getName() << " is in checkmate" << endl
                << Game::getOpponentOf(currentPlayer)->getName() << " is the"
                << " winner!" << endl;
            validMove = true;
            gameOver = true;
        }
        else
        {
            // Since a piece was moved on the board, display it again to 
            // reflect the changes
            Board::getInstance()->display(cout);
            
        }

        // Try to get the current player to enter a valid move
        while (!validMove)
        {
            validMove = currentPlayer->makeMove(cin, cout, cerr);

            // If the move wasn't valid, but the current player didn't resign, 
            // then print out an error message
            if (!validMove && !currentPlayer->hasResigned())
            {
                cerr << endl << "Input should be structured like:" << endl <<
                    "RankFile RankFile" << endl << "Rank = a-h. File = 1-8"
                    << endl << endl;
            }

            // Otherwise, if the player did resign, then the game is over
            else if (currentPlayer->hasResigned())
            {
                validMove = true;
                gameOver = true;
                cout << endl << currentPlayer->getName() << " has resigned!"
                    << endl << Game::getOpponentOf(currentPlayer)->getName()
                    << " is the winner!" << endl;
            }

            // If a draw was accepted then the game is over
            else if (Game::drawAccepted())
            {
                validMove = true;
                gameOver = true;
                cout << endl << "Both players indicated that they wanted a "
                    << "draw so the game is now over with no winner" << endl;
            }
        }

        if (!gameOver)
        {

            // Tell the game that a turn was performed. If the maximum number 
            // of turns were performed, then the game is over
            if (Game::turnPerformed())
            {
                gameOver = true;
                cout << endl << MAX_TURNS << " turns were performed without a "
                    << "piece being captured or a pawn moving, so the game is "
                    << "a DRAW!" << endl;
            }

            // Check if this move put the opposing player in check. If it did, 
            // then print out a message
            if (Game::isInCheck(Game::getOpponentOf(currentPlayer)))
            {
                cout << endl << Game::getOpponentOf(currentPlayer)->getName()
                    << " is now in CHECK" << endl;

                // Indicate that this player is now in check
                Game::getOpponentOf(currentPlayer)->setCheck(true);
            }

            // Otherwise, this player is no longer in check
            else
            {
                Game::getOpponentOf(currentPlayer)->setCheck(false);
            }

            // Now get the next player
            currentPlayer = Game::getNextPlayer();
        }
    }

    // Display the final scores of the chess game
    cout << "\n" << currentPlayer->getName() << " Final Score: "
        << currentPlayer->calculateScore() << "\n"
        << Game::getOpponentOf(currentPlayer)->getName() << " Final Score: "
        << Game::getOpponentOf(currentPlayer)->calculateScore() << endl;
}
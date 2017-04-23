/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#include <iostream>
#include "Bishop.h"
#include "Board.h"
#include "Game.h"
#include "Knight.h"
#include "Pawn.h"
#include "Piece.h"
#include "Player.h"
#include "Rook.h"
#include "Square.h"
#include "Queen.h"

 /**
  * Game implementation
  */

Player* Game::_white = NULL;
Player* Game::_black = NULL;
Player* Game::_currentPlayer = new Player();
Board* Game::_board = Board::getInstance();
set<Piece*> Game::_blackPieces;
set<Piece*> Game::_whitePieces;
int Game::_turnCounter = 0;
bool Game::_drawOffered = false;
bool Game::_drawAccepted = false;


void Game::initialize()
{
    // Start by creating the black and white kings
    King* blackKing = NULL;
    King* whiteKing = NULL;


    // Iterate across the length of the board, putting the pieces in the
    // correct positions
    for (int i = 0; i < _board->getDimensions(); i++)
    {
        // Place the rooks
        if (i == A || i == H)
        {
            _blackPieces.insert(new Rook(_board->getSquareAt(EIGHT, i),
                BLACK_COLOR));
            _whitePieces.insert(new Rook(_board->getSquareAt(ONE, i),
                WHITE_COLOR));
        }

        // Place the Knights
        else if (i == B || i == G)
        {
            _blackPieces.insert(new Knight(_board->getSquareAt(EIGHT, i),
                BLACK_COLOR));
            _whitePieces.insert(new Knight(_board->getSquareAt(ONE, i),
                WHITE_COLOR));
        }

        // Place the bishops
        else if (i == C || i == F)
        {
            _blackPieces.insert(new Bishop(_board->getSquareAt(EIGHT, i),
                BLACK_COLOR));
            _whitePieces.insert(new Bishop(_board->getSquareAt(ONE, i),
                WHITE_COLOR));
        }

        // Place the Queens
        else if (i == D)
        {
            _blackPieces.insert(new Queen(_board->getSquareAt(EIGHT, i),
                BLACK_COLOR));
            _whitePieces.insert(new Queen(_board->getSquareAt(ONE, i),
                WHITE_COLOR));
        }

        // Place the kings
        else if (i == E)
        {
            // Create the king objects
            blackKing = new King(_board->getSquareAt(EIGHT, i), BLACK_COLOR);
            whiteKing = new King(_board->getSquareAt(ONE, i), WHITE_COLOR);

            // Now insert the kings into the collection
            _blackPieces.insert(blackKing);
            _whitePieces.insert(whiteKing);
        }

        // Place the pawns
        _blackPieces.insert(new Pawn(_board->getSquareAt(SEVEN, i),
            BLACK_COLOR));
        _whitePieces.insert(new Pawn(_board->getSquareAt(TWO, i),
            WHITE_COLOR));
    }

    // Now create the two players.
    _white = new Player(WHITE_COLOR, whiteKing, _whitePieces);
    _black = new Player(BLACK_COLOR, blackKing, _blackPieces);

    // Start off with the current player being the white player
    _currentPlayer = _white;
}


Player* Game::getNextPlayer()
{
    _currentPlayer = getOpponentOf(_currentPlayer);
    return _currentPlayer;
}


Player* Game::getOpponentOf(Player* player)
{
    Player* opponent;

    // If the current player is white, then the opponent is black
    if (player->getName() == _white->getName())
    {
        opponent = _black;
    }

    //Otherwise, the opponent is white
    else
    {
        opponent = _white;
    }

    return opponent;
}


Player* Game::getCurrentPlayer()
{
    return _currentPlayer;
}


bool Game::turnPerformed()
{
    return (++_turnCounter == MAX_TURNS);
}


void Game::resetTurnCount()
{
    _turnCounter = 0;
}

bool Game::isInCheck(Player* player)
{
    bool inCheck = false;
    Square* kingLocation = player->getKing()->getLocation();

    // Iterate through all the pieces of the given player's opponent.
    for (auto iter = getOpponentOf(player)->getPieces().begin();
    (iter != getOpponentOf(player)->getPieces().end()) && (!inCheck);
        ++iter)
    {
        // Make sure that the piece is on the board (A piece may be temporarily
        // removed from the board, but not fully captured, in the act of moving
        // a piece)
        if ((*iter)->getLocation() != NULL)
        {
            // If the given piece can capture the given player's king, then
            // this player is in check
            inCheck = (*iter)->canMoveTo(kingLocation);
        }
    }

    return inCheck;
}

bool Game::isInCheckmate(Player* player)
{
    bool inCheckmate = false;
    Piece* toBeCaptured = NULL;
    bool capturedPiece = false;
    Square* originalLocation;
    Square* destination;

    // Iterate through all the pieces of the player
    for (auto iter = player->getPieces().begin();
    (iter != player->getPieces().end()) && (!inCheckmate);
        ++iter)
    {
        originalLocation = (*iter)->getLocation();

        // Iterate through all of the squares on the board
        for (int rank = 0; rank < 8 && (!inCheckmate); rank++)
        {
            for (int file = 0; file < 8 && (!inCheckmate); file++)
            {
                destination = Board::getInstance()->getSquareAt(rank, file);

                // Don't bother checking if a piece can move to the location it
                // is currently at
                if ((*iter)->getLocation() != destination)
                {
                    if ((*iter)->canMoveTo(destination))
                    {
                        // Temporarily move the piece, and see if that puts the
                        // king in check.
                        if (destination->isOccupied())
                        {
                            // If the destination square is occupied remove the
                            // occupying piece to simulate being captured.
                            toBeCaptured = destination->getOccupant();
                            toBeCaptured->setLocation(NULL);
                            destination->setOccupant(NULL);
                            capturedPiece = true;
                        }

                        // Move the piece temporarily to its new location.
                        (*iter)->getLocation()->setOccupant(NULL);
                        (*iter)->setLocation(destination);
                        destination->setOccupant((*iter));

                        // If this move wouldn't put the player in check, then
                        // it is a "safe" move
                        inCheckmate = !(isInCheck(player));

                        // Now "reset" the board to its state prior to moving
                        // the piece
                        destination->setOccupant(NULL);

                        if (capturedPiece)
                        {
                            toBeCaptured->setLocation(destination);
                            destination->setOccupant(toBeCaptured);
                            capturedPiece = false;
                        }

                        (*iter)->setLocation(originalLocation);
                        originalLocation->setOccupant((*iter));
                    }
                }
            }
        }
    }

    return !inCheckmate;
}


bool Game::drawOffered()
{
    return _drawOffered;
}


bool Game::drawAccepted()
{
    return _drawAccepted;
}


void Game::offerDraw()
{
    _drawOffered = true;
}


void Game::rejectDraw()
{
    _drawOffered = false;
    _drawAccepted = false;
}


void Game::acceptDraw()
{
    _drawAccepted = true;
}

/**
 * 1851366
 * Assignment 7
 * 2017-04-13
 */

#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Piece.h"

 /**
  * Game implementation
  */

Player* Game::_white = new Player();
Player* Game::_black = new Player();
Player* Game::_currentPlayer = new Player();
Board& Game::_board = Board::getInstance();
set<Piece*> Game::_blackPieces;
set<Piece*> Game::_whitePieces;
int Game::_turnCounter = 0;


void Game::initialize()
{
    // Start by placing all the necessary pieces on the board.
    // Start with the black pieces, then do the white pieces.
    King blackKing = PlaceBlackPieces(_board);
    King whiteKing = PlaceWhitePieces(_board);

    // Now create the two players, they'll just be named white and black for 
    // now
    delete _white;
    delete _black;
    _white = new Player(WHITE_COLOR, whiteKing, _whitePieces);
    _black = new Player(BLACK_COLOR, blackKing, _blackPieces);

    // Have the board display itself
    _board.display(cout);

    // Start off with the current player being the white player
    _currentPlayer = _white;
}


Player& Game::getNextPlayer()
{
    _currentPlayer = &getOpponentOf(*_currentPlayer);
    return *_currentPlayer;
}


Player& Game::getOpponentOf(Player& player)
{
    Player* opponent;

    // If the current player is white, then the opponent is black
    if (player.getName() == _white->getName())
    {
        opponent = _black;
    }

    //Otherwise, the opponent is white
    else
    {
        opponent = _white;
    }

    return *opponent;
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

/**
 * Places all of the black pieces on the board in their initial state
 *
 * @param board The board where the pieces will be placed
 *
 * @return The black King
 */
King& Game::PlaceBlackPieces(Board & board)
{
    // Start by creating the black king and adding it to the set of black 
    // pieces
    King* blackKing = new King(board.getSquareAt(EIGHT, E), BLACK_COLOR);
    _blackPieces.insert(blackKing);

    // Now create the rest of the black pieces
    // Queen
    _blackPieces.insert(new Queen(board.getSquareAt(EIGHT, D), BLACK_COLOR));

    // Bishops
    _blackPieces.insert(new Bishop(board.getSquareAt(EIGHT, C), BLACK_COLOR));
    _blackPieces.insert(new Bishop(board.getSquareAt(EIGHT, F), BLACK_COLOR));

    // Knights
    _blackPieces.insert(new Knight(board.getSquareAt(EIGHT, B), BLACK_COLOR));
    _blackPieces.insert(new Knight(board.getSquareAt(EIGHT, G), BLACK_COLOR));

    // Rooks
    _blackPieces.insert(new Rook(board.getSquareAt(EIGHT, A), BLACK_COLOR));
    _blackPieces.insert(new Rook(board.getSquareAt(EIGHT, H), BLACK_COLOR));

    // Pawns
    // Iterate over the files for the seventh rank
    for (int i = 0; i < board.getDimensions(); i++)
    {
        _blackPieces.insert(new Pawn(board.getSquareAt(SEVEN, i), BLACK_COLOR));
    }

    return *blackKing;
}


/**
 * Places all of the white pieces on the board in their initial state
 *
 * @param board The board where the pieces will be placed
 *
 * @return The white King
 */
King& Game::PlaceWhitePieces(Board & board)
{
    // Start by creating the white king and adding it to the set of the white 
    // pieces
    King* whiteKing = new King(board.getSquareAt(ONE, E), WHITE_COLOR);
    _whitePieces.insert(whiteKing);

    // Now create the rest of the white pieces
    // Queen
    _whitePieces.insert(new Queen(board.getSquareAt(ONE, D), WHITE_COLOR));

    // Bishops
    _whitePieces.insert(new Bishop(board.getSquareAt(ONE, C), WHITE_COLOR));
    _whitePieces.insert(new Bishop(board.getSquareAt(ONE, F), WHITE_COLOR));

    // Knights
    _whitePieces.insert(new Knight(board.getSquareAt(ONE, B), WHITE_COLOR));
    _whitePieces.insert(new Knight(board.getSquareAt(ONE, G), WHITE_COLOR));

    // Rooks
    _whitePieces.insert(new Rook(board.getSquareAt(ONE, A), WHITE_COLOR));
    _whitePieces.insert(new Rook(board.getSquareAt(ONE, H), WHITE_COLOR));

    // Pawns
    // Iterate over the files for the second rank
    for (int i = 0; i < board.getDimensions(); i++)
    {
        _whitePieces.insert(new Pawn(board.getSquareAt(TWO, i), WHITE_COLOR));
    }

    return *whiteKing;
}


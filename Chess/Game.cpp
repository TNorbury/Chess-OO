#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"

/**
 * Game implementation
 */

Player* Game::_player[2];
Board& Game::_board = Board::getInstance();
set<Piece*> Game::_blackPieces;
set<Piece*> Game::_whitePieces;
int Game::_currentPlayer;


void Game::initialize()
{
    // Start by placing all the necessary pieces on the board.
    // Start with the black pieces, then do the white pieces.
    King blackKing = PlaceBlackPieces(_board);
    King whiteKing = PlaceWhitePieces(_board);

    // Now create the two players, they'll just be named white and black for 
    // now
    _player[WHITE] = new Player("White", whiteKing, _whitePieces);
    _player[BLACK] = new Player("Black", blackKing, _blackPieces);

    // Have the board display itself
    _board.display(cout);

    // Start off with the current player being the white player
    _currentPlayer = WHITE;
}


Player& Game::getNextPlayer()
{
    // Make sure _currentPlayer doesn't get bigger than 1
    _currentPlayer = _currentPlayer % 2;

    // The next player is the opponent of the current player
    return getOpponentOf(*_player[_currentPlayer++]);
}


Player& Game::getOpponentOf(Player& player)
{
    Player* opponent;

    // If the current player is white, then the opponent is black
    if (player.getName() == _player[WHITE]->getName())
    {
        opponent = _player[BLACK];
    }

    //Otherwise, the opponent is white
    else
    {
        opponent = _player[WHITE];
    }

    return *opponent;
}


King& Game::PlaceBlackPieces(Board & board)
{
    // Start by creating the black king and adding it to the set of black 
    // pieces
    King* blackKing = new King(board.getSquareAt(EIGHT, E), "Black");
    _blackPieces.insert(blackKing);

    // Now create the rest of the black pieces
    // Queen
    _blackPieces.insert(new Queen(board.getSquareAt(EIGHT, D), "Black"));

    // Bishops
    _blackPieces.insert(new Bishop(board.getSquareAt(EIGHT, C), "Black"));
    _blackPieces.insert(new Bishop(board.getSquareAt(EIGHT, F), "Black"));

    // Knights
    _blackPieces.insert(new Knight(board.getSquareAt(EIGHT, B), "Black"));
    _blackPieces.insert(new Knight(board.getSquareAt(EIGHT, G), "Black"));

    // Rooks
    _blackPieces.insert(new Rook(board.getSquareAt(EIGHT, A), "Black"));
    _blackPieces.insert(new Rook(board.getSquareAt(EIGHT, H), "Black"));

    // Pawns
    // Iterate over the files for the seventh rank
    for (int i = 0; i < board.getDimensions(); i++)
    {
        _blackPieces.insert(new Pawn(board.getSquareAt(SEVEN, i), "Black"));
    }

    return *blackKing;
}

King& Game::PlaceWhitePieces(Board & board)
{
    // Start by creating the white king and adding it to the set of the white 
    // pieces
    King* whiteKing = new King(board.getSquareAt(ONE, E), "White");
    _whitePieces.insert(whiteKing);

    // Now create the rest of the white pieces
    // Queen
    _whitePieces.insert(new Queen(board.getSquareAt(ONE, D), "White"));

    // Bishops
    _whitePieces.insert(new Bishop(board.getSquareAt(ONE, C), "White"));
    _whitePieces.insert(new Bishop(board.getSquareAt(ONE, F), "White"));

    // Knights
    _whitePieces.insert(new Knight(board.getSquareAt(ONE, B), "White"));
    _whitePieces.insert(new Knight(board.getSquareAt(ONE, G), "White"));

    // Rooks
    _whitePieces.insert(new Rook(board.getSquareAt(ONE, A), "White"));
    _whitePieces.insert(new Rook(board.getSquareAt(ONE, H), "White"));

    // Pawns
    // Iterate over the files for the second rank
    for (int i = 0; i < board.getDimensions(); i++)
    {
        _whitePieces.insert(new Pawn(board.getSquareAt(TWO, i), "White"));
    }

    return *whiteKing;
}


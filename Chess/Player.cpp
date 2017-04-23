/**
 * 1851366
 * Assignment 9
 * 2017-04-22
 */

#include <iostream>
#include <set>
#include <string>
#include "Board.h"
#include "Game.h"
#include "King.h"
#include "Piece.h"
#include "Player.h"
#include "Square.h"

 /**
  * Player implementation
  */

const string IN_CHECKMATE = "#";
const char DRAW = '=';

const int SOURCE_FILE = 0;
const int SOURCE_RANK = 1;
const int DESTINATION_FILE = 3;
const int DESTINATION_RANK = 4;
const int DRAW_INDEX = 5;

const int INVALID_RANK_FILE = -1;

Player::Player(string name, King* king, set<Piece*>& pieces)
{
    _name = name;
    _king = king;
    _pieces = pieces;
}


string Player::getName()
{
    return _name;
}


King* Player::getKing()
{
    return _king;
}


set<Piece*>& Player::getPieces()
{
    return _pieces;
}


bool Player::makeMove(istream& is, ostream& os, ostream& err)
{
    bool isValidMove;
    bool drawAccepted = false;
    string input;
    int sourceRank;
    int sourceFile;
    int destinationRank;
    int destinationFile;
    Square* sourceSquare;
    Square* destinationSquare;

    // Ask the player to enter a move
    os << _name << " enter move: ";
    getline(is, input);

    // If the length of the input is 5 or 6, see if it is formatted correctly
    if (input.length() == 5 || input.length() == 6)
    {
        // Parse the characters in the input in order to get the indices of the
        // source and destination square 
        sourceFile = parseFile(input[SOURCE_FILE], cerr);
        sourceRank = parseRank(input[SOURCE_RANK], cerr);
        destinationFile = parseFile(input[DESTINATION_FILE], cerr);
        destinationRank = parseRank(input[DESTINATION_RANK], cerr);

        // If both the source and destination file and rank are valid, then get
        // the corresponding square from the board
        if ((sourceFile != INVALID_RANK_FILE) 
            && (sourceRank != INVALID_RANK_FILE) 
            && (destinationFile != INVALID_RANK_FILE) 
            && (destinationRank != INVALID_RANK_FILE))
        {
            sourceSquare = Board::getInstance()
                ->getSquareAt(sourceRank, sourceFile);
            destinationSquare = Board::getInstance()
                ->getSquareAt(destinationRank, destinationFile);

            // Check if the source square is occupied, if it is, then see if 
            // the occupying piece can move to the destination square
            if (sourceSquare->isOccupied() && (sourceSquare->getOccupant()
                ->getColor() == _name))
            {
                // If the occupant can move then move it
                if (sourceSquare->getOccupant()->canMoveTo(destinationSquare))
                {
                    // If this move would put the player in check, then it 
                    // won't be done and a message will be printed
                    if (!(sourceSquare->getOccupant()
                        ->moveTo(destinationSquare, *this)))
                    {
                        err << endl << "This move would put you in check so it"
                            << " won't be done" << endl;
                        isValidMove = false;
                    }

                    // Otherwise, this is a valid move
                    else
                    {
                        isValidMove = true;
                    }
                }

                // Otherwise, if the player resigned, then the game is over
                else if (hasResigned())
                {
                    // The move is valid just for the sake of ending the game
                    isValidMove = true;
                }

                // Otherwise, print an error message
                else
                {
                    err << "The piece at the starting square can't move to "
                        << "the destination square" << endl;
                    isValidMove = false;
                }
            }
            else
            {
                err << "The source square isn't occupied by a piece you own"
                    << endl;
                isValidMove = false;
            }
        }

        // Otherwise, improper rank or file was entered, meaning that this move
        // is invalid
        else
        {
            isValidMove = false;
        }

        // If the input was valid, and there was a 6th character at the end of 
        // the input, check if the player is offering a draw
        if (isValidMove && input.length() == 6)
        {
            // If the 6th character is '=' then a draw was offered.
            if (input[DRAW_INDEX] == DRAW)
            {
                // The draw is considered "accepted" for the sake of continuing
                // the game
                isValidMove = true;
                drawAccepted = true;
                Game::offerDraw();
            }

            // Otherwise, this input is invalid
            else
            {
                err << endl << "The only valid character to append to a move "
                    << "is =" << endl;
                isValidMove = false;
            }
        }
    }

    // Otherwise, if the only character entered is "#", then the player is in 
    // checkmate
    else if (input.length() == 1)
    {
        // If the entered input is "#" then the player is declaring that they 
        // are in checkmate
        if (input == IN_CHECKMATE)
        {
            // If the player is currently checked, then they can declare that 
            // they're in checkmate
            if (_inCheck)
            {
                isValidMove = true;
                resign();
            }

            // Otherwise, print a message indicating that this move is invalid
            else
            {
                cerr << "You can't indicate that you're in checkmate if you're"
                    << " not checked" << endl;
                isValidMove = false;
            }
        }

        // Otherwise, if "=" is entered, then see if a draw was offered.
        else if (input[0] == DRAW)
        {
            // If a draw was offered, then the move is valid
            if (Game::drawOffered())
            {
                isValidMove = true;
                drawAccepted = true;

                // Tell the game that the draw was accepted
                Game::acceptDraw();
            }

            // Otherwise, it's invalid to accepted a draw if one wasn't offered
            else
            {
                err << "You can't accept a draw if one wasn't offered" << endl;
                isValidMove = false;
            }
        }

        // If neither of those characters were entered, then the move isn't 
        // considered valid
        else
        {
            isValidMove = false;
        }
    }
    else
    {
        err << "Input was too short or too long" << endl;
        isValidMove = false;
    }

    // If a draw wasn't accepted, but there was an offer for a draw, then 
    // reject said offer
    if (Game::drawOffered() && !drawAccepted)
    {
        Game::rejectDraw();
    }

    return isValidMove;
}


void Player::capture(Piece* piece)
{
    std::set<Piece*>::iterator capturedPiece;

    // Put the captured piece into the captured pieces collection
    _capturedPieces.insert(piece);

    // Since a piece was captured tell the game to reset the turn counter.
    Game::resetTurnCount();

    // Finally, remove the captured from its owner's set of pieces.
    // Start by finding the captured piece's location in the set.
    capturedPiece = Game::getOpponentOf(this)->getPieces().find(piece);

    // Then remove said piece from the set
    Game::getOpponentOf(this)->getPieces().erase(capturedPiece);
}


bool Player::hasResigned()
{
    return _resigned;
}


void Player::resign()
{
    _resigned = true;
}


int Player::calculateScore()
{
    int score = 0;

    // Iterate through all the pieces of the player
    for (auto iter = getPieces().begin(); iter != getPieces().end(); ++iter)
    {
        score += (*iter)->getValue();
    }

    return score;
}


void Player::setCheck(bool inCheck)
{
    _inCheck = inCheck;
}


Player::Player()
{
    // This default constructor exists so that the static players in Game can
    // be instantiated
}


/**
 * Parse a character and find the rank that it corresponds to. The number
 * returned is based around the indexes of the chess board and is 0-based
 *
 * @param inputCharacter The character that will be parsed
 * @param os The stream that will be printed to if there is an issue with
 *           parsing
 *
 * @return 0-7 if the character was valid, otherwise -1.
 */
int Player::parseRank(char inputCharacter, ostream& os)
{
    int rank;

    // Switch on the given character and find the appropriate rank
    switch (inputCharacter)
    {

        // Since the array which represents that board is 0-based, and the top
        // row is 0, the rank that the player enters will be different than the
        // int returned by this function, though they will reference the same
        // place
        case '1':
            rank = 7;
            break;
        case '2':
            rank = 6;
            break;
        case '3':
            rank = 5;
            break;
        case '4':
            rank = 4;
            break;
        case '5':
            rank = 3;
            break;
        case '6':
            rank = 2;
            break;
        case '7':
            rank = 1;
            break;
        case '8':
            rank = 0;
            break;

            // If the input doesn't match any of those above, then it is
            // invalid.
        default:
            rank = INVALID_RANK_FILE;
            os << inputCharacter << " is not a valid rank!" << endl;
    }

    return rank;
}


/**
 * Parse a character and find the file that it corresponds to. The number
 * returned is based around the indexes of the chess board and is 0-based
 *
 * @param inputCharacter The character that will be parsed
 * @param os The stream that will be printed to if there is an issue with
 *           parsing
 *
 * @return 0-7, if the character was valid, otherwise -1.
 */
int Player::parseFile(char inputCharacter, ostream& os)
{
    int file;

    // Switch on the given character and find the appropriate file
    switch (inputCharacter)
    {
        case 'a':
            file = 0;
            break;
        case 'b':
            file = 1;
            break;
        case 'c':
            file = 2;
            break;
        case 'd':
            file = 3;
            break;
        case 'e':
            file = 4;
            break;
        case 'f':
            file = 5;
            break;
        case 'g':
            file = 6;
            break;
        case 'h':
            file = 7;
            break;

            // If the input doesn't match any of those above, then it is
            // invalid.
        default:
            file = INVALID_RANK_FILE;
            os << inputCharacter << " is not a valid file!" << endl;
    }

    return file;
}

#include <set>
#include <string>
#include <iostream>
#include "Player.h"
#include "King.h"
#include "Piece.h"
#include "Board.h"
#include "Square.h"

/**
 * Player implementation
 */

const int SOURCE_FILE = 0;
const int SOURCE_RANK = 1;
const int DESTINATION_FILE = 3;
const int DESTINATION_RANK = 4;

Player::Player(string name, King& king, set<Piece*>& pieces)
{
    _name = name;
    _king = &king;
    _pieces = pieces;
}


string Player::getName()
{
    return _name;
}


King& Player::getKing()
{
    return *_king;
}


set<Piece*>& Player::getPieces()
{
    return _pieces;
}


bool Player::makeMove(istream& is, ostream& os, ostream& err)
{
    bool isValidMove = true;
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

    // Make sure that the input is of appropriate length, which is 5. If it's 
    // not then don't parse the input
    if (input.length() == 5)
    {
        // Parse the characters in the input in order to get the indices of the
        // source and destination square 
        sourceFile = parseFile(input[SOURCE_FILE], cerr);
        sourceRank = parseRank(input[SOURCE_RANK], cerr);
        destinationFile = parseFile(input[DESTINATION_FILE], cerr);
        destinationRank = parseRank(input[DESTINATION_RANK], cerr);

        // If both the source and destination file and rank are valid, then get
        // the corresponding square from the board
        if ((sourceFile != -1) && (sourceRank != -1) && (destinationFile != -1)
            && (destinationRank != -1))
        {
            sourceSquare = Board::getInstance()
                .getSquareAt(sourceRank, sourceFile);
            destinationSquare = Board::getInstance()
                .getSquareAt(destinationRank, destinationFile);

            // Check if the source square is occupied, if it is, then see if 
            // the occupying piece can move to the destination square
            if (sourceSquare->isOccupied() && (sourceSquare->getOccupant()
                .getColor() == _name))
            {
                // If the occupant can move then move it
                if (sourceSquare->getOccupant().canMoveTo(destinationSquare))
                {
                    sourceSquare->getOccupant().moveTo(destinationSquare,
                        *this);
                }

                // Otherwise, print an error message
                else
                {
                    cerr << "The piece at the starting square can't move to "
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
        else
        {
            isValidMove = false;
        }
    }
    else
    {
        err << "Input was too short" << endl;
        isValidMove = false;
    }

    return isValidMove;
}


void Player::capture(Piece& piece)
{
    // Put the captured piece into the captured pieces collection
    _capturedPieces.insert(&piece);

    // Tell the piece that it isn't on the board anymore
    piece.setLocation(NULL);
}


int Player::calculateScore()
{
    return 0;
}

Player::Player()
{
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

        // If the input doesn't match any of those above, then it is invalid.
        default:
            rank = -1;
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

        // If the input doesn't match any of those above, then it is invalid.
        default:
            file = -1;
            os << inputCharacter << " is not a valid file!" << endl;
    }

    return file;
}

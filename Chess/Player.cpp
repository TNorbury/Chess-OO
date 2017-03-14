#include <set>
#include <string>
#include "Player.h"
#include "King.h"
#include "Piece.h"

 /**
  * Player implementation
  */


  /**
   * @param name The Player's name
   * @param king The player's king
   * @param pieces The set of pieces owned by this player
   */
Player::Player(string name, King& king, set<Piece*>& pieces)
{
    _name = name;
    _king = &king;
    _pieces = pieces;
}

/**
 * @return string
 */
string Player::getName()
{
    return _name;
}

/**
 * @return King&
 */
King& Player::getKing()
{
    return *_king;
}

/**
 * @return set<Piece*>&
 */
set<Piece*>& Player::getPieces()
{
    return _pieces;
}

/**
 * @return bool
 */
bool Player::makeMove()
{
    return false;
}

/**
 * @param piece
 */
void Player::capture(Piece& piece)
{

}

/**
 * @return int
 */
int Player::calculateScore()
{
    return 0;
}

Player::Player()
{
}

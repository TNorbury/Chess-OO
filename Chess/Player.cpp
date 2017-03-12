#include <set>
#include <string>
#include "Player.h"
#include "King.h"
#include "Piece.h"

 /**
  * Player implementation
  */


  /**
   * @param name
   * @param king
   * @param pieces
   */
Player::Player(string name, King& king, set<Piece*>& pieces)
{

}

/**
 * @return string
 */
string Player::getName()
{
    return "";
}

/**
 * @return King&
 */
King& Player::getKing()
{
    return *king;
}

/**
 * @return set<Piece*>&
 */
set<Piece*>& Player::getPieces()
{
    return pieces;
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

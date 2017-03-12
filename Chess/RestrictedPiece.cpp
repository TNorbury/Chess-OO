/**
 * Project Chess
 * @author Brian R. Snider
 */


#include "RestrictedPiece.h"
#include "Square.h"
#include "Player.h"
#include "Piece.h"

 /**
  * RestrictedPiece implementation
  */


  /**
   * @param location
   * @param byPlayer
   * @return bool
   */
bool RestrictedPiece::moveTo(Square& location, Player& byPlayer)
{
    return false;
}

/**
 * @return bool
 */
bool RestrictedPiece::hasMoved()
{
    return false;
}
#ifndef Display_H
#define Display_H
#include <string>
#include <list>
#include "Board.h"
using namespace std;

/**
 * Contains all the prints needed for the gameflow.
 */
class Display {
 public:
  /**
   * Prints the current state of board.
   * @param board Board object
   */
  virtual void printCurrentBoard(Board &board) = 0;
  /**
   * Prints the previous players move.
   * @param name of player
   * @param coordinate move
   */
  virtual void printPreviousMove(string name, string coordinate) = 0;
  /**
   * Prints whos turn it is.
   * @param name of player
   */
  virtual void printTurn(string name) = 0;
  /**
   * Prints a message that player has no move.
   */
  virtual void printNoMove() = 0;
  /**
   * Prints the options for the player.
   * @param options list of coordinates
   */
  virtual void printOptions(list<Coordinates> &options) = 0;
  /**
   * Asking player for a move.
   */
  virtual void printMoveRequest() = 0;
  /**
   * Printing an error message in case of wrong input.
   * @param error
   */
  virtual void printInputError(const char* error) = 0;
  /**
   * Prints the result of the game.
   * @param name of the winning player
   */
  virtual void printResult(string name = "draw") = 0;
  /**
   * Gets an input from a (human) player and returns it as a string.
   * @return string
   */
  virtual string input() = 0;
  /**
   * Printing an appropiate message.
   */
  virtual void pcCalculating() = 0;
  /**
   * Prints a message to player that he needs to wait for the other player's move.
   */
  virtual void waitingForPlayer() = 0;
  /**
   * Prints a message to player he needs to wait untill another player joins the game.
   */
  virtual void waitForOtherPlayerConnect() = 0;
};

#endif //Display_H

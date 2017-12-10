#ifndef ConsoleDisplay_H
#define ConsoleDisplay_H

#include "Display.h"

/**
 * All the prints of the gameflow, using console.
 */
class ConsoleDisplay : public Display {
 public:
   /**
   * Prints the current state of board.
   * @param board Board object
   */
  void printCurrentBoard(Board &board);
  /**
   * Prints the previous players move.
   * @param name of player
   * @param coordinate move
   */
  void printPreviousMove(string name, string coordinate);
  /**
   * Prints whos turn it is.
   * @param name of player
   */
  void printTurn(string name);
  /**
   * Prints a message that player has no move.
   */
  void printNoMove();
  /**
   * Prints the options for the player.
   * @param options list of coordinates
   */
  void printOptions(list<Coordinates> &options);
  /**
   * Asking player for a move.
   */
  void printMoveRequest();
  /**
   * Printing an error message in case of wrong input.
   * @param error
   */
  void printInputError(const char* error);
  /**
   * Prints the result of the game.
   * @param name of the winning player
   */
  void printResult(string name = "draw");
  /**
   * Printing an appropiate message.
   */
  void pcCalculating();
  /**
   * Gets an input from a (human) player and returns it as a string.
   * @return string
   */
  string input();
  /**
   * Prints a message to player that he needs to wait for the other player's move.
   */
  void waitingForPlayer();
  /**
   * Prints a message to player he needs to wait untill another player joins the game.
   */
  void waitForOtherPlayerConnect();
};

#endif //ConsoleDisplay_H

// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef CONSOLEGAMEFLOW_H
#define CONSOLEGAMEFLOW_H

#include "GameFlowLook.h"

/**
 * All the prints of the gameflow, using console.
 */
class ConsoleGameFlow : public GameFlowLook{
 public:
  void/**
   * Prints the current state of board.
   * @param board Board object
   */
  printCurrentBoard(Board &board);
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
};

#endif //CONSOLEGAMEFLOW_H

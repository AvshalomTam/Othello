//
// Created by steve on 12/6/17.
//

#ifndef OTHELLO_SERVERLISTENER_H
#define OTHELLO_SERVERLISTENER_H
#include "Listener.h"
class ServerListener : public Listener {
 public:
  /**
   * Constructor.
   */
  ServerListener(Listener *listener, int clientSocket);
  /**
   * Sets the name of the previous player.
   * @param name string
   */
  void setPreName(string name);
  /**
   * @return name of previous player
   */
  string getName();
  /**
   * Sets the move of the previous player.
   * @param c Coordinates
   */
  void setPreMove(Coordinates c);
  /**
   * @return previous move
   */
  Coordinates getPreMove();
  /**
   * Sets boolean saying if previous player had a move.
   * @param had_move boolean
   */
  void hadMove(bool had_move);
  /**
   * @return true if previous player had a move, false otherwise
   */
  bool preHadMove();
  ~ServerListener();
 private:
  int client_socket_;
  Listener *listener_;
};
#endif //OTHELLO_SERVERLISTENER_H

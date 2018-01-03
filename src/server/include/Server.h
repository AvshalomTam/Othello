#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include "ClientHandler.h"
class Server {
 public:
  /**
   * Constructor.
   */
  Server();
  /**
   * Creates a socket and listens to incoming clients.
   * @param filePath path to file with information about ip and port
   */
  void start(const char* filePath);
  /**
   * Closes the server.
   */
  void stop();
  /**
   * Handles the clients, passes messages from one to another.
   * @param clientSocket1 socket from which client 1 listens
   * @param clientSocket2 socket from which client 2 listens
   */
 private:
    ClientHandler handler_;
  int serverSocket; // the socket's file descriptor
};

#endif //SERVER_SERVER_H

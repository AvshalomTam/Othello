//
// Created by steve on 12/5/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

class Server {
 public:
  Server(int port);
  void start();
  void stop();

 private:
  int port;
  int serverSocket; // the socket's file descriptor

  void handleClients(int clientSocket1, int clientSocket2);
  int middleMan(int clientSocketRead, int clientSocketWrite);
};

#endif //SERVER_SERVER_H

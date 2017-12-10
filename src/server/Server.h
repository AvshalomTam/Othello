//
// Created by steve on 12/5/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

class Server {
 public:
  Server();
  void start(const char* filePath);
  void stop();
  void handleClients(int clientSocket1, int clientSocket2);
  int middleMan(int clientSocketRead, int clientSocketWrite);
  int getPort(const char* filePath);
 private:
  int port;
  int serverSocket; // the socket's file descriptor
};

#endif //SERVER_SERVER_H

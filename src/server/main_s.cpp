#include "include/Server.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
  Server server;
  try {
    server.start("../exe/server_settings.txt");
  } catch (const char *msg) {
    cout << "Cannot start server. Reason: " << msg << endl;
    return 0;
  }
  server.stop();
  return 0;
}
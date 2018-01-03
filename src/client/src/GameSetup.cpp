#include <vector>
#include <iostream>
#include "../include/GameSetup.h"
#include "../include/Menu.h"
#include "../include/ConsoleMenu.h"
#include "../include/ConsoleDisplay.h"
#define MAX_NAME_LENGTH 50

GameSetup::GameSetup(const char *filePath) : filepath_(filePath) {
    setMainMenu();
    setRemoteMenu();
    setServerAddress();
    this->display = new ConsoleDisplay();
}

void GameSetup::setup() {
    this->main_menu_->printMenu();
    char choice = this->main_menu_->getChoice();
    switch (choice) {
        case '1': this->type_ = local;
            return;

        case '2': this->type_ = computer;
            return;

        case '3':   while (true) {
                        int n = remoteSetup();
                        if (n != 0) {
                            this->type_ = remote;
                            return;
                        }
                    }
    }
}

int GameSetup::remoteSetup() {
    this->remote_menu_->printMenu();
    char choice = this->remote_menu_->getChoice();
    switch (choice) {
        case '1': return listGames();

        case '2': return joinGame();

        case '3': return startGame();
    }
}

void GameSetup::setMainMenu() {
    this->main_menu_ = new ConsoleMenu();
    this->main_menu_->title("OTHELLO");
    this->main_menu_->subTitle("Choose an opponent type:");
    this->main_menu_->addMenuOption('1', "a human local player");
    this->main_menu_->addMenuOption('2', "an AI player");
    this->main_menu_->addMenuOption('3', "a remote player");
}

void GameSetup::setRemoteMenu() {
    this->remote_menu_ = new ConsoleMenu();
    this->remote_menu_->subTitle("Choose a command:");
    this->remote_menu_->addMenuOption('1', "get the list of open games");
    this->remote_menu_->addMenuOption('2', "join an excisting game");
    this->remote_menu_->addMenuOption('3', "start a new game");
}

int GameSetup::getSocket() {
    return this->socket_;
}

game_type GameSetup::getGameType() {
    return this->type_;
}

void GameSetup::setServerAddress() {
    //allocating places
    string serverIP;
    const char* serverIP_c;
    int serverPort;
    //open file
    ifstream inFile;
    inFile.open(this->filepath_);
    if (inFile.is_open()) {
        //reading first line
        inFile >> serverPort;
        //reading second line
        inFile >> serverIP;
    }
    else {
        throw "Error opening file";
    }
    //close the file
    inFile.close();
    serverIP_c = serverIP.c_str();
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP_c, &address)) {
        throw "Can't parse IP address";
    }
    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof(address), AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    bzero((char *)&address, sizeof(address));

    this->serverAddress.sin_family = AF_INET;
    memcpy((char *)&this->serverAddress.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    // htons converts values between host and network byte orders
    this->serverAddress.sin_port = htons(serverPort);
}

int GameSetup::createConnection() {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        throw "Error opening socket";
    }
    // Establish a connection with the TCP server
    if (connect(client_socket, (struct sockaddr *)&this->serverAddress, sizeof(this->serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    return client_socket;
}

GameSetup::~GameSetup() {
    delete this->main_menu_;
    delete this->remote_menu_;
    delete this->display;
}

int GameSetup::listGames() {
    int socket = createConnection();
    string command = "list_games";
    int n = write(socket, command.data(), command.size());
    if (n == -1) {
        throw "Error writing to server";
    }
    char buffer[MAX_NAME_LENGTH] = "\0";
    int amount = 0;

    n = read(socket, buffer, sizeof(buffer));
    if (n == -1 ) {
        throw "Error reading from server";
    }
    while (n != 0) {
        amount++;
        this->display->printGameName(buffer);
        int ack = 1;
        n = write(socket, &ack, sizeof(int));
        if (n == -1 ) {
            throw "Error writing to server server";
        }
        for (int i = 0; i < MAX_NAME_LENGTH; i++) {
            buffer[i] = '\0';
        }
        n = read(socket, buffer, sizeof(buffer));
        if (n == -1 ) {
            throw "Error reading from server";
        }
    }

    if (amount == 0) {
        this->display->nonAvailable();
    }
    close(socket);
    this->display->pressAnyKey();
    return 0;
}

int GameSetup::joinGame() {
    string game_name = this->display->getGameName();
    string command = "join ";
    command.append(game_name);
    int socket = createConnection();
    int n = write(socket, command.data(), command.size());
    if (n == -1) {
        throw "Error writing to server";
    }
    if (n == 0) {
        throw "Server disconnected.";
    }
    int number;
    n = read(socket, &number, sizeof(number));
    if (n == -1) {
        throw "Error reading from server";
    }
    if (n == 0) {
        throw "Server disconnected.";
    }
    if (number == -1) {
        close(socket);
        this->display->printUnableJoin();
        this->display->pressAnyKey();
        return 0;
    }
    this->socket_ = socket;
    return 1;
}

int GameSetup::startGame() {
    string game_name = this->display->getGameName();
    string command = "start ";
    command.append(game_name);
    int socket = createConnection();
    int n = write(socket, command.data(), command.size());
    if (n == -1) {
        throw "Error writing to server";
    }
    if (n == 0) {
        throw "Server disconnected.";
    }
    int number;
    n = read(socket, &number, sizeof(number));
    if (n == -1) {
        throw "Error reading from server";
    }
    if (n == 0) {
        throw "Server disconnected.";
    }
    if (number == -1) {
        close(socket);
        this->display->printNameOccupied();
        this->display->pressAnyKey();
        return 0;
    }
    this->display->waitForOtherPlayerConnect();
    this->socket_ = socket;
    return 1;
}

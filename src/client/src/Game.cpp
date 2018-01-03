#include <iostream>
#include "../include/Game.h"
#include "../include/CharBoard.h"
#include "../include/BasicRules.h"
#include "../include/ConsoleDisplay.h"
#include "../include/ConsoleMenu.h"
#define NO_MOVE Coordinates(-1, -1)

Game::Game() : frst_player_(true) {}

void Game::initialize(const char* filePath) {
    this->setup_ = new GameSetup(filePath);
    this->setup_->setup();
    this->game_flow_ = new ConsoleDisplay();
    this->board_ = new CharBoard(4);
    this->judge_ = new BasicRules();

    this->factory = new PlayerFactory(*this->board_, *this->judge_, *this->game_flow_, *this->setup_);
    this->pl1_ = factory->getFirstPlayer();
    this->pl2_ = factory->getSecondPlayer();
    this->pl1_->setName("X");
    this->pl2_->setName("O");
}

void Game::run() {
  try {
    do {
      if (this->frst_player_) {
        this->playOneTurn(*this->pl1_);
      } else {
        this->playOneTurn(*this->pl2_);
      }
      this->frst_player_ = !this->frst_player_;
    } while ((this->pl1_->played() || this->pl2_->played()) && !this->judge_->boardIsFull(*this->board_));
  } catch (const char* e) {
    this->game_flow_->serverDisconnect(e);
    return;
  }

  this->board_->printBoard();
  //printing the game results
  int winner = this->judge_->checkWinner(*this->board_);
  if (winner == 0) {
    this->game_flow_->printResult();
  }
  else {
    if (winner == first_player) {
      this->game_flow_->printResult(this->pl1_->getName());
    }
    else {
      this->game_flow_->printResult(this->pl2_->getName());
    }
  }
}

void Game::playOneTurn(Player &pl) {
  this->game_flow_->printCurrentBoard(*this->board_);

  pl.message();

  try {
    //get move from current player
    Coordinates input = pl.getMove();
    if (!NO_MOVE.isEqual(input)) {
      this->judge_->turnTiles(*this->board_, input, pl.getId());
    }
  } catch (const char* e) {
    throw e;
  }
}

Game::~Game() {
    delete this->setup_;
  delete this->game_flow_;
  delete this->pl1_;
  delete this->pl2_;
  delete this->board_;
  delete this->judge_;
  delete this->factory;
}

#include <iostream>
#include "../include/Game.h"
#include "../include/CharBoard.h"
#include "../include/BasicRules.h"
#include "../include/ConsoleMenu.h"
#include "../include/ConsoleDisplay.h"
#define NO_MOVE Coordinates(-1, -1)

Game::Game() : frst_player_(true) {}

void Game::initialize() {
  this->menu_ = new ConsoleMenu();
  this->game_flow_ = new ConsoleDisplay();
  this->board_ = new CharBoard();
  this->judge_ = new BasicRules();
  //print the menu
  this->menu_->printMenu();
  this->factory = new PlayerFactory(*this->board_, *this->judge_, *this->game_flow_,
                                    this->menu_->getGameType(), "client_settings.txt");
  this->pl1_ = factory->getFirstPlayer();
  this->pl2_ = factory->getSecondPlayer();
  this->pl1_->setName("X");
  this->pl2_->setName("O");
}

void Game::run() {
  do {
    if (this->frst_player_) {
      this->playOneTurn(*this->pl1_);
    }
    else {
      this->playOneTurn(*this->pl2_);
    }
    this->frst_player_ = !this->frst_player_;
  }
  while ((this->pl1_->played() || this->pl2_->played()) && !this->judge_->boardIsFull(*this->board_));

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
  //get move from current player
  Coordinates input = pl.getMove();
  if (!NO_MOVE.isEqual(input)) {
    this->judge_->turnTiles(*this->board_, input, pl.getId());
  }
}

Game::~Game() {
  delete this->menu_;
  delete this->game_flow_;
  delete this->pl1_;
  delete this->pl2_;
  delete this->board_;
  delete this->judge_;
  delete this->factory;
}
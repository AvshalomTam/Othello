// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#include "../include/Game.h"
#include "../include/CharBoard.h"
#include "../include/BasicRules.h"
#include "../include/AIplayer.h"
#include "../include/ConsoleMenu.h"
#include "../include/ConsoleGameFlow.h"

Game::Game() : frst_player_(true) {}

void Game::initialize() {
  this->menu_ = new ConsoleMenu();
  this->game_flow_ = new ConsoleGameFlow();
  this->board_ = new CharBoard();
  this->judge_ = new BasicRules();
  this->menu_->printMenu();
  this->game_info_ = new PreviousInfo();
  if (this->menu_->getGameType() == local) {
    this->pl1_ = new HumanPlayer(first_player, *this->board_, *this->judge_, *this->game_flow_, *this->game_info_);
    this->pl2_ = new HumanPlayer(second_player, *this->board_, *this->judge_, *this->game_flow_, *this->game_info_);
  }
  else if (this->menu_->getGameType() == computer) {
    this->pl1_ = new HumanPlayer(first_player, *this->board_, *this->judge_, *this->game_flow_, *this->game_info_);
    this->pl2_ = new AIplayer(*this->board_, *this->judge_, *this->game_flow_, second_player);
  }
  this->pl1_->setName("X");
  this->pl2_->setName("O");
}

void Game::run() {
  do {
    this->playOneTurn();
    this->frst_player_ = !this->frst_player_;
  }
  while ((this->pl1_->played() || this->pl2_->played()) && (!this->judge_->boardIsFull(*this->board_)));

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

void Game::playOneTurn() {
  Player *pl;
  if (this->frst_player_) {
    pl = this->pl1_;
  }
  else {
    pl = this->pl2_;
  }

  this->game_flow_->printCurrentBoard(*this->board_);
  if (this->game_info_->preHadMove()) {
    this->game_flow_->printPreviousMove(this->game_info_->getName(), this->game_info_->getPreMove().toString());
  }

  this->game_flow_->printTurn(pl->getName());

  //if the player has no moves
  if (!this->judge_->hasOptions(*this->board_, pl->getId())) {
    this->game_info_->hadMove(false);
    pl->hasMove(false);
    this->game_flow_->printNoMove();
    return;
  }

  Coordinates input = pl->getMove();
  this->game_info_->hadMove(true);
  pl->hasMove(true);
  this->judge_->turnTiles(*this->board_, input, pl->getId());
  this->game_info_->setPreMove(input.move(Coordinates(1, 1)));
  this->game_info_->setPreName(pl->getName());
}

Game::~Game() {
  delete this->menu_;
  delete this->pl1_;
  delete this->pl2_;
  delete this->board_;
  delete this->judge_;
  delete this->game_info_;
}

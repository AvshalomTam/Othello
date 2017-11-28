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
  this->board_ = new CharBoard(4);
  this->judge_ = new BasicRules();
  this->menu_->printMenu();
  if (this->menu_->getGameType() == local) {
    this->pl1_ = new HumanPlayer(first_player);
    this->pl2_ = new HumanPlayer(second_player);
  }
  else if (this->menu_->getGameType() == computer) {
    this->pl1_ = new HumanPlayer(first_player);
    this->pl2_ = new AIplayer(*this->board_, *this->judge_, second_player);
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
  Player *pre_pl;

  if (this->frst_player_) {
    pl = this->pl1_;
    pre_pl = this->pl2_;
  }
  else {
    pl = this->pl2_;
    pre_pl = this->pl1_;
  }

  if (this->menu_->getGameType() == computer && !this->frst_player_) {
    if (this->judge_->getOptions(*this->board_, second_player).empty()) {
      pl->hasMove(false);
      return;
    }
    Coordinates input = pl->getMove();
    pl->hasMove(true);
    this->judge_->turnTiles(*this->board_, input, pl->getId());
    this->previous_move_ = input.move(Coordinates(1, 1));
    return;
  }

  this->game_flow_->printCurrentBoard(*this->board_);

  //previous player's move
  if (pre_pl->played()) {
    this->game_flow_->printPreviousMove(pre_pl->getName(), this->previous_move_.toString());
  }

  this->game_flow_->printTurn(pl->getName());

  //checking if player has any options
  list <Coordinates> options = this->judge_->getOptions(*this->board_, pl->getId());
  if (options.empty()) {
    this->game_flow_->printNoMove();
    pl->hasMove(false);
    return;
  }

  while (true) {
    pl->hasMove(true);
    //printing the player's options
    this->game_flow_->printOptions(options);

    this->game_flow_->printMoveRequest();
    try {
      Coordinates input = pl->getMove().move(Coordinates(-1, -1));
      //checking if player's choice is one of the options
      if (this->judge_->isValidChoice(*this->board_, input, pl->getId())) {
        this->previous_move_ = input.move(Coordinates(1, 1));
        this->judge_->turnTiles(*this->board_, input, pl->getId());
        break;
      }
      else {
        throw "That's none of your choices!";
      }
    } catch (const char* error) {
      this->game_flow_->printInputError(error);
      continue;
    }
  }
}

Game::~Game() {
  delete this->menu_;
  delete this->game_flow_;
  delete this->pl1_;
  delete this->pl2_;
  delete this->board_;
  delete this->judge_;
}

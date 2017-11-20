// EM168887
// Steve Gutfreund

#include <iostream>
#include "../include/Game.h"
#include "../include/CharBoard.h"
#include "../include/BasicRules.h"

enum {first_player = 1, second_player};
using namespace std;

Game::Game() : frst_player_(true) {}

void Game::initialize() {
  this->board_ = new CharBoard();
  this->frst_player_ = true;
  this->judge_ = new BasicRules();
  this->pl1_ = new HumanPlayer(first_player);
  this->pl2_ = new HumanPlayer(second_player);
  this->pl1_->setName("X");
  this->pl2_->setName("O");
}

void Game::run() {
  do {
    this->playOneTurn();
    this->frst_player_ = !this->frst_player_;
  }
  while ((this->pl1_->played() || this->pl2_->played()) && (!this->judge_->boardIsFull(*this->board_)));

  cout << endl << endl << "G A M E   O V E R" << endl << endl;
  board_->printBoard();

  //printing the game results
  int winner = this->judge_->checkWinner(*this->board_);
  cout << endl;
  if (winner == 0) {
    cout << "DRAW GAME !!!!";
  }
  else {
    if (winner == first_player) {
      cout << this->pl1_->getName();
    }
    else {
      cout << this->pl2_->getName();
    }
    cout << " wins the game.";
  }
  cout << endl << endl;
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

  cout << "Current board:" << endl << endl;
  board_->printBoard();
  cout << endl;

  //previous player's move
  if (pre_pl->played()) {
    cout << pre_pl->getName() << " played " << this->previous_move_.toString() << endl << endl;
  }

  cout << pl->getName() << ": It's your move." << endl;

  //checking if player has any options
  list <Coordinates> options = this->judge_->getOptions(*this->board_, pl->getId());
  if (options.empty()) {
    cout << "No possible moves. Play passes to the other player. Press any key to continue." << endl;
    cin.get();
    pl->hasMove(false);
    return;
  }

  while (true) {
    pl->hasMove(true);
    //printing the player's options
    cout << "Your possible moves: ";
    for (list<Coordinates>::iterator it = options.begin(); it != options.end(); ++it) {
      if (it == options.begin()) {
        cout << it->move(Coordinates(1, 1)).toString();
      }
      else {
        cout << "," << it->move(Coordinates(1, 1)).toString();
      }
    }
    cout << endl;

    cout << "Please enter your move row,col: ";
    try {
      Coordinates input = pl->getMove().move(Coordinates(-1, -1));
      //checking if player's choice is one of the options
      if (this->judge_->isValidChoice(*this->board_, input, pl->getId())) {
        this->previous_move_ = input.move(Coordinates(1, 1));
        this->judge_->turnTiles(*this->board_, input, pl->getId());
        cout << endl << endl;
        break;
      }
      else {
        throw "Thats none of your choices!";
      }
    } catch (const char* error) {
      cout << endl << error << endl << endl;
      continue;
    }
  }
}

Game::~Game() {
  delete this->pl1_;
  delete this->pl2_;
  delete this->board_;
  delete this->judge_;
}
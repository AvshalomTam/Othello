#include "../include/Player.h"

Player::Player(cell num_player) : had_move_(false), player_id_(num_player) {}

void Player::setName(string name) {
    this->name_ = name;
}

string Player::getName() const {
    return this->name_;
}

void Player::hasMove(bool played) {
    this->had_move_ = played;
}

bool Player::played() const {
    return this->had_move_;
}

cell Player::getId() const {
    return this->player_id_;
}
#include "../include/Coordinates.h"

string intToString(int num);

Coordinates::Coordinates() : x_(0), y_(0) {}

Coordinates::Coordinates(int x, int y) : x_(x), y_(y) {}

Coordinates::Coordinates(string s) {
	int i = 0;
	this->x_ = 0;
	while (s[i] != ',') {
		if (s[i] < '0' || s[i] > '9') {
			throw "Wrong parameters!";
		}
		this->x_ = 10 * this->x_ + s[i] - '0';
		i++;
	}
	i++;
	this->y_ = 0;
	while(i < s.length()) {
		if (s[i] < '0' || s[i] > '9') {
			throw "Wrong parameters!";
		}
		this->y_ = 10 * this->y_ + s[i] - '0';
		i++;
	}
}

void Coordinates::setX(int x) {
	this->x_ = x;
}

void Coordinates::setY(int y) {
	this->y_ = y;
}


int Coordinates::getX() const {
	return this->x_;
}

int Coordinates::getY() const {
	return this->y_;
}

string Coordinates::toString() const {
	return "(" + intToString(this->x_) + "," + intToString(this->y_ ) + ")";
}

Coordinates Coordinates::move(const Coordinates& vector) const {
	return Coordinates(this->x_ + vector.getX(), this->y_ + vector.getY());
}

string intToString(int num) {
	bool negative = false;
	if (num == 0) {
		return "0";
	}
	if (num < 0) {
		negative = true;
		num *= -1;
	}
	string s, tmp;
	while (num != 0) {
		tmp = s;
		s = num % 10 + '0';
		s.append(tmp);
		num /= 10;
	}
	if (negative) {
		return "-" + s;
	}
	return s;
}

bool Coordinates::isEqual(Coordinates& other) const {
	return this->getX() == other.getX() && this->getY() == other.getY();
}
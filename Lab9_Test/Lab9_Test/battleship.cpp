// implements and defines the functions
// defined by the files supplied by the professor
// to be used in the battleship lab
// Eddie Lampert
// 3/26/2021

#include "battleship.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

Location::Location() {
	x_ = -1;
	y_ = '*';
}

void Location::print() const {
	cout << x_ << y_ << endl;
}

void Location::fire() {
	cout << "Input x to fire: ";
	cin >> x_;
	cout << "Input y to fire: ";
	cin >> y_;
}

void Location::pick() {
	srand((unsigned)time(NULL));
	x_ = rand() % fieldSize_ + 1;
	y_ = rand() % fieldSize_ + 97;
}

bool compare(const Location& left, const Location& right) {
	return left.x_ == right.x_ && left.y_ == right.y_;
}

Ship::Ship() :sunk_(false) {}

bool Ship::match(const Location& a_loc) const {
	return compare(loc_, a_loc);
}

void Ship::setLocation(const Location& a_loc) {
	loc_ = a_loc;
}

void Ship::sink() {
	sunk_ = true;
}

void Ship::printShip() const {
	loc_.print();
	if (sunk_) cout << "sunk.";
	else cout << "up.";
}

int Fleet::check(const Location& a_loc) const {
	for (int i = 0; i < fleetSize_; ++i) {
		if (ships_[i].match(a_loc)) return i;
	}
	return -1;
}

void Fleet::deployFleet() {
	int i = 0;
	while (i < fleetSize_) {
		Location mySpot;
		mySpot.pick();
		int tmp = check(mySpot);
		if (tmp == -1) {
			ships_[i].setLocation(mySpot);
			++i;
		}
	}
}

bool Fleet::isHitNSink(const Location& a_loc) {
	for (int i = 0; i < fleetSize_; i++)
	{
		if (ships_[i].match(a_loc) == true)
		{
			ships_[i].sink();
			return true;
		}
	}
	return false;
}

bool Fleet::operational() const {
	for (int i = 0; i < fleetSize_; i++)
	{
		if (ships_[i].isSunk() == false)
			return true;
	}
	return false;
}

void Fleet::printFleet(void) const {
	for (int i = 0; i < fleetSize_; i++)
	{
		ships_[i].printShip();
	}
}
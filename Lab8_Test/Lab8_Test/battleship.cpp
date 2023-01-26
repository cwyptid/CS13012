// implements and defines the functions
// defined by the files supplied by the professor
// to be used in the battleship lab
// Eddie Lampert
// 3/17/2021

#include "battleship.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

void initialize(Ship arrShip[]) {
	// looping through the array
	arrShip[0] = { {-1, '*' }, false };
	// arrShip[0].loc.x = -1;
	// arrShip[0].loc.y = '*';
	// arrShip[0].sunk = false;
}

Location pick() {
	Location loc;
	// assign values 
	loc.x = rand() % fieldSize + 1; // [1,6]
	loc.y = rand() % fieldSize + 97; // [97-102]

	return loc;
}

bool match(const Ship& a_ship, const Location& a_loc) {
	if (a_ship.loc.x == a_loc.x
		&& a_ship.loc.y == a_loc.y) return true;
	return false;
}

int check(const Ship arrShip[], const Location& a_loc) {
	for (int i = 0; i < fleetSize; i++) {
		if (match(arrShip[i], a_loc)) {
			return i;
		}
	}
	return -1;
}

void deploy(Ship arrShip[]) {
	int i = 0;
	while (i < fleetSize) {
		Location mySpot = pick();
		int tmp = check(arrShip, mySpot);
		if (tmp == -1) {
			arrShip[i].loc = mySpot;
			arrShip[i].sunk = false;
			++i;
		}
	}

}

void printShip(const Ship& a_ship) {
	// prints the location
	cout << a_ship.loc.x << endl;
	cout << a_ship.loc.y << endl;
	// status (sunk or not)
	if (a_ship.sunk) cout << "sunk." << endl;
	else cout << "up." << endl;
}


void printFleet(const Ship arrShip[]) {
	for (int i = 0; i < fleetSize; i++) {
		printShip(arrShip[i]);
	}
}

bool operational(const Ship arrShip[]) {
	for (int i = 0; i < fleetSize; i++) {
		if (!arrShip[i].sunk) {
			return true;
		}
	}
	return false;
}

Location fire() {
	Location mySpot;
	cout << "Input x to fire: ";
	cin >> mySpot.x;
	cout << "Input y to fire: ";
	cin >> mySpot.y;
	return mySpot;
}

void sink(Ship& a_ship) {
	a_ship.sunk = true;
}
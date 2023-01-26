// utilizes battleship.cpp and
// battleship.hpp in order to 
// create the battleship game per
// the instructions provided
// Eddie Lampert
// 3/17/21

#include <cstdlib>
#include <iostream>
#include "battleship.hpp"

using std::cout; using std::string; using std::cin; using std::endl;

int main() {
    cout << "Welcome to the game! There are 8 ships in the fleet and it is your duty to sink them. I wish you luck!" << endl;
    cout << "Directions: The ocean is a 6x6 square, you will input a number (1-6) and a letter (a-f), Each ship takes up one space and once hit is sunk." << endl;

    Ship myFleet[fleetSize];
    string ans;

    srand(int(time(0)));

    initialize(myFleet);
    deploy(myFleet);

    cout << "Would you like to print the fleet? y/n " << endl;
    cin >> ans;
    if (ans == "y" || ans == "Y")
        printFleet(myFleet);

    while (operational(myFleet)) {
        Location myLocation = fire();
        int index = check(myFleet, myLocation);
        if (index != -1) {
            sink(myFleet[index]);
            cout << "It's a HIT! Congratulations!" << endl;
        }
        else {
            cout << "It's a MISS! Better luck next time!" << endl;
        }
    }

    cout << "GAME OVER: Thanks for playing!" << endl;
}
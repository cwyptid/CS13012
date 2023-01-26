// utilizes battleship.cpp and
// battleship.hpp in order to 
// create the battleship game per
// the instructions provided
// Eddie Lampert
// 3/26/21

#include "battleship.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::ctime; using std::string;

int main()
{
	cout << "Welcome to the game! There are 8 ships in the fleet and it is your duty to sink them. I wish you luck!" << endl;
	cout << "Directions: The ocean is a 6x6 square, you will input a number (1-6) and a letter (a-f), Each ship takes up one space and once hit is sunk." << endl;

	Fleet myFleet;
	srand(time(NULL));
	myFleet.deployFleet();
	string ans;

	cout << "Would you like to print the fleet? y/n " << endl;
	cin >> ans;
	if (ans == "y" || ans == "Y")
		myFleet.printFleet();

	do
	{
		Location shot;
		shot.fire();
		if (myFleet.isHitNSink(shot))
		{
			cout << "It's a HIT! Congratulations!" << endl;
		}
		else
			cout << "It's a MISS! Better luck next time!" << endl;
	} while (myFleet.operational());

	cout << "GAME OVER: Thanks for playing!" << endl;
}
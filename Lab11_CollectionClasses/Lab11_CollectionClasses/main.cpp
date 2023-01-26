// utilizes collection.cpp and
// collection.hpp in order to create
// the number collection lab per
// the instructions provided
// Eddie Lampert
// 4/9/21

#include "collection.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

	int number;
	char operation;
	Collection a1;

	do {
		cout << "Enter operation [a,r,q] and number:" << endl;
		cin >> operation;
		if (operation != 'q')
			cin >> number;
		if (operation == 'a') {
			a1.addNumber(number);
		}
		if (operation == 'r') {
			a1.removeNumber(number);
		}
		if (operation != 'q')
			a1.output();
			cout << " " << endl;

	} while (operation != 'q');
	a1.output();
}
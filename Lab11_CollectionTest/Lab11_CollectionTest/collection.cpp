// implements and defines the functions
// prototyped by the files supplied by the professor
// to be used in the number collection lab
// Eddie Lampert
// 4/9/21

#include "collection.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

// function checks the array for the number
int Collection::check(double number) {
	for (int i = 0; i < size_; i++) {
		if (col_[i] == number) {
			return i;
		}
	}
	return -1;
}

// adds number to the array
void Collection::addNumber(double number) {
	double* tmp;
	int found = check(number);
	if (found >= 0)
	{
		cout << "ERROR: duplicate number!\n";
		Collection a2;
		a2.output();
	}
	else
	{
		tmp = new double[size_ + 1];
		for (int i = 0; i < size_; i++) {
			tmp[i] = col_[i];
		}
		tmp[size_] = number;
		size_++;
		delete col_;
		col_ = tmp;
	}
}

// removes number from array
void Collection::removeNumber(double number) {
	int index = check(number);
	if (index < 0) {
		return;
	}
	double* tmp = new double[size_ - 1];
	for (int i = 0; i < index; i++) {
		tmp[i] = col_[i];
	}
	for (int i = index + 1; i < size_; i++) {
		tmp[i - 1] = col_[i];
	}
	size_--;
	delete  col_;
	col_ = tmp;
}

//  outputs array
void Collection::output() {
	for (int i = 0; i < size_; i++) {
		cout << col_[i] << ' ';
	}
}

//  void constructor
Collection::Collection() {
	size_ = 0;
}

//  destructor
Collection::~Collection() {
	delete col_;
}

//  copy constructor
Collection::Collection(const Collection& org) {
	size_ = org.size_;
	col_ = new double[size_];
	for (int i = 0; i < size_; ++i) {
		col_[i] = org.col_[i];
	}
}

//  overloaded assignment
Collection& Collection::operator=(const Collection& va) {
	size_ = va.size_;
	delete[] col_;
	col_ = new double[size_];
	for (int i = 0; i < size_; ++i) {
		col_[i] = va.col_[i];
	}
	return *this;
}
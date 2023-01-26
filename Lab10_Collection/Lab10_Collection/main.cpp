// utilizes collection.cpp and
// collection.hpp in order to create
// the number collection lab per
// the instructions provided
// Eddie Lampert
// 4/2/21

#include "collection.hpp"
#include <iostream>
using namespace std;

int main()
{
    double* arr = new double[1];
    int size = 0;

    while (true)
    {
        char operation;
        double number;

        cout << "Enter operation [a/r/q]:";
        cin >> operation;

        if (operation == 'a')
        {
            cout << "Enter number to add : ";
            cin >> number;
             addNumber(arr, number, size);
             output(arr, size);

        }
        else if (operation == 'r')
        {
            cout << "Enter number to remove : ";
            cin >> number;
            removeNumber(arr, number, size);
            output(arr, size);


        }
        else
        {
            break;
        }
    }


}
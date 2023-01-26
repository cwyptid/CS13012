// implements and defines the functions
// prototyped by the files supplied by the professor
// to be used in the number collection lab
// Eddie Lampert
// 4/2/21

#include"collection.hpp"
#include<iostream>

using namespace std;

void output(double* colPtr, int size)
{
    for (int i = 0; i < size; i++)
        cout << colPtr[i] << " ";
    cout << endl;
}

int check(double* colPtr, double number, int size)
{
    for (int i = 0; i < size; i++)
        if (colPtr[i] == number)
            return i;
    return -1;
}

void addNumber(double*& colPtr, double number, int& size)
{
    if (check(colPtr, number, size) == -1)
    {
        double* temp = new double[size + 1];
        int i;
        for (i = 0; i < size; i++)
        {
            temp[i] = colPtr[i];
        }
        temp[i] = number;
        delete[]colPtr;
        colPtr = temp;
        size += 1;
    }
}
void removeNumber(double*& colPtr, double number, int& size)
{
    int pos = check(colPtr, number, size);
    if (pos != -1)
    {
        double* temp = new double[size - 1];
        int i = 0;
        for (int j = 0; j < size; j++)
        {
            if (j != pos)
            {
                temp[i] = colPtr[j];
                i++;
            }
        }
        delete[]colPtr;
        colPtr = temp;
        size -= 1;
    }
}
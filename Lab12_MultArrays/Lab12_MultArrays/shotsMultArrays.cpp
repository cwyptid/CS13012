// keeps track of shots fired
// in a battleship game using
// multidimensional arrays
// Eddie Lampert
// 4/23/2021

#include<iostream>

using namespace std;
const int oceanLength = 6;
const int oceanWidth = 6;

int main()
{
    bool shots[oceanLength][oceanWidth] = { 0 };
    char shoot;
    int row_val, col_val;
    char ch;

    do {
        cout << "Input a number (1-6) and a letter (a-f): ";
        cin >> ch >> row_val;

        col_val = ch - 'a';
        row_val--;

        if (col_val >= 0 && col_val < oceanWidth 
            && row_val >= 0 && row_val <= oceanLength)

            shots[row_val][col_val] = true;

        cout << endl;
        cout << "Record of shots:" << endl;

        for (int lp = 0; lp < oceanWidth; lp++)

            cout << "  " << char('a' + lp);

        for (int lp = 0; lp < oceanLength; lp++) {

            cout << endl << endl << lp + 1 << " ";

            for (int lj = 0; lj < oceanLength; lj++) {

                if (shots[lp][lj] == true)
                    cout << "* ";
                else
                    cout << " ";

            }

        }

        cout << endl << "Try again? [y/n]";
        cin >> shoot;

    } while (shoot != 'n');
}
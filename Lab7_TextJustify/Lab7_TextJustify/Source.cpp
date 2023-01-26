// program takes a paragraph
// in unjustified.txt and
// prints a justified revision
// in a file justified.txt
// Eddie Lampert
// 3/21/2021

#include <iostream> 
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

using std::cout; using std::cin; using std::endl;
using std::string;
using std::ifstream; using std::ofstream;

// maximum size of a line in the justified text
const int maxSize = 75;

// declaration of function prototypes
string punctuationSpaces(string input);
size_t getLowest(string input, int startIndex);
string randomSpace(string input);

int main() {
    srand(time(NULL));
    string input;

    string filename = "unjustified.txt";
    ifstream fin(filename.c_str());

    // checks if the file can be opened
    if (fin.is_open())
    {
        ofstream fout("justified.txt"); // creates the output file for justified text

        // reads until the end of the file
        while (!fin.eof())
        {
            getline(fin, input); // reads a line from the file

            if (input.length() < maxSize)
            {
                if (input.length() >= 40)
                {
                    input = punctuationSpaces(input);


                    if (input.length() < maxSize)
                    {
                        input = randomSpace(input);
                    }

                    fout << input;

                }
                else
                    fout << input;
            }
            else
                fout << input;

            if (!fin.eof())
                fout << endl;
        }

        // closes the files
        fin.close();
        fout.close();

        cout << "PROGRAM EXECUTED SUCCESSFULLY: check your files for the justified text!" << endl;
    }
    else
        cout << "ERROR: unable to open file! " << filename << endl;
    return 0;

}

// adds spaces after punctuations
string punctuationSpaces(string input)
{
    size_t index = 0;
    string outStr = input;

    while ((outStr.length() < maxSize) && (index != (outStr.length() - 1)))
    {
        index = getLowest(outStr, index);

        if (index != outStr.length() - 1)
        {
            outStr = outStr.insert(index + 1, 2, ' ');
            index = index + 1;
        }
    }

    return outStr;

}

// retrieves the lowest index punctuation from the start of the index
size_t getLowest(string input, int startIndex)
{
    //string punctuations = ":.,!?;";
    string punctuations = ".,!?;";
    size_t index[maxSize];

    for (size_t i = 0; i < punctuations.length(); i++)
    {
        index[i] = input.find(punctuations.at(i), startIndex);
    }

    size_t min = input.length() - 1;
    for (size_t i = 0; i < punctuations.length(); i++)
        if ((index[i] != string::npos) && (index[i] < min))
            min = index[i];
    return min;
}

// adds random spaces in the strings
string randomSpace(string input)
{
    string outStr = input;
    int startNextWord = -1, endNextWord;
    int spaceInsert;
    while (outStr.length() < maxSize)
    {
        endNextWord = outStr.find_first_of(' ', startNextWord + 1);
        if (endNextWord == -1)
        {
            startNextWord = -1;
            endNextWord = outStr.find_first_of(' ', startNextWord + 1);
        }


        spaceInsert = rand() % 2;
        if (spaceInsert == 1)
            outStr = outStr.insert(endNextWord, 1, ' ');

        startNextWord = outStr.find_first_not_of(' ', endNextWord + 1);
        if (startNextWord == outStr.length() - 1)
            startNextWord = -1;


    }

    return outStr;
}
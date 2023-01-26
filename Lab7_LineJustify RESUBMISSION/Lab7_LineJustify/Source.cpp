// program allows the user to input
// a string, and then prints a
// justified revision of the string
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
void justification(string&);

int main() {
    srand(time(0));
    string line;

    // prompts the user to input a string
    cout << "input a string to be justified, then hit return." << endl;
    getline(cin, line);

    // calls the justification function
    justification(line);

    // prints the results
    cout << "your line justified is..." << endl;
    cout << line << endl;
}


// function that justifies the line
void justification(string& line) {

	// shorter than 40 characters is not justified
	if (line.size() < 40) return;

	string punctuations = ",.;!?";

	int pos = line.find(punctuations[0]);

	// adds spaces for punctuation
	while (pos != string::npos) {
		if (pos != string::npos && pos != line.size() - 1) {
			line.insert(pos + 1, " ");
		}
		pos = line.find(punctuations[0], pos + 1); // commas
		pos = line.find(punctuations[1], pos + 1); // periods
		pos = line.find(punctuations[2], pos + 1); // semicolons
		pos = line.find(punctuations[3], pos + 1); // exclamation points
		pos = line.find(punctuations[4], pos + 1); // question marks
	}

	// adds random spaces to the text according to the maxSize
	while (line.size() < maxSize) {
		int randPos = rand() % maxSize;
		int posToInsert = line.find_first_of(" ", randPos);
		if (posToInsert != string::npos) {
			line.insert(posToInsert + 1, " ");
		}
	}
}
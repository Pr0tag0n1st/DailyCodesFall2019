//Written by TJ with help from Aidan
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));//seeds rand
	vector<string> adjectives;//Dynamic string holder
	vector<string> nouns;	//Same but for a different set of strings
	vector<string>::iterator iter;//Counts through vectors
	ifstream input;//Reads from a text file
	string temp;//Temporarily holds a string
	int nloops = 0;//Sets the amount of nouns
	int aloops = 0;//Sets adjective amount
	int random;//Random number to pick random word
	char cont;//Allows user to continue the code
	cout << "Time to generate some \"original\" stand names" << endl;

	do {//Loop to take words and put them in vectors
		input.open("noun.txt");//Reads from noun text file
		input >> nloops;//Writes a number into the file to take that number of strings
		for (int i = 0; i < nloops; i++) {//For loop for number of strings to take
			input >> temp;//Use a temporary variable to take a string
			nouns.push_back(temp);//Save that string in the vector
			
		}
		input.close();//Close the noun flie
		input.open("adj.txt");//Open Adjective file
		input >> aloops;//Writes number to take number of strings

		for (int i = 0; i < aloops; i++) {//For loop for number of strings to take
			input >> temp;//Saves string to temporary variable
			adjectives.push_back(temp);//Save string in vector

		}
		input.close();//Close adjective text file

		while (nloops > 0 && aloops > 0) {//If either number drops to 0, stop the program
			iter = adjectives.begin();//Set iterator to the start of the adjectives vector
			random = rand() % aloops;//Pick a random number from the amount of strings taken
			for (int i = 0; i < random; i++) {//Loop to find the correct slot
				iter++;//Increments until correct slot is reached
			}
			cout << *iter << " ";//Prints string in iter's memory to the console window
			adjectives.erase(iter);//Removes string to prevent repetition
			aloops--;//Reduces maximum number count to account for removed slot

			iter = nouns.begin();//Sets iter to the start of the nouns 
			random = rand() % nloops;//Sets random number to the amount of slots in vector
			for (int i = 0; i < random; i++) {//Sets out loop to find the correct slot
				iter++;//Counts to reach the correct slot
			}
			cout << *iter << endl;//Prints out string in iterator's memory
			nouns.erase(iter);//Removes string and slot from vector
			nloops--;//Lowers the maximum slot number
		}
		cout << endl << "Input q to quit or anything else to keep going" << endl;//Tells user how to continue or escape
		cin >> cont;//User chooses to finish or keep going
		if (cont != 'q')
			cout << endl;
	} while (cont != 'q');

}
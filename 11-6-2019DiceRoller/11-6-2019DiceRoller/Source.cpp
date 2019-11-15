#include <ctime>						//Used to seed random
#include <iostream>						//Basic IO library
using namespace std;					//Skip by using a standard namespace
int DiceRoller(int sides);				//Function declaration
int main() {							//Start of main
	srand(time(NULL));					//Seeds random
	int input = 20;						//Declares variable
	cout << "What kind of dice would you like to roll?" << endl;		//Asks user for input
	cout << "You can pick either 4, 6, 8, 10, 12, or 20 sided dice.  A 0 will exit the program." << endl;//Clarifies inputs
	while (input != 0) {				//Starts game loop
		cin >> input;					//Requests user input
		if (input == 4 || input == 6 || input == 8 || input == 10 || input == 12 || input == 20)//Prevents logical inconsistencies
			cout << "By rolling a d" << input << ", you got " << DiceRoller(input) << ".  Would you like to roll again?" << endl;//Shows roll by calling function
		else							//Prevents incorrect dice from rolling
			cout << "I can't roll that die." << endl;//Error message
	}									//End of game loop
	cout << "Thanks for roling some dice!" << endl;//End message
}										//End of main
int DiceRoller(int sides) {				//Function definition
		return rand() % sides + 1;		//Random number generator
}										//End of function definition
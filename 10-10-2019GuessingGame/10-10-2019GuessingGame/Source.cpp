////programmed by Patrick and TJ on  10/10/2019
#include <ctime>
#include <iostream>
using namespace std;

int main() {
	srand(time(NULL));
//	int randomnumber = 0;
////	while (true) {
////		randomnumber = rand() % 14 + 2;
////		cout << randomnumber << endl;
////		system("Pause");
////	}
////}
	int randomnumber = rand() % 100+1;
	int guessnumber = 101;
	int turncount = 0;
	char choice = 'a';
	while (choice != 'q') {
		guessnumber = 101;
		randomnumber = rand() % 100 + 1;
		turncount = 0;
		cout << "Welcome to the Number guessing game!" << endl;
		cout << "If you'd like to play, press 'p'!  If not, press 'q'!" << endl;
		cin >> choice;
		if (choice == 'p') {
			while (choice != 'q' && guessnumber != randomnumber) {
				turncount++;
				cout << "Pick a number between 1 and 100." << endl;
				cin >> guessnumber;
				if (randomnumber > guessnumber) {
					cout << "Try again, your guess was too low." << endl;
				}
				if (randomnumber < guessnumber) {
					cout << "Try again, your guess was too high." << endl;
				}
			}
			if (guessnumber == randomnumber) {
				cout << "HEY! YOU GUESSED IT!" << endl;
				cout << "It took you " << turncount << " turns." << endl;
			}
			cout << "Want to play again? 'p' to play, 'q' to quit" << endl;
			cin >> choice;
		}
	}
	if (choice == 'q') {
		cout << "Ok, we'll see you next time then!" << endl;
	}
	return 0;
}
#include <ctime>
#include <iostream>
using namespace std;
//CoinDropper function
//9% chance to find a Penny
//15% chance to find a Nickel
//5% chance to find a Dime
//20% chance to find a Quarter
//25% chance to lose a Dime
//13% chance to lose a Nickel
//12% chance to lose a Quarter
//1% chance to lose a Dollar
int CoinDropper();

int main() {
	srand(time(NULL));
	int wallet = 100;
	cout << "You have " << wallet << " cents.  Let's see how that changes!" << endl;
	
	while (wallet > 0) {
		wallet += CoinDropper();
		cout << "You have " << wallet << " cents.  Let's see how that changes!" << endl;
		system("Pause");
	}

	cout << "You are broke mah boi" << endl;

}

int CoinDropper() {
	int dropchance = rand() % 101;
	if (dropchance < 10) {
		cout << "You found a Penny!" << endl;
		return 1;
	}
	if (10 <= dropchance && dropchance < 25) {
		cout << "You found a Nickel!" << endl;
		return 5;
	}
	if (25 <= dropchance && dropchance < 30) {
		cout << "You found a Dime!" << endl;
		return 10;
	}
	if (30 <= dropchance && dropchance < 50) {
		cout << "You found a Quarter!" << endl;
		return 25;
	}
	if (50 <= dropchance && dropchance < 75) {
		cout << "You lost a Dime." << endl;
		return -10;
	}
	if (75 <= dropchance && dropchance < 88) {
		cout << "You lost a Nickel." << endl;
		return -5;
	}
	if (88 <= dropchance && dropchance <= 99) {
		cout << "You lost a Quarter." << endl;
		return -25;
	}
	if (dropchance == 100) {
		cout << "There goes a dollar." << endl;
		return -100;
	}
}
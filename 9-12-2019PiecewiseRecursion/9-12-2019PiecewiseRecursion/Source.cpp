#include <iostream>
using namespace std;

int PiecewiseFunction(int input);

int main() {
	cout << "Give me a number.  It can be negative." << endl;
	int number;
	while (true) {
		cin >> number;
		cout << "My function has turned your input into " << PiecewiseFunction(number) << "." << endl;
		cout << "How about another one?" << endl;
	}
	
}

int PiecewiseFunction(int input) {
	if (input <= -5) {
		cout << (input * input) - 1 << endl;;
		return PiecewiseFunction((input*input)-1);
	}
	else if (-5 < input && input < 5 && input != 0) {
		return PiecewiseFunction(input*0);
	}
	else if (input >= 5) {
		cout << (input / input) + 1 << endl;;
		return PiecewiseFunction((input /input)+1);
	}
	else if (input == 0) {
		cout << "The madness has stopped" << endl;
		return 0;
	}
	else if (abs(input) > 1000) {
		cout << "Please stop" << endl;
		return 0;
	}
}
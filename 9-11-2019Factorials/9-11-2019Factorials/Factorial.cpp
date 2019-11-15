#include <iostream>
using namespace std;

double Factorial(double num);

int main() {
	while (true) {
		cout << "Give me a whole number please" << endl;
		double number = 0;
		cin >> number;
		cout << "Here we go" << endl;
		cout << Factorial(number) << endl;
	}
}

double Factorial(double num) {
	if (num > 1)
		return num * Factorial(num - 1);
	else if (num < -1)
		return num * Factorial(num + 1);
	else
		return 1;
	

}
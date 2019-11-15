#include <iostream>
using namespace std;

int main() {
	int input = 0;
	int printnum = 0;
	cout << "Hey, give me a number." << endl;
	cin >> input;

	for (int i = 0; i <= input; i++) {
		for (int j = 0; j < i; j++) {
			printnum++;
			cout << printnum<<" ";
		}
		cout << endl;
	}
	 

}
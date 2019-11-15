#include <iostream>

using namespace std;



int main() {
	int input1;
	int input2;
    int totalscore=0;
	int input4;

	cout << "How many scores do you need?" << endl;
	cin >> input1;
	input2 = input1;


	while (input1 > 0) {
		cout << "Enter score" << endl;
		cin >> input4;
		totalscore += input4;
		input1--;
	}
		
	cout << "The average is " << totalscore / input2 << "." << endl;




}
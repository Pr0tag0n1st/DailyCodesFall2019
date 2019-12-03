//Made by Leah and TJ
#include <iostream>//Iostream
#include <string> //String
using namespace std;//Cstd namespace

int main() {//Main
	string input;//Declares string variable
	int inputnum = 1;
	string FoodTypes[5] = {"NULL", "NULL", "NULL", "NULL", "NULL"};//Declares and initializes string array
	int FoodVotes[5] = { 0, 0, 0, 0, 0 };//Declares int array
	cout << "Tell me 5 types of foods." << endl;//Input prompt
	for (int i = 0; i < 5; i++) {//For loop
		getline(cin, input);//User  input
		FoodTypes[i] = input;//Places input into array
	}
	
	while (inputnum !=0) {
		cout << "Yo, vote for a food my dude: (Press 0 to quit) " << endl;
		cout << "Ok, so here's your food options:" << endl;//Confirm array
		for (int i = 0; i < 5; i++) {//Print out array slots
			cout << i + 1 << ": " << FoodTypes[i] << endl;//Number and print out slots
		}
		cin >> inputnum;

		switch (inputnum) {
		case 1:
			FoodVotes[0]++;
			cout << "You voted for " << FoodTypes[inputnum - 1] << endl;
			break;
		case 2:
			FoodVotes[1]++;
			cout << "You voted for " << FoodTypes[inputnum - 1] << endl;
			break;
		case 3:
			FoodVotes[2]++;
			cout << "You voted for " << FoodTypes[inputnum - 1] << endl;
			break;
		case 4:
			FoodVotes[3]++;
			cout << "You voted for " << FoodTypes[inputnum - 1] << endl;
			break;
		case 5:
			FoodVotes[4]++;
			cout << "You voted for " << FoodTypes[inputnum - 1] << endl;
			break;
		default:
			cout << "No" << endl;
			break;
		}
	}
	cout << "Here are the votes!" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "This food got " << FoodVotes[i] << " votes: " << FoodTypes[i] << endl;
	}
}

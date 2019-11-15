#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main() {
	char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	bool alphabettrue[26];
	while (true) {
		bool pangram = true;
		for (int i = 0; i < 26; i++) {
			alphabettrue[i] = false;
		}
		cout << "Give me a sentence to work with." << endl;
		string inputsentence;
		getline(cin, inputsentence);
		cout << "Your sentence is " << inputsentence << endl;
		for (auto& x : inputsentence) {
			//	tolower(inputsentence[x]);
			for (int i = 0; i < 26; i++) {
				if (x == alphabet[i]) {
					alphabettrue[i] = true;
				}
			}
		}
		for (int j = 0; j < 26; j++) {
			if (alphabettrue[j] == false) {
				pangram = false;
			}
		}
		if (pangram == true) {
			cout << inputsentence << "is a pangram" << endl;
		}
		if (pangram != true) {
			cout << inputsentence << "is not a pangram" << endl;
		}
		system("Pause");
	}
}
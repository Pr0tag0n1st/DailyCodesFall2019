//Made by Nathaniel and TJ
#include <iostream> 
#include <cmath>
using namespace std;

void Quad(int a, int b, int c);

int main() {
	int input1;
	int input2;
	int input3;
	while (true) {
		cout << "Can you give me the a \"a\" term of a quadratic?" << endl;
		cin >> input1;
		cout << "Can you give me the a \"b\" term of a quadratic?" << endl;
		cin >> input2;
		cout << "Can you give me the a \"c\" term of a quadratic?" << endl;
		cin >> input3;
		Quad(input1, input2, input3);
		system("Pause");
	}
}

void Quad(int a, int b, int c) {
	double root1 = 0;
	double root2 = 0;

	root1 = ((b * -1) + sqrt((b * b) - (4 * a * c))) / (2 * a);
	root2 = ((b * -1) - sqrt((b * b) - (4 * a * c))) / (2 * a);
	cout << " Your quadratic's solutions are (" << root1 << ", 0) and (" << root2 << ", 0)." << endl;
}
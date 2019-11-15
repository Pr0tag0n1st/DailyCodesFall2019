#include <iostream>
using namespace std;

void Recursion(int num);

int main() {
	int i = 0;
	Recursion(i);
}

void Recursion(int num) {
	cout << "Num is " << num << endl;
	num++;
	Recursion(num);
}
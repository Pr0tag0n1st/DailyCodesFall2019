#include <iostream>
using namespace std;

const double DEATH_RATE = 0.1;
const double CONVERSION_RATE = 0.00001;
const double GROWTH_RATE = 0.4;
const double FOX_ABILITY = 0.0005;
const double CAPACITY = 30000;


int main() {
	int fox;
	int geese;
	int yearfox;
	int yeargeese;
	cout << "How many geese are there on the island?" << endl;
	cin >> geese;
	cout << "How many foxes are there on the island?" << endl;
	cin >> fox;
	yearfox = fox;
	yeargeese = geese;

	for (int i = 0; i <= 100; i++) {
		yearfox = fox;
		yeargeese = geese;
		fox = ((1 - DEATH_RATE + CONVERSION_RATE * yeargeese) * yearfox);
		geese = (((1 + GROWTH_RATE - (GROWTH_RATE * yeargeese) / CAPACITY) - FOX_ABILITY * yearfox) * yeargeese);
		if (i % 10 == 0) {
			cout << "Year   " << i << "  Fox    " << yearfox << "   Geese  " << yeargeese << endl;
		}
	}

}






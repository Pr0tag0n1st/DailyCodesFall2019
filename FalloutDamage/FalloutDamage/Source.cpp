#include <iostream>
using namespace std;
double DamageResistance(double Resistance, double Adjusted);
int main() {
	double DR = 0;
	double Adj = 0;
	while (1) {
		cout << "You just got hit!  What's your damage resistance?" << endl;
		cin >> DR;
		cout << "What difficulty are you on?" << endl;
		cin >> Adj;
		cout << "Well then, you resisted " << DamageResistance(DR, Adj) << " points of damage." << endl;

	}



}
double DamageResistance(double Resistance, double Adjusted) {
	double damage;
	if (Resistance > 90)
		Resistance = 90; 
	cout <<"Resistance is "<< Resistance << endl;
	damage = Adjusted * ((100 - Resistance)/100);
	cout <<"Damage is "<< damage << endl;
	if (damage < 1)
		damage = 1;

	return damage;
}
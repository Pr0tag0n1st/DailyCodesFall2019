//Written by Patrick and TJ
#include <iostream>
#include <string>
using namespace std;


class dayType {
private:
	string Days[7] = { "sun", "mon", "tues", "wed", "thur", "fri", "sat" };
	int day;

public:
	void SetDay(string newday);
	void PrintDay();
	int Today();
	int Tomorrow();
	int Yesterday();
	int DaysLater(int skipdays);
	dayType();
};


int main() {
	int dayskip = 0;
	dayType weekday;
	string input;
	cout << "Welcome to days of the week" << endl;
	cout << "What is today? (answer with sun, mon, tues, wed, thur, fri, or sat)" << endl;
	getline(cin, input);
	weekday.SetDay(input);
	weekday.PrintDay();
	weekday.Today();
	weekday.Tomorrow();
	weekday.Yesterday();
	cout << "How many days do you need to see ahead?" << endl;
	cin >> dayskip;
	weekday.DaysLater(dayskip);
	
	system("Pause");

}


dayType::dayType() {
	day = 0;
}
void dayType::SetDay(string newday) {
	for (int i = 0; i < 7; i++) {
		if (newday.compare(Days[i]) == 0) {
			day = i;
		}
	}
}
void dayType::PrintDay() {
	cout << "Today is "<< Days[day] << endl;
}
int dayType::Today() {
	cout << "Returning " << Days[(day)] << " For Today" << endl;

	return day;
}
int dayType::Tomorrow() {
	if (day != 6) {
		cout << "Returning " << Days[(day + 1)] << " For Tomorrow" << endl;
		return day + 1;
	}
	else if (day == 6) {
		cout << "Returning " << Days[0] << " For Tomorrow" << endl;
		return 0;
	}		
}
int dayType::Yesterday() {
	if (day != 0) {
		cout << "Returning " << Days[(day - 1)] << " For Yesterday" << endl;
		return day - 1;
	}
	else if (day == 0) {
		cout << "Returning " << Days[6] << " For Yesterday" << endl;
		return 6;
	}
}
int dayType::DaysLater(int skipdays) {
	cout << "In " << skipdays << " days, it will be " << Days[(day + skipdays) % 7] << endl;
	return (day + skipdays)%7;
}

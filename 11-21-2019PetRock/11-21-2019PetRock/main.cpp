//Made by TJ
#include <iostream>
#include <string>
using namespace std;

class Rock {//Creates class Rock
public://Functions
	Rock();//Fills with defaults
	void SetInfo(string n, double s, string t, int h);//Allows user to set Rock's info
	void PrintInfo();//Prints Rock's info
	void Pet();//Increases Rock happiness
	void Throw();//Decreases happiness
private:
	string name;//Names rock
	string type;//Determines rock's type
	double size;//Determines rock's size
	int happiness;//Determines rock's happiness
};


int main() {//Start of main
	string inputname;//String for name
	string inputtype;//String for type
	string command;//String for user interaction
	double inputn;//Number for size
	int basehappiness = 50;//Predetermined happiness
	Rock r1;//Creates a default rock
	cout << "Welcome to Tamagotchi Rock!  Please create a rock." << endl;//Introduces user to the program
	cout << "What is its name?" << endl;//Asks user to name the rock
	getline(cin, inputname);//User inputs rock's name
	cout << "Ok, what type of rock is it?" << endl;//Asks user to determine the rock's type
	getline(cin, inputtype);//User inputs rock's type
	cout << "What is its size?" << endl;//Asks user to input rock's size
	cin >> inputn;//User inputs rock's size
	r1.SetInfo(inputname, inputn, inputtype, basehappiness);//Sets user input to the rock
	cout << "Ok, get ready to take care of your rock.  You can use (pet) to pet your rock, and (throw) to throw it." << endl;//Commands
	cout << "Its stats can be seen with (info)." << endl;//Commands
	while (true) {//Game loop
		cout << "What would you like to do?" << endl;//Asks user for input
		getline(cin, command);//User input
		if (command.compare("pet") == 0) {//Checks if user inputs pet with no differences
			r1.Pet();//Calls Pet();
		}
		else if (command.compare("throw") == 0) {//Checks if user inputs throw with no differences
			r1.Throw();//Calls Throw();
		}
		else if (command.compare("info") == 0) {//Checks if user inputs pet with no differences
			r1.PrintInfo();//callse PrintInfo();
		}
		else {
			cout << "Sorry, I didn't quite catch that." << endl;//Error message
		}
	}
}

Rock::Rock() {//Constructor with default rock settings
	name = "Balboa";
	size = 24;
	type = "Granite";
	happiness = 100;

}
void Rock::SetInfo(string n, double s, string t, int h) {//Sets user input to class variables
	name = n;
	size = s;
	type = t;
	happiness = h;
}
void Rock::PrintInfo() {//Prints out class variables with context
	cout << "Your rock's name is " << name << "." << endl;
	cout << "Its size is " << size << " centimeters." << endl;
	cout << "Your rock's type is " << type << "." << endl;
	cout << "Its happiness score is " << happiness << "." << endl;
}
void Rock::Pet() {//Prints message and increases rock's happiness
	cout << "You pet your rock.  Its happiness has increased." << endl;
	happiness += 25;
}
void Rock::Throw() {//Prints message and decreases rock's happiness
	cout << "You throw your rock.  Its happiness has decreased." << endl;
	happiness -= 25;
}
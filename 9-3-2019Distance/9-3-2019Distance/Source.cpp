#include <iostream>
using namespace std;

double distance(double xpos1, double ypos1, double xpos2, double ypos2);

int main() {

	double x1 = 0;
	double y1 = 0;
	double x2 = 0;
	double y2 = 0;

	while (true) {
		cout << "What is the  first point's x position?" << endl;
		cin >> x1;

		cout << "Y position?" << endl;
		cin >> y1;

		cout << "Second x?" << endl;
		cin >> x2;

		cout << "Second y?" << endl;
		cin >> y2;


		cout << "So we have (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ")." << endl;
		if (distance(x1, y1, x2, y2) <= 10)
			cout << "These points are colliding." << endl;
		else
			cout << "These points are " << distance(x1, y1, x2, y2) << "units apart." << endl;

	}
	
}

double distance(double xpos1, double ypos1, double xpos2, double ypos2) {
	double dx = (xpos2 - xpos1) * (xpos2 - xpos1);
	double dy = (ypos2 - ypos1) * (ypos2 - ypos1);

	double dxy = sqrt(dx + dy);

	return dxy;

}

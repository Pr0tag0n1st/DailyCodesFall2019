#include <iostream>
#include <string>
using namespace std;

int Inventory[6] = { 0, 0, 0, 0, 0, 1 };
string InventoryItems[6];
int Funds = 500;

void Shop();

int main() {
	
	Shop();

}

void Shop() {
	int input;
	int ShopNums[5] = { 10, 10, 10, 10, 10 };
	string ShopItems[5] = { "Mana Potions", "Health Potions", "Arrows", "Bombs", "Swords" };
	int ShopPrices[5] = { 50, 25, 10, 100, 250 };
	int SellPrices[5] = { 25, 10, 1, 50, 100 };
	do {
		cout << "You're in the shop with " << Funds << " gold left." << endl;
		cout << "1) will show you the items for sale.  2) will allow you to purchase items." << endl;
		cout << "3) will show you your inventory.  4) will allow you to sell items to the shop." << endl;
		cout << "Press 0) to exit the shop." << endl;
		cin >> input;

		switch (input) {
		case 0:
			cout << "You are now leaving the shop." << endl;
			break;

		case 1:
			cout << "The items for sale are as follows:" << endl;
			for (int i = 0; i < 5; i++) {
				cout << ShopNums[i] << " " << ShopItems[i] << " for " << ShopPrices[i] << " gold." << endl;
			}
			break;
		case 2:
			cout << "Press 1) for Mana Potions, 2) for Health Potions, 3) for Arrows, 4) for Bombs, and 5) for swords" << endl;
			cout << "Press 0) if you'd rather not buy." << endl;
			cin >> input;
			if (input == 0) {
				input = 1;
				break;
			}
			if (ShopNums[input - 1] < 0) {
				cout << "We're out of that." << endl;
			}
			else if (ShopPrices[input-1] > Funds){
				cout << "Maybe you forgot, but you're broke." << endl;
			}
			else {
				Inventory[input - 1] += 1;
				InventoryItems[input - 1] = ShopItems[input - 1];
				ShopNums[input - 1] -= 1;
				Funds -= ShopPrices[input - 1];
				
			}
			break;
		case 3:
			cout << "Your inventory is as follows:" << endl;
			for (int i = 0; i < 6; i++){
				if (Inventory[i] > 0) {
					cout << Inventory[i] << " " << InventoryItems[i] << endl;
				}
			}
			break;
		case 4:
			cout << "You can sell:" << endl;
			for (int i = 0; i < 6; i++) {
				if (Inventory[i] > 0) {
					cout << Inventory[i] << " " << InventoryItems[i] << endl;
				}
			}
			cout << "Press 0 if you'd rather not sell." << endl;
			cin >> input;
			if (input == 0) {
				input = 1;
				break;
			}
			if (Inventory[input - 1] < 0) {
				cout << "You're out of that." << endl;
			}
			else if (ShopPrices[input - 1] > Funds) {
				cout << "Maybe you forgot, but you're broke." << endl;
			}
			else {
				Inventory[input - 1] -= 1;
				InventoryItems[input - 1] = ShopItems[input - 1];
				ShopNums[input - 1] += 1;
				Funds += (SellPrices[input - 1]);
			}
			break;
		default:
			cout << "What?" << endl;
		}
	} while (input != 0);

}
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

/*
* @author Bhavya Premachandran
* 
* this program will design a cafe billing system.
*/

//struct is used to store variables of different purpose.
struct menuItemType{
	string menuItem;    //contains the name of the item
	double menuPrice;	//stores the price of the item
	int inventoryCount;	//stores the number of each items
};

//declares the function prototypes
void initData(menuItemType menu[]);
void showMenu(menuItemType menu[]);
double calcAmt(menuItemType menu[], int i, int quantity);
void updateInventory(menuItemType menu[], int i, int quantity);
void printTotalBill(double total);

//the function initialize menu 
//function displays the menu choices
//the functions
int main() {
	menuItemType menu[8];	//declare variable to store 8 menuItemType
	char choice = 'y';
	double total = 0;	
	int item;
	int quantity;
	int count = 0;

	initData(menu);	//funcation call to initialize the menu
	cout << "Welcome to the cafe\n";
	showMenu(menu);	//displays menu
	while (choice == 'y') {
		cout << "Enter item number: ";	//item 
		cin >> item;
		cout << "Enter item quantity: ";	//item quantity
		cin >> quantity;
		if (menu[item].inventoryCount < quantity) {	//checks if item count is less than the required anount.
			cout << "Sorry this item is not available in this quantity, please choose another item\n\n";
		}
		else {
			double amount;
			amount = calcAmt(menu, item, quantity);
			cout << setprecision(2) << fixed << "Your total cost: $" << amount << endl;
			updateInventory(menu, item, quantity);
			total += amount;
		}
		cout << "Would you like to buy more item? Enter Y for 'yes' and N for'no: ";
		cin >> choice;
		count++;
	}
	printTotalBill(total);
	

	system("PAUSE");
	return 0;
}
//the function initializes the 8 menu options
void initData(menuItemType menu[]) {
	menu[0] = { "Plain Egg",1.99,20 };
	menu[1] = { "Bacon and Egg",3.45,20 };
	menu[2] = { "Muffin",2.99,20 };
	menu[3] = { "French Toast",4.99,20 };
	menu[4] = { "Fruit Basket",5.49,20 };
	menu[5] = { "Cereal",1.99,20 };
	menu[6] = { "Coffee",1.50,30 };
	menu[7] = { "Tea",1.25,30 };

}
//displays the menu using a for loop
void showMenu(menuItemType menu[]) {
	for (int i = 0; i < 8; i++) {
		cout << i+1 << ") ";
		cout << fixed << showpoint << setprecision(2);
		cout << left << fixed << setw(20);
		cout << menu[i].menuItem << "$" << menu[i].menuPrice << endl;
	}
	cout << "Select Item Number(0-7) and Quantities.\n" << endl;
}

//the function calculates the total amount of the purchase.
double calcAmt(menuItemType menu[], int i, int quantity) {
	return menu[i].menuPrice * quantity;
}

//update the item count after customer purchased
void updateInventory(menuItemType menu[], int i, int quantity) {
	menu[i].inventoryCount -= quantity;
}

//function display the total bill with 5% tax.
void printTotalBill(double total) {
	cout << "Total Bill AMOUNt: $";
	cout << fixed << showpoint << setprecision(2) << total * 1.05 << endl;
}
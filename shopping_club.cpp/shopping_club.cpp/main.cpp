#include<iostream>
#include<string>
#include<windows.h>

using namespace std;
void administator();
void customer();
void displayShoppingList();

struct node {
	int id;
	string name;
	double price;
	int amount;
	struct node* next;
};
struct node* head = NULL;
struct cart {
	int id;
	string name;
	string cuName;
	double totalPrice;
	int amount;
	struct cart* next;
};
struct cart* top = NULL;
void pushToCart(cart*& top, cart* newItem) {
	if (top == NULL) {
		newItem->next = top;
		top = newItem;
	}
	else {
		cart* current = top;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newItem;
		newItem->next = NULL;
	}
}
void addProduct() {
	int pid = 0,  pamount = 0;
	double pprice = 0;
	string pname;
	struct node* t = new node;
	struct node* p = head;
	cout << "\n\t\tEnter product ID >>> "; cin >> pid;
	t->id = pid;
	cout << "\n\t\tEnter product name >>> "; cin >> pname;
	t->name = pname;
	cout << "\n\t\tEnter product price >>> "; cin >> pprice;
	t->price = pprice;
	cout << "\n\t\tEnter product amount  >>> "; cin >> pamount;
	t->amount = pamount;

	if (head == NULL) {
		t->next = head;
		head = t;
	}
	else {
		while (p->next != NULL) {
			p = p->next;
		}p->next = t;
		t->next = NULL;
	}
	system("cls");
	cout << "\n\t\t|------New product was inserted-----|" << endl;
	
}
void display() {
	system("cls");
	struct node* p = head;
	cout << "\n\t\tID\tName\tPrice\tAmount" << endl;
	cout << "===========================================================" << endl;
	while (p != NULL) {
		cout << "\n\t\t"<< p->id << "\t" << p->name << "\t" << p->price << "\t" << p->amount << endl;
		p = p->next;
	}
	cout << "\n\n" << endl;
	
}
void modify() {
	int id, newPrice;
	double newAmount;
	string newName;
	system("cls");
	if (head == NULL) {
		cout << "\n\t\tList is empty" << endl;
	}
	else {
		display();
		struct node* curr = head;
		cout << "\n" << endl;
		cout << "\nEnter ID to modify the product >>>"; cin >> id;
		while (curr != NULL && curr->id != id) {
			curr = curr->next;
		}
		if (curr == NULL) {
			cout << "\n\t\tThere is no " << id << endl;
			Sleep(2000);
			administator();
		}
		else {
			cout << "\nEnter new name >>>"; cin >> newName;
			curr->name = newName;
			cout << "\nEnter new price >>>"; cin >> newPrice;
			curr->price = newPrice;
			cout << "\nEnter new amount >>>"; cin >> newAmount;
			curr->amount = newAmount;
			display();

		}
	}
}
void deleteProduct() {
	int id;
	
	if (head == NULL) {
		cout << "\n\t\tList is empty" << endl;
	}
	else {
		display();
		struct node* curr = head;
		struct node* temp = head;
		struct node* delPtr = NULL;
		cout << "\nEnter ID to delete the product >>>"; cin >> id;
	
		while (curr != NULL && curr->id != id) {
			temp = curr;
			curr = curr->next;
		}
		if (curr == NULL) {
			cout << "\n\t\tThere is no " << id << endl;
			Sleep(2000);
			administator();
		}
		else {
			delPtr = curr;
			curr = curr->next;
			temp->next = curr;
			if (delPtr == head) {
				head = head->next;
				temp = NULL;
			}
			delete delPtr;
			cout << "\n" << id << " was deleted" << endl;
			Sleep(1000);
			display();
		}

	}

}
/////////////////////////////////////////////////////////////////
void shopping() {
	string cuName;
	int Id;
	double cuAmount;
	struct node* curr = head;
	struct cart* now = top;
	struct cart* temp = new cart;

	display();
	cout << "\nEnter your name first >>>"; cin >> cuName;
	temp->cuName = cuName;
	cout << "\nEnter id of product that you want to buy >>>"; cin >> Id;
	while (curr != NULL && curr->id != Id) {
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << "\n\t\tThere is no " << Id << endl;
		Sleep(2000);
		customer();
	}
	temp->id = Id;
	cout << "\nEnter the amount >>>"; cin >> cuAmount;
	temp->amount = cuAmount;
	if (head == NULL) {
		cout << "\nThere is nothing to buy" << endl;
	}  
	else {
		while (curr != NULL && curr->id != Id) {
			curr = curr->next;
		}
		if (curr == NULL) {
			cout << "\n\t\tThere is no " << Id << endl;
			Sleep(2000);
			system("cls");
			shopping();
		}
		else {
			curr->amount = curr->amount - cuAmount;
			temp->totalPrice = cuAmount * (curr->price);
			pushToCart(top,temp);
		}  
	}displayShoppingList();
}
void displayShoppingList() {
	system("cls");
	struct cart* t = top;
	struct node* p = head;
	cout << "\n\tCustomer Name\tProduct Name\tAmount\tTotalPrice" << endl;
	cout << "=====================================================================" << endl;
	while (t != NULL) {
		t->id = p->id;
		cout << "\n\t\t" << t->id << "\t" << p->name << "\t\t" << t->amount << "\t\t" << t->totalPrice << endl;
		t = t->next;

	};
	cout << "\n\n" << endl;

}
/////////////////////////////////////////////////////////////////
void administator() {
	system("cls");
	int adChoice = 0;
	do {
		cout << "\n\t\t|------Administator-----|" << endl;
		cout << "\n\t\t1. Add a new product" << endl;
		cout << "\n\t\t2. Display all products" << endl;
		cout << "\n\t\t3. Modify existing product" << endl;
		cout << "\n\t\t4. Delete a product" << endl;
		cout << "\n\t\t5. Customer list" << endl;
		cout << "\n\t\t0. Back to main menu" << endl;

		cout << "\nEnter your choice >>>"; cin >> adChoice;
		switch (adChoice) {
		case 1:
			system("cls");
			addProduct();
			break;
		case 2:
			system("cls");
			display();
			break;
		case 3:
			system("cls");
			modify();
			break;
		case 4:
			system("cls");
			deleteProduct();
			break;
		case 5:
			system("cls");
			displayShoppingList();
			break;
		default:
			system("cls");
		}	
	} while (adChoice !=0);	
}
/////////////////////////////////////////////////////////////////
void customer() {
	system("cls");
	int cuChoice = 0;
	do {
		cout << "\n\t\t|------Customer-----|" << endl;
		cout << "\n\t\t1. Shopping" << endl;
		cout << "\n\t\t2. Check my shopping list" << endl;
		cout << "\n\t\t0. Back to main menu" << endl;

		cout << "\nEnter your choice >>>"; cin >> cuChoice;
		switch (cuChoice) {
		case 1:
			system("cls");
			shopping();
			break;
		case 2:
			system("cls");
			displayShoppingList();
			break;
			
		default:
			system("cls");
		}
	} while (cuChoice != 0);
}
/////////////////////////////////////////////////////////////////

int main() {
	int choice = 0;
	do {
		cout << "\n\t\t|------Welcome to shopping club-----|" << endl;
		cout << "\n\t\t|------Main Menu-----|" << endl;
		cout << "\n\t\t1. Administator Of Market" << endl;
		cout << "\n\t\t2. Customer" << endl;
		cout << "\n\t\t3. Exit" << endl;

		cout << "\nEnter your choice >>>"; cin >> choice;
		switch (choice) {
		case 1:
			administator();
			break;
		case 2:
			customer();
			break;
		case 3:
			cout << "\nSee you next time" << endl;
			break;
		default:
			cout << "choose the correct number" << endl;
		}

	} while (choice != 3);
	return 0;
}
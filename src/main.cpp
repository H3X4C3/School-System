#include "main.h"
#include "person.h"
#include "admin.h"

#include <string>
#include <Windows.h>
#include <iostream>
#include <db/db_read.h>
#include <db/db_write.h>
using namespace std;

#define CLEAR system("cls");

void cleanup();
void login();
bool check_account(ifstream stream);

struct INPUTS {
	bool stop = false;
	string choice;
	string username, password;
} input;

// MAIN FUNCTION
int main() {
	connect_db();

	while (input.stop != true) {
		print_menu();
		getline(cin, input.choice);
		int choice_int = stoi(input.choice);

		switch (choice_int) {
		case 1:
			CLEAR;
			break;
		case 2:

			break;
		case 3:

			break;
		default:

			break;
		}
	}

	cleanup();
	return 0;
}

// OTHER FUNCTIONS
void cleanup() {
	delete result;
	delete statement;
	delete con;
}

void login() {
	login_menu();
	getline(cin, input.choice);
	int choice_int = stoi(input.choice);

	switch (choice_int) {
	case 1:
		CLEAR;
		PRINT("Username: ");
		getline(cin, input.username);
		PRINT("Password: ");
		getline(cin, input.password);


		break;
	case 2:

		break;
	case 0:
		break;
	default:
		CLEAR;
		PRINT("Invalid choice, please try again");
		Sleep(2000);
		CLEAR;
		break;
	}
}
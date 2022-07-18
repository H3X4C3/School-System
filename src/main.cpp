#include "main.h"
#include "person.h"
#include "admin.h"

#include <fstream>
#include <string>
#include <Windows.h>
#include <iostream>
#include <db/db_read.h>
#include <db/db_write.h>
using namespace std;

#define CLEAR system("cls");
#define WAIT Sleep(2000);

void cleanup();
void login();
void register_user();
void create_acc(string role, string& username, string& password);

bool check_password(string role, string& username, string& password);
bool has_account(string role, string& username);

struct INPUTS {
	bool stop = false;
	string choice;
	string username, password;
} input;

// This can be changed by the programmer depending on what directory they wish to save
// account files on
const string dir = "C:\\Users\\Administrator\\Documents\\Visual Studio 2022\\C++ Projects\\school system\\data\\users";

// MAIN FUNCTION ==============================================================================================
int main() {
	connect_db();

	while (input.stop != true) {
		print_menu();
		getline(cin, input.choice);
		int choice_int = stoi(input.choice);

		switch (choice_int) {
		case 1:
			CLEAR;
			login();
			break;
		case 2:
			CLEAR;
			register_user();
			break;
		case 0:
			CLEAR;
			input.stop = true;
			PRINTLN("Goodbye!");
			WAIT;
			break;
		default:
			CLEAR;
			PRINTLN("Goodbye!");
			break;
		}
	}

	cleanup();
	return 0;
}

// OTHER FUNCTIONS =============================================================================================
void cleanup() {
	delete result;
	delete statement;
	delete con;
}

bool check_password(string role, string& username, string& password) { // check passwords
	string pw_check;
	ifstream reader(dir + "\\" + role + "\\" + username + ".txt");
	
	while (getline(reader, pw_check)) {
		if (pw_check == password) {
			reader.close();
			return true;
		}
	}

	reader.close();
	return false;
}

bool has_account(string role, string& username) { // check if an account already exists
	string user_check;
	ifstream file;
	file.open(dir + "\\" + role + "\\" + username + ".txt");

	if (!file) {
		file.close();
		return false;
	}

	file.close();
	return true;
}

void create_acc(string role, string& username, string& password) { // create accounts
	ofstream file(dir + "\\" + role + "\\" + username + ".txt");
	file << username << endl << password << endl;
	file.close();
}

void login() {
	login_menu();
	getline(cin, input.choice);
	int choice_int = stoi(input.choice);

	switch (choice_int) {
	case 1:
		CLEAR;
		PRINTLN("\t\tLogin\n");
		PRINT("Username: ");
		getline(cin, input.username);
		PRINT("Password: ");
		getline(cin, input.password);

		if (!(check_password("admins", input.username, input.password) == true)) { // check if passwords match
			PRINTLN("\nUsername or password is incorrect. Please try again.");
			WAIT;
			CLEAR;
			break;
		}

		PRINTLN("\nSuccessfully logged in as " + input.username + "!");
		WAIT;
		CLEAR;
		break;
	case 2:
		CLEAR;
		PRINTLN("\t\tLogin\n");
		PRINT("Username: ");
		getline(cin, input.username);
		PRINT("Password: ");
		getline(cin, input.password);

		if (!(check_password("teachers", input.username, input.password) == true)) {
			PRINTLN("\nUsername or password is incorrect. Please try again.");
			WAIT;
			CLEAR
			break;
		}

		PRINTLN("\nSuccessfully logged in as " + input.username + "!");
		WAIT;
		CLEAR;
		break;
	case 0:
		CLEAR;
		break;
	default:
		CLEAR;
		PRINT("Invalid choice, please try again");
		WAIT;
		CLEAR;
		break;
	}
}

void register_user() {
	register_menu();
	getline(cin, input.choice);
	int choice_int = stoi(input.choice);

	string confirmation; // stores the input of 'Confirm Password' field

	switch (choice_int) {
	case 1:
		CLEAR;
		PRINTLN("\t\tRegister Account\n");
		PRINT("Username: ");
		getline(cin, input.username);
		PRINT("Password: ");
		getline(cin, input.password);
		PRINT("Confirm Password: ");
		getline(cin, confirmation);

		if (has_account("admins", input.username)) { // checks the usernames if they are already taken
			PRINTLN("\nThat username already exists, please use a different one.");
			WAIT;
			CLEAR;
			break;
		}
		if (confirmation == input.password) { // compare the two entered passwords
			create_acc("admins", input.username, input.password);
			PRINTLN("\nAccount successfully created. An administrator will have to approve your account,\nwhich may take some time.");
			WAIT;
			CLEAR;
			break;
		}

		PRINTLN("\nPassword confirmation failed. Please try again.");
		WAIT;
		CLEAR;
		break;
	case 2:
		CLEAR;
		PRINTLN("\t\tRegister Account\n");
		PRINT("Username: ");
		getline(cin, input.username);
		PRINT("Password: ");
		getline(cin, input.password);
		PRINT("Confirm Password: ");
		getline(cin, confirmation);

		if (has_account("teachers", input.username)) {
			PRINTLN("\nThat username already exists, please use a different one.");
			WAIT;
			CLEAR;
			break;
		}
		if (confirmation == input.password) {
			create_acc("teachers", input.username, input.password);
			PRINTLN("\nAccount successfully created. An administrator will have to approve your account,\nwhich may take some time.");
			WAIT;
			CLEAR;
			break;
		}

		PRINTLN("\nPassword confirmation failed. Please try again.");
		WAIT;
		CLEAR;
		break;
	case 0:
		CLEAR;
		break;
	default:
		CLEAR;
		PRINT("Invalid choice, please try again");
		WAIT;
		break;
	}
}
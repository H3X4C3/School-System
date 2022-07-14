#include "admin.h"

#include <string>
#include <ctime>
using namespace std;

Admin::Admin(string first_name, string surname, int age, string email): Person(first_name, surname, age) {
	this->email = email;

	new_id();
}

// GETTERS
string Admin::get_email() {
	return this->email;
}

int Admin::get_id() {
	return this->admin_id;
}

// SETTERS
void Admin::set_email(string email) {
	this->email = email;
}

void Admin::new_id() {
	srand((unsigned)time(0));
	this->admin_id = 1 + (rand() % 999);
}

// OTHER FUNCTIONS
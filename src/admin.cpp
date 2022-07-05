#include "admin.h"

#include <string>
#include <ctime>
using namespace std;

Admin::Admin(string name, int age, string email) {
	this->name = name;
	this->age = age;
	this->email = email;

	new_id();
}

// GETTERS
string Admin::get_name() {
	return this->name;
}

string Admin::get_email() {
	return this->email;
}

int Admin::get_age() {
	return this->age;
}

int Admin::get_id() {
	return this->admin_id;
}

// SETTERS
void Admin::set_age(int age) {
	this->age = age;
}

void Admin::set_email(string email) {
	this->email = email;
}

void Admin::set_name(string name) {
	this->name = name;
}

void Admin::new_id() {
	srand((unsigned)time(0));
	this->admin_id = 1 + (rand() % 999);
}

// OTHER FUNCTIONS

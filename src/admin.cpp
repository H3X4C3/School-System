#include "admin.h"

#include <string>
#include <ctime>
using namespace std;

Admin::Admin(string first_name, string surname, int age, string email) {
	this->first_name = first_name;
	this->surname = surname;
	this->age = age;
	this->email = email;

	new_id();
}

// GETTERS
string Admin::get_first_name() {
	return this->first_name;
}

string Admin::get_surname() {
	return this->surname;
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

void Admin::set_first_name(string first_name) {
	this->first_name = first_name;
}

void Admin::set_surname(string surname) {
	this->surname = surname;
}

void Admin::new_id() {
	srand((unsigned)time(0));
	this->admin_id = 1 + (rand() % 999);
}

// OTHER FUNCTIONS

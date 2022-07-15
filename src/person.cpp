#include "person.h"

#include <string>
#include <ctime>
using namespace std;

Person::Person(string first_name, string surname, string dob, string email) {
	this->first_name = first_name;
	this->surname = surname;
	this->dob = dob;
	this->email = email;

	new_id();
}

// GETTERS
string Person::get_first_name() {
	return this->first_name;
}

string Person::get_surname() {
	return this->surname;
}

string Person::get_dob() {
	return this->dob;
}

int Person::get_id() {
	return this->id;
}

string Person::get_email() {
	return this->email;
}

// SETTERS
void Person::set_first_name(string name) {
	this->first_name = name;
}

void Person::set_surname(string name) {
	this->surname = name;
}

void Person::set_email(string email) {
	this->email = email;
}

void Person::set_dob(string dob) {
	this->dob = dob;
}

void Person::new_id() {
	srand((unsigned)time(0));
	this->id = 1 + (rand() % 999);
}
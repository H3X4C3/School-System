#include "person.h"

#include <string>
using namespace std;

Person::Person(string first_name, string surname) {
	this->first_name = first_name;
	this->surname = surname;
}

// GETTERS
string Person::get_first_name() {
	return this->first_name;
}

string Person::get_surname() {
	return this->surname;
}

// SETTERS
void Person::set_first_name(string name) {
	this->first_name = name;
}

void Person::set_surname(string name) {
	this->surname = name;
}
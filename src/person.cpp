#include "person.h"

#include <string>
#include <iostream>
using namespace std;

Person::Person(string first_name, string surname, int age) {
	this->first_name = first_name;
	this->surname = surname;
	this->age = age;
}

// GETTERS
string Person::get_first_name() {
	return this->first_name;
}

string Person::get_surname() {
	return this->surname;
}

int Person::get_age() {
	return this->age;
}

// SETTERS
void Person::set_first_name(string name) {
	this->first_name = name;
}

void Person::set_surname(string name) {
	this->surname = name;
}

void Person::set_age(int age) {
	this->age = age;
}
#include "teacher.h"

#include <string>
#include <ctime>
using namespace std;

Teacher::Teacher(string name, int age, string email) {
	this->name = name;
	this->age = age;
	this->email = email;

	new_id();
}

// GETTERS
string Teacher::get_name() {
	return this->name;
}

string Teacher::get_email() {
	return this->email;
}

int Teacher::get_id() {
	return this->teacher_id;
}

int Teacher::get_age() {
	return this->age;
}

// SETTERS
void Teacher::new_id() {
	srand((unsigned)time(0));
	this->teacher_id = 1 + (rand() % 999);
}

void Teacher::set_age(int age) {
	this->age = age;
}

void Teacher::set_email(string email) {
	this->email = email;
}

void Teacher::set_name(string name) {
	this->name = name;
}
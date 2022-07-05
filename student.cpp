#include "student.h"

#include <ctime>
#include <random>
using namespace std;

Student::Student(string name, int age, string email) {
	this->name = name;
	this->age = age;
	this->email = email;

	new_id();
	//srand((unsigned)time(0));
	//this->student_id = 1 + (rand() % 999);
}

// GETTERS
string Student::get_name() {
	return this->name;
}

string Student::get_email() {
	return this->email;
}

int Student::get_age() {
	return this->age;
}

int Student::get_id() {
	return this->student_id;
}

int Student::get_gpa() {
	return this->gpa;
}

// SETTERS
void Student::set_age(int age) {
	this->age = age;
}

void Student::set_name(string name) {
	this->name = name;
}

void Student::new_id() {
	srand((unsigned)time(0));
	this->student_id = 1 + (rand() % 999);
}

void Student::set_email(string email) {
	this->email = email;
}

// OTHER FUNCTIONS

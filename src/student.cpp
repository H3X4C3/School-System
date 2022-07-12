#include "student.h"

#include <ctime>
#include <random>
using namespace std;

Student::Student(string first_name, string surname, int age, string email) {
	this->first_name = first_name;
	this->surname = surname;
	this->age = age;
	this->email = email;

	new_id();
	//srand((unsigned)time(0));
	//this->student_id = 1 + (rand() % 999);
}

// GETTERS
string Student::get_first_name() {
	return this->first_name;
}

string Student::get_surname() {
	return this->surname;
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

double Student::get_gpa() {
	return this->gpa;
}

// SETTERS
void Student::set_age(int age) {
	this->age = age;
}

void Student::set_first_name(string first_name) {
	this->first_name = first_name;
}

void Student::set_surname(string surname) {
	this->surname = surname;
}

void Student::new_id() {
	srand((unsigned)time(0));
	this->student_id = 1 + (rand() % 999);
}

void Student::set_email(string email) {
	this->email = email;
}

// OTHER FUNCTIONS

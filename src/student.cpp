#include "student.h"
using namespace std;

Student::Student(string first_name, string surname, string dob, double gpa, int level): Person(first_name, surname, dob) {
	this->gpa = gpa;
	this->level = level;
}

// GETTERS
double Student::get_gpa() {
	return this->gpa;
}

int Student::get_level() {
	return this->level;
}
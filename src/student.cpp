#include "student.h"

#include <vector>
using namespace std;

Student::Student(string first_name, string surname, string dob, double gpa, int level): Person(first_name, surname) {
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

string Student::get_dob() {
	return this->dob;
}

string Student::get_firstname() {
	return this->first_name;
}

string Student::get_surname() {
	return this->surname;
}

string Student::get_name() {
	return this->first_name + " " + this->surname;
}

int Student::get_id() {
	return this->student_id;
}

vector<Student> Student::get_student_list() {
	return this->student_list;
}
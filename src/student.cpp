#include "student.h"

#include <algorithm>
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

vector<int> Student::get_id_list() {
	return this->id_list;
}

// SETTERS
void Student::set_firstname(string first_name) {
	this->first_name = first_name;
}

void Student::set_surname(string surname) {
	this->surname = surname;
}

void Student::set_dob(string dob) {
	this->dob = dob;
}

int Student::new_id() {
	int id;
	sort(id_list.begin(), id_list.end());
	if (id_list.empty()) return id = 1; // check if id_list is empty

	// if not, increment the last element of vector and return
	id = id_list.back();
	return id++;
}

// OTHERS
bool Student::add_student(Student& student) {
	for (Student& elem : student_list) {
		if (elem.get_id() == student.get_id()) return false;
	}

	student_list.push_back(student);
	return true;
}

void Student::add_id(int id) {
	id_list.push_back(id);
}
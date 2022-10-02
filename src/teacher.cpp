#include "teacher.h"
#include "person.h"

#include <string>
#include <vector>
using namespace std;

Teacher::Teacher(string first_name, string surname, string dob, string email) : Person(first_name, surname) {
	this->dob = dob;
	this->email = email;
}

Teacher::Teacher(string first_name, string surname, string dob, string email, int id) : Person(first_name, surname) {
	this->dob = dob;
	this->email = email;
	this->id = id;
}

// GETTERS
string Teacher::get_name() {
	return this->first_name + " " + this->surname;
}

string Teacher::get_firstname() {
	return this->first_name;
}

string Teacher::get_surname() {
	return this->surname;
}

string Teacher::get_dob() {
	return this->dob;
}

string Teacher::get_email() {
	return this->email;
}

int Teacher::get_id() {
	return this->id;
}

vector<Teacher> Teacher::get_teacher_list() {
	return this->teacher_list;
}

Student Teacher::get_student(int id) {
	Student obj;
	for (Student& elem : obj.get_student_list()) {
		if (elem.get_id() == id) return elem;
	}

	throw "student_id does not exist";
}

// SETTERS

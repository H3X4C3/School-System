#include "teacher.h"
#include "person.h"
#include "db/db_read.h"

#include <string>
using namespace std;

Teacher::Teacher(string first_name, string surname, string dob, string email) : Person(first_name, surname) {
	this->dob = dob;
	this->email = email;
}

Teacher::Teacher(string first_name, string surname, string dob, string email, int id) : Person(first_name, surname) {
	this->dob = dob;
	this->email = email;
	this->teacher_id = id;
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
	return this->teacher_id;
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

int Teacher::get_student_level(Student& student) {
	return get_entry<int>(student.get_id(), "student", "level");
}

double Teacher::get_student_gpa(Student& student) {
	return get_entry<double>(student.get_id(), "student", "gpa");
}

// SETTERS
void Teacher::set_dob(string dob) {
	this->dob = dob;
}

void Teacher::set_email(string email) {
	this->email = email;
}

void Teacher::set_firstname(string first_name) {
	this->first_name = first_name;
}

void Teacher::set_surname(string surname) {
	this->surname = surname;
}

int Teacher::new_id() {
	int id;
	sort(id_list.begin(), id_list.end());
	if (id_list.empty()) return id = 1; // check if id_list is empty

	// if not, increment the last element of vector and return
	id = id_list.back();
	return id++;
}

// OTHERS
bool Teacher::add_teacher(Teacher& teacher) {
	for (Teacher& elem : teacher_list) {
		if (elem.get_id() == teacher.get_id()) return false;
	}

	teacher_list.push_back(teacher);
	return true;
}

void Teacher::add_id(int id) {
	id_list.push_back(id);
}
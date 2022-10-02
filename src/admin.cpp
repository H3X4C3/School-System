#include "admin.h"
#include "person.h"
#include "teacher.h"
#include "student.h"

#include <string>
#include <ctime>
using namespace std;

Admin::Admin(string first_name, string surname, string dob, string email) : Person(first_name, surname) {
	this->dob = dob;
	this->email = email;
}

Admin::Admin(string first_name, string surname, string dob, string email, int id) : Person(first_name, surname) {
	this->dob = dob;
	this->email = email;
	this->admin_id = id;
}

// GETTERS
Admin Admin::get_admin(int id) {
	for (Admin& elem : admin_list) {
		if (elem.get_id() == id) return elem;
	}

	throw "admin_id does not exist";
}

Teacher Admin::get_teacher(int id) {
	Teacher obj;
	for (Teacher& elem : obj.get_teacher_list()) {
		if (elem.get_id() == id) return elem;
	}

	throw "teacher_id does not exist";
}

Student Admin::get_student(int id) {
	Student obj;
	for (Student& elem : obj.get_student_list()) {
		if (elem.get_id() == id) return elem;
	}

	throw "student_id does not exist";
}

vector<Admin> Admin::get_admin_list() {
	return this->admin_list;
}

string Admin::get_name() {
	return this->first_name + " " + this->surname;
}

string Admin::get_firstname() {
	return this->first_name;
}

string Admin::get_surname() {
	return this->surname;
}

string Admin::get_dob() {
	return this->dob;
}

string Admin::get_email() {
	return this->email;
}

int Admin::get_id() {
	return this->admin_id;
}

// SETTERS
void Admin::set_firstname(string first_name) {
	this->first_name = first_name;
}

void Admin::set_surname(string surname) {
	this->surname = surname;
}

void Admin::set_dob(string dob) {
	this->dob = dob;
}

void Admin::set_email(string email) {
	this->email = email;
}

int Admin::new_id() {
	return 0;
}

// OTHERS
bool Admin::add_admin(Admin admin) {
	for (Admin& elem : admin_list) {
		if (!(elem.get_id() == admin.get_id())) {
			admin_list.push_back(admin);
			return true;
		}
	}

	return false;
}
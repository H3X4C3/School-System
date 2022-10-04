#include "admin.h"
#include "person.h"
#include "teacher.h"
#include "student.h"
#include "db/db_read.h"

#include <string>
#include <algorithm>
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
	int id;
	sort(id_list.begin(), id_list.end());
	if (id_list.empty()) return id = 1; // check if id_list is empty

	// if not, increment the last element of vector and return
	id = id_list.back();
	return id++;
}

// OTHERS
bool Admin::add_admin(Admin& admin) {
	for (Admin& elem : admin_list) {
		if (elem.get_id() == admin.get_id()) return false;
	}
	admin_list.push_back(admin);
	return true;
}

void Admin::add_id(int id) {
	id_list.push_back(id);
}

bool Admin::remove_admin(Admin& admin) {
	for (Admin& elem : admin_list) {
		if (elem.get_id() == admin.get_id()) {
			admin_list.erase(find(admin_list.begin(), admin_list.end(), elem)); // find elem and remove it from vector
			return true;
		}
	}

	return false;
}

bool Admin::remove_teacher(Teacher& teacher) {
	vector<Teacher> vtr = teacher.get_teacher_list();
	for (Teacher& elem : vtr) {
		if (elem.get_id() == teacher.get_id()) {
			vtr.erase(find(vtr.begin(), vtr.end(), elem));
			return true;
		}
	}

	return false;
}

bool Admin::remove_student(Student& student) {
	vector<Student> vtr = student.get_student_list();
	for (Student& elem : vtr) {
		if (elem.get_id() == student.get_id()) {
			vtr.erase(find(vtr.begin(), vtr.end(), elem));
			return true;
		}
	}

	return false;
}

void Admin::print_admins() {
	print_table("administrator");
}

void Admin::print_teachers() {
	print_table("teacher");
}

void Admin::print_students() {
	print_table("student");
}
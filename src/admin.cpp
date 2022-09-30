#include "admin.h"
#include "person.h"

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
	this->id = id;
}

// GETTERS
Admin Admin::get_admin(int &id) {
	for (auto& elem : admin_list) {
		if (elem.get_id() == id) return elem;
	}

	throw "ID does not exist";
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
	return this->id;
}

// SETTERS

// OTHERS
int Admin::new_id() {

}
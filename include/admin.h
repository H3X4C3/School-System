#pragma once
#include "teacher.h"
#include "person.h"

#include <string>
#include <vector>
using namespace std;

class Admin: public Person {
private:
	string first_name;
	string surname;
	string email;
	string dob;
	int id = 0;

	vector<Admin> admin_list;
	vector<int> id_list;

public:
	Admin() {};
	Admin(string first_name, string surname, string dob, string email);
	Admin(string first_name, string surname, string dob, string email, int id);

	// GETTERS
	string get_name();
	string get_firstname();
	string get_surname();
	string get_dob();
	string get_email();
	int get_id();
	Admin get_admin(int& id);
	vector<Admin> get_admin_list();
	Teacher get_teacher(int& id);
	Student get_student(int& id);

	// SETTERS
	void set_firstname(string& firstname);
	void set_surname(string& surname);
	void set_id(int& id);
	void set_email(string& email);
	void set_dob(string& dob);
	int new_id();

	// OTHER
	void print_admins();
	void print_teachers();
	void print_students();
};
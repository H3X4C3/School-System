#pragma once
#include "teacher.h"
#include "student.h"
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
	int admin_id = 0;

	vector<Admin> admin_list;
	vector<int> id_list;

public:
	Admin() {};
	Admin(string first_name, string surname, string dob, string email);
	Admin(string first_name, string surname, string dob, string email, int id);
	~Admin() {};

	// GETTERS
	string get_name();
	string get_firstname();
	string get_surname();
	string get_dob();
	string get_email();
	int get_id();
	Admin get_admin(int id);
	vector<Admin> get_admin_list();
	Teacher get_teacher(int id);
	Student get_student(int id);

	// SETTERS
	void set_firstname(string first_name);
	void set_surname(string surname);
	int new_id();
	void set_email(string email);
	void set_dob(string dob);

	// OTHER
	bool add_admin(Admin& admin);
	bool remove_student(Student& student);
	bool remove_teacher(Teacher& teacher);
	bool remove_admin(Admin& admin);
	void add_id(int id);
	void print_admins();
	void print_teachers();
	void print_students();
};
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

public:
	Admin(string first_name, string surname, string dob, string email);

	void print_admins();
	void print_teachers();
	void print_students();

	Admin get_admin(int id);
	Admin get_admin_list();
	Teacher get_teacher(int id);
	Student get_student(int id);
};
#pragma once
#include "teacher.h"

#include <string>
using namespace std;

class Admin {
private:
	string name;
	string email;
	int age;
	int admin_id;

public:
	Admin(string name, int age, string email);

	string get_name();
	string get_email();
	int get_age();
	int get_id();

	void set_name(string name);
	void set_email(string email);
	void set_age(int age);
	void new_id();

	Teacher get_teacher(string name);
};
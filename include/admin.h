#pragma once
#include "teacher.h"
#include "person.h"

#include <string>
using namespace std;

class Admin: public Person {
private:
	string first_name;
	string surname;
	string email;
	int age;
	int admin_id;

public:
	Admin(string first_name, string surname, int age, string email);

	string get_email();
	int get_id();

	void set_email(string email);
	void new_id();
};
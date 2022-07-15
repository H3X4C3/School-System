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
	string dob;
	int id = 0;

public:
	Admin(string first_name, string surname, string dob, string email);
};
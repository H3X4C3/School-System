#pragma once
#include <string>
using namespace std;

class Person {
private:
	string first_name;
	string surname;
	string email;
	string dob;
	int id = 0;

public:
	Person(string first_name, string surname, string dob, string email);

	string get_first_name();
	string get_surname();
	string get_dob();
	string get_email();
	int get_id();

	void set_first_name(string name);
	void set_surname(string name);
	void set_dob(string dob);
	void set_email(string email);
	void new_id();
};
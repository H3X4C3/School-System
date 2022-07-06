#pragma once
#include <string>
using namespace std;

class Teacher {
private:
	string first_name;
	string surname;
	string email;
	int age;
	int teacher_id;

public:
	Teacher(string first_name, string surname, int age, string email);

	string get_first_name();
	string get_surname();
	string get_email();
	int get_age();
	int get_id();

	void set_first_name(string first_name);
	void set_surname(string surname);
	void set_email(string email);
	void set_age(int age);
	void new_id();
};
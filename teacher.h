#pragma once
#include <string>
using namespace std;

class Teacher {
private:
	string name;
	string email;
	int age;
	int teacher_id;

public:
	Teacher(string name, int age, string email);

	string get_name();
	string get_email();
	int get_age();
	int get_id();

	void set_name(string name);
	void set_email(string email);
	void set_age(int age);
	void new_id();
};
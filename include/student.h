#pragma once
#include <string>
using namespace std;

class Student {
private:
	string name;
	string email;
	int age;
	int student_id;
	int gpa;

public:
	Student(string name, int age, string email);

	string get_name();
	string get_email();
	int get_id();
	int get_age();
	int get_gpa();

	void set_name(string name);
	void set_age(int age);
	void new_id();
	void set_email(string email);
};
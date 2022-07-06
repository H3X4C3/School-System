#pragma once
#include <string>
using namespace std;

class Student {
private:
	string first_name;
	string surname;
	string email;
	int age;
	int student_id;
	int gpa;

public:
	Student(string first_name, string surname, int age, string email);

	string get_first_name();
	string get_surname();
	string get_email();
	int get_id();
	int get_age();
	int get_gpa();

	void set_first_name(string first_name);
	void set_surname(string surname);
	void set_age(int age);
	void new_id();
	void set_email(string email);
};
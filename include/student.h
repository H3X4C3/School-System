#pragma once
#include "person.h"

#include <string>
using namespace std;

class Student: public Person {
private:
	string first_name;
	string surname;
	string email;
	int age;
	int student_id;
	double gpa;

public:
	Student(string first_name, string surname, int age, double gpa);

	int get_id();
	double get_gpa();

	void new_id();
};
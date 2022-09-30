#pragma once
#include "person.h"

#include <string>
using namespace std;

class Student: public Person {
private:
	string first_name;
	string surname;
	string dob;
	double gpa = 0.0;
	int level = 1;
	int id = 0;

public:
	Student(string first_name, string surname, string dob, double gpa, int level);

	double get_gpa();
	int get_level();
	int get_id();
	string get_dob();
};
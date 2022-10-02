#pragma once
#include "person.h"

#include <string>
#include <vector>
using namespace std;

class Student : public Person {
private:
	string first_name;
	string surname;
	string dob;
	double gpa = 0.0;
	int level = 1;
	int student_id = 0;

	vector<Student> student_list;
	vector<int> id_list;

public:
	Student() {};
	Student(string first_name, string surname, string dob, double gpa, int level);
	~Student() {};

	// GETTERS
	double get_gpa();
	int get_level();
	int get_id();
	string get_dob();
	string get_firstname();
	string get_surname();
	string get_name();
	vector<Student> get_student_list();

	// SETTERS
	void set_gpa(int gpa);
	void set_level(int level);
	int new_id();
	void set_dob(string dob);
	void set_firstname(string first_name);
	void set_surname(string surname);

	// OTHERS
	bool add_student(Student student);
};
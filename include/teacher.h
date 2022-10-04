#pragma once
#include "student.h"
#include "person.h"

#include <string>
#include <vector>
using namespace std;

class Teacher : public Person {
private:
	string first_name;
	string surname;
	string email;
	string dob;
	int teacher_id = 0;

	vector<Teacher> teacher_list;
	vector<int> id_list;

public:
	Teacher() {};
	Teacher(string first_name, string surname, string dob, string email);
	Teacher(string first_name, string surname, string dob, string email, int id);
	~Teacher() {};

	// GETTERS
	string get_name();
	string get_firstname();
	string get_surname();
	string get_dob();
	string get_email();
	int get_id();
	int get_student_level(Student& student);
	double get_student_gpa(Student& student);
	vector<Teacher> get_teacher_list();
	Student get_student(int id);

	// SETTERS
	void set_firstname(string first_name);
	void set_surname(string surname);
	void set_dob(string dob);
	void set_email(string email);
	int new_id();

	// OTHERS
	bool add_teacher(Teacher& teacher);
	void add_id(int id);
};
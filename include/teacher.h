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
	int id = 0;

	vector<Teacher> teacher_list;
	vector<int> id_list;

public:
	Teacher() {};
	Teacher(string first_name, string surname, string dob, string email);
	Teacher(string first_name, string surname, string dob, string email, int id);

	// GETTERS
	string get_name();
	string get_firstname();
	string get_surname();
	string get_dob();
	string get_email();
	int get_id();
	Student get_student_obj(int id);
	string get_student_name(Student student);
	double get_student_gpa(Student student);
	string get_student_email(Student student);
	int get_student_level(Student student);
};
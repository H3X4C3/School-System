#pragma once
#include "student.h"
#include "person.h"

#include <string>
using namespace std;

class Teacher: public Person {
private:
	string first_name;
	string surname;
	string email;
	string dob;
	int id = 0;

public:
	Teacher(string first_name, string surname, string dob, string email);

	Student get_student_obj(int id);
	string get_student_name(Student student);
	double get_student_gpa(Student student);
	string get_student_email(Student student);
	int get_student_level(Student student);
};
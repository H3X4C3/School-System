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
	int age;
	int teacher_id;

public:
	Teacher(string first_name, string surname, int age, string email);

	string get_email();
	int get_id();

	void set_email(string email);
	void new_id();

	Student get_student_obj(int id);
	string get_student_name(Student student);
	double get_student_gpa(Student student);
	string get_student_email(Student student);
	int get_student_level(Student student);
};
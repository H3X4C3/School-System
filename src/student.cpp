#include "student.h"
#include "person.h"

#include <ctime>
#include <random>
using namespace std;

Student::Student(string first_name, string surname, int age, double gpa): Person(first_name, surname, age) {
	this->gpa = gpa;

	new_id();
	//srand((unsigned)time(0));
	//this->student_id = 1 + (rand() % 999);
}

// GETTERS
int Student::get_id() {
	return this->student_id;
}

double Student::get_gpa() {
	return this->gpa;
}

// SETTERS
void Student::new_id() {
	srand((unsigned)time(0));
	this->student_id = 1 + (rand() % 999);
}
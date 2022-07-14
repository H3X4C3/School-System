#include "teacher.h"
#include "person.h"
//#include "db/db_read.h"

#include <string>
#include <ctime>
using namespace std;

Teacher::Teacher(string first_name, string surname, int age, string email): Person(first_name, surname, age) {
	this->email = email;

	new_id();
}

// GETTERS
string Teacher::get_email() {
	return this->email;
}

int Teacher::get_id() {
	return this->teacher_id;
}

// SETTERS
void Teacher::new_id() {
	srand((unsigned)time(0));
	this->teacher_id = 1 + (rand() % 999);
}

void Teacher::set_email(string email) {
	this->email = email;
}

// OTHER FUNCTIONS
Student Teacher::get_student_obj(int id) {

}
#include "teacher.h"
#include "person.h"

#include <string>
using namespace std;

Teacher::Teacher(string first_name, string surname, string dob, string email): Person(first_name, surname, dob, email) { }

// OTHER FUNCTIONS
Student Teacher::get_student_obj(int id) {

}
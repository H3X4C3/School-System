#include "main.h"
#include "db/db_read.h"

#include <iostream>
using namespace std;

void cleanup();

int main() {
	connect_db();
	string name = get_student_name(213);
	string dob = get_student_dob(213);
	cleanup();

	cout << name << endl;
	cout << dob << endl;

	return 0;
}

void cleanup() {
	delete result;
	delete statement;
	delete con;
}
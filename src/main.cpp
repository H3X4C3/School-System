#include "main.h"
#include "db/db_read.h"

#include <iostream>
using namespace std;

void cleanup();

int main() {
	connect_db();
	print_entry(213, "student");
	print_entry(433, "administrator");
	print_entry(746, "teacher");

	return 0;
}

void cleanup() {
	delete result;
	delete statement;
	delete con;
}
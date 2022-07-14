#include "main.h"
#include "db/db_read.h"

#include <iostream>
using namespace std;

void cleanup();

int main() {
	connect_db();

	return 0;
}

void cleanup() {
	delete result;
	delete statement;
	delete con;
}
#include "main.h"
#include "person.h"
#include "admin.h"

#include <string>
#include <iostream>
#include <db/db_read.h>
#include <db/db_write.h>
using namespace std;

int main();

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
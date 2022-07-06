#include "main.h"
#include "db/db_read.h"

#include <iostream>
using namespace std;

int main() {
	connect_db();
	print_admin("john");

	return 0;
}
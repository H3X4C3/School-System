#pragma once
#include "mysql_connection.h"
#include "main.h"

#include <string>
#include <stdlib.h>
#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
using namespace std;

// PRINT TABLE FROM DATABASE
void print_table(string table) {
	sql::PreparedStatement* statement;
	sql::ResultSet* result;

	// READ DATA
	statement = con->prepareStatement("SELECT * FROM " + table);
	result = statement->executeQuery();

	transform(table.begin(), table.end(), table.begin(), toupper);
	cout << "Entries from " << table << ":" << endl;
	transform(table.begin(), table.end(), table.begin(), tolower);

	if (table == "student") {
		while (result->next()) {
			printf("id: %d   first_name: %s   surname: %s   DOB: %s   gpa: %.1f   level: %d\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str(), 
				result->getString(4).c_str(), result->getDouble(5), result->getInt(6));
		}
	}
	else {
		while (result->next()) {
			printf("id: %d   first_name: %s   surname: %s   dob: %s   email: %s\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str(), 
				result->getString(4).c_str(), result->getString(5).c_str());
		}
	}

	delete result;
	delete statement;
	delete con;
	system("pause");
}

// PRINT ADMIN FUNCTIONS
void print_admin(int id) { // ================================= PRINT ADMIN INT
	sql::PreparedStatement* statement;
	sql::ResultSet* result;
	string str_id = to_string(id);
	
	statement = con->prepareStatement("SELECT * FROM administrator WHERE (id=" + str_id + ");");
	result = statement->executeQuery();

	cout << "From ADMINISTRATOR:" << endl;
	
	while (result->next()) {
		printf("id: %d   first_name: %s   surname: %s   age: %s   email: %s\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str(), 
			result->getString(4).c_str(), result->getString(5).c_str());
	}

	delete result;
	delete statement;
	delete con;
	system("pause");
}

void print_admin(string str) { // ================================= PRINT ADMIN STRING
	sql::PreparedStatement* statement;
	sql::ResultSet* result;

	// must put in try-catch clause
	try {
		// put escape chars otherwise mysql won't be able to read strings
		statement = con->prepareStatement("SELECT * FROM administrator WHERE (first_name=\'" + str + "\') OR (surname=\'" + str + "\');");
	}
	catch (sql::SQLException e) {
		cout << "Error grabbing names from DB: " << e.what() << endl;
		system("pause");
		exit(1);
	}
	result = statement->executeQuery();

	printf("Names with \'%s\' in ADMINISTRATOR:\n", str.c_str());

	while (result->next()) {
		printf("id: %d   first_name: %s   surname: %s   age: %s   email: %s\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str(), 
			result->getString(4).c_str(), result->getString(5).c_str());
	}

	delete result;
	delete statement;
	delete con;
	system("pause");
}

// STUDENT FUNCTIONS
void print_student(int id) {
	sql::PreparedStatement* statement;
	sql::ResultSet* result;
	string str_id = to_string(id);

	statement = con->prepareStatement("SELECT * FROM student WHERE (id=" + str_id + ");");
	result = statement->executeQuery();

	printf("Entries with ID \'%d\' in STUDENT:\n", id);

	while (result->next()) {
		printf("id: %d   first_name: %s   surname: %s   DOB: %s   gpa: %.1f   level: %d\n", result->getInt(1), result->getString(2).c_str(), 
			result->getString(3).c_str(), result->getString(4).c_str(), result->getDouble(5), result->getInt(6));
	}

	delete result;
	delete statement;
	delete con;
	system("pause");
}
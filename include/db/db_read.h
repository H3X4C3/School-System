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
	cout << "From " << table << ":" << endl;

	while (result->next()) {
		printf("id: %d   first_name: %s   surname: %s   age: %d   email: %s\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str(), result->getInt(4), result->getString(5).c_str());
	}

	delete result;
	delete statement;
	delete con;
	system("pause");
}

// PRINT ADMIN FUNCTIONS
void print_admin(int id) {
	sql::PreparedStatement* statement;
	sql::ResultSet* result;
	string str_id = to_string(id);
	
	statement = con->prepareStatement("SELECT * FROM administrator WHERE (id=" + str_id + ");");
	result = statement->executeQuery();

	cout << "From ADMINISTRATOR:" << endl;
	
	while (result->next()) {
		printf("id: %d   first_name: %s   surname: %s   age: %s   email: %s\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str(), result->getString(4).c_str(), result->getString(5).c_str());
	}

	delete result;
	delete statement;
	delete con;
	system("pause");
}

void print_admin(string name) {
	sql::PreparedStatement* statement;
	sql::ResultSet* result;
	
	// must put in try-catch clause
	try {
		statement = con->prepareStatement("SELECT * FROM administrator WHERE (first_name=" + name + ") OR (surname=" + name + ");");
	}
	catch (sql::SQLException e) {
		cout << "Error grabbing names from DB: " << e.what() << endl;
		system("pause");
		exit(1);
	}
	result = statement->executeQuery();

	printf("Names with \'%s\' in ADMINISTRATOR:\n", name.c_str());

	while (result->next()) {
		printf("id: %d   first_name: %s   surname: %s   age: %s   email: %s\n", result->getInt(1), result->getString(2).c_str(), result->getString(3).c_str(), result->getString(4).c_str(), result->getString(5).c_str());
	}

	delete result;
	delete statement;
	delete con;
	system("pause");
}
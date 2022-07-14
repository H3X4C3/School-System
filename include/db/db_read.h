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

sql::PreparedStatement* statement;
sql::ResultSet* result;

// PRINT TABLE FROM DATABASE
void print_table(string table) {
	// READ DATA
	statement = con->prepareStatement("SELECT * FROM " + table);
	result = statement->executeQuery();

	transform(table.begin(), table.end(), table.begin(), tolower);

	try {
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
	}
	catch (sql::SQLException e) {
		cout << "Error grabbing entries from DB: " << e.what() << endl;
		system("pause");
		exit(1);
	}
}

// PRINT ROW(S)
void print_row(int id, string table) {
	string str_id = to_string(id);

	statement = con->prepareStatement("SELECT * FROM " + table + " WHERE (id=" + str_id + ");");
	result = statement->executeQuery();

	transform(table.begin(), table.end(), table.begin(), tolower);

	try {
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
	}
	catch (sql::SQLException e) {
		cout << "Error grabbing entries from DB: " << e.what() << endl;
		system("pause");
		exit(1);
	}
}

void print_row(string val, string column, string table) {
	statement = con->prepareStatement("SELECT * FROM " + table + " WHERE (" + column + "=\'" + val + "\');");
	result = statement->executeQuery();

	transform(table.begin(), table.end(), table.begin(), tolower);

	try {
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
	}
	catch (sql::SQLException e) {
		cout << "Error grabbing entry from DB: " << e.what() << endl;
		system("pause");
		exit(1);
	}
}

// GENERAL FUNCTIONS
template <typename numbers>
numbers get_entry(int id, string table, string column) {
	string str_id = to_string(id);
	numbers output;

	statement = con->prepareStatement("SELECT " + column + " FROM " + table + " WHERE (id=" + str_id + ");");
	result = statement->executeQuery();

	transform(column.begin(), column.end(), column.begin(), tolower);

	try {
		while (result->next()) {
			if (column == "gpa") {
				output = result->getDouble(column);
			}
			else {
				output = result->getInt(column);
			}
		}
	}
	catch (sql::SQLException e) {
		cout << "Error grabbing entry from DB: " << e.what() << endl;
		system("pause");
		exit(1);
	}

	return output;
}

string get_entry(int id, string table, string column1, string column2 = "") {
	string str_id = to_string(id);
	string output;

	if (!(column2.empty())) {
		statement = con->prepareStatement("SELECT " + column1 + ", " + column2 + " FROM " + table + " WHERE (id=" + str_id + ");");
	}
	else statement = con->prepareStatement("SELECT " + column1 + " FROM " + table + " WHERE (id=" + str_id + ");");
	result = statement->executeQuery();

	transform(column2.begin(), column2.end(), column2.begin(), tolower);

	try {
		if (column2 == "surname") {
			while (result->next()) {
				output = result->getString(column1) + " " + result->getString(column2);
			}
		}
		else {
			while (result->next()) {
				output = result->getString(column1);
			}
		}
	}
	catch (sql::SQLException e) {
		cout << "Error grabbing entry from DB: " << e.what() << endl;
		system("pause");
		exit(1);
	}

	return output;
}
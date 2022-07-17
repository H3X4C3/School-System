#pragma once
#include "mysql_connection.h"
#include "person.h"
#include "main.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"

#include <stdlib.h>
#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

void insert_to_table(Person* person, string table) {
	transform(table.begin(), table.end(), table.begin(), tolower);

	if (!(table == "student")) {
		statement = con->prepareStatement("INSERT INTO " + table + "(id, first_name, surname, DOB, email) VALUES(?, ?, ?, ?, ?);");
		// Set values to db
		statement->setInt(1, person->get_id());
		statement->setString(2, person->get_first_name());
		statement->setString(3, person->get_surname());
		statement->setString(4, person->get_dob());
		statement->setString(5, person->get_email());
		statement->execute();

		cout << "Entry inserted to database." << endl;
		return;
	}

	statement = con->prepareStatement("INSERT INTO " + table + "(id, first_name, surname, DOB, gpa, level) VALUES(?, ?, ?, ?, ?, ?);");
	// Set values to db
	statement->setInt(1, person->get_id());
	statement->setString(2, person->get_first_name());
	statement->setString(3, person->get_surname());
	statement->setString(4, person->get_dob());
	statement->setDouble(5, static_cast<Student*>(person)->get_gpa());
	statement->setInt(6, static_cast<Student*>(person)->get_level());
	statement->execute();

	cout << "Entry inserted to database." << endl;
}

/*
* Had to reuse update_entry() for each type of column to update the database.
* Not entirely sure how to convert template type T to a string type,
* but if I figure it out I'll change this.
*/
void update_entry(int id, string entry, string val, string table) { // update student table and set entry = val where the id is given
	statement = con->prepareStatement("UPDATE " + table + " SET " + entry + " = ? WHERE id = ?");

	statement->setString(1, val);
	statement->setInt(2, id);
	statement->executeQuery();

	cout << "Entry updated." << endl;
}

void update_entry(int id, string entry, double val, string table) {
	statement = con->prepareStatement("UPDATE " + table + " SET " + entry + " = ? WHERE id = ?");

	statement->setDouble(1, val);
	statement->setInt(2, id);
	statement->executeQuery();

	cout << "Entry updated." << endl;
}

void update_entry(int id, string entry, int val, string table) {
	statement = con->prepareStatement("UPDATE " + table + " SET " + entry + " = ? WHERE id = ?");

	statement->setInt(1, val);
	statement->setInt(2, id);
	statement->executeQuery();

	cout << "Entry updated." << endl;
}
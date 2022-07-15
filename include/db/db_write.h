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

//sql::PreparedStatement* statement;

void insert_to_table(Person* person, string table) {
	transform(table.begin(), table.end(), table.begin(), tolower);

	if (table == "student") {
		statement = con->prepareStatement("INSERT INTO " + table + "(id, first_name, surname, DOB, gpa, level) VALUES(?, ?, ?, ?, ?, ?);");
		// Set values to db
		statement->setInt(1, person->get_id());
		statement->setString(2, person->get_first_name());
		statement->setString(3, person->get_surname());
		statement->setString(4, person->get_dob());
		statement->setDouble(5, static_cast<Student*>(person)->get_gpa());
		statement->setInt(6, static_cast<Student*>(person)->get_level());
	}
	else {
		statement = con->prepareStatement("INSERT INTO " + table + "(id, first_name, surname, DOB, email) VALUES(?, ?, ?, ?, ?);");
		// Set values to db
		statement->setInt(1, person->get_id());
		statement->setString(2, person->get_first_name());
		statement->setString(3, person->get_surname());
		statement->setString(4, person->get_dob());
		statement->setString(5, person->get_email());
	}
	statement->execute();

	cout << "Entry inserted to database." << endl;
}
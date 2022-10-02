#pragma once
#include "mysql_connection.h"

#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
using namespace std;

#define PRINTLN(x) cout<<x<<endl;
#define PRINT(x) cout<<x;

extern sql::Driver* driver;
extern sql::Connection* con;

// READ PASSWORD FROM FILE
inline string read_pass() {
	ifstream file;
	string pass = "";

	// for security purposes I'm opening a local .env file to read database password
	file.open(".\\.env", ios::in);

	if (file.is_open()) {
		getline(file, pass);
		file.close();
	}

	return pass;
}

// Can be changed depending on SQL server credentials and domain location
const string server = "localhost";
const string username = "root";
const string password = read_pass(); // read password from .env and assign it to string

// CONNECT TO DATABASE
inline void connect_db() {
	try {
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
	}
	catch (sql::SQLException e) {
		cout << "Error connecting to DB Server: " << e.what() << endl;
		system("pause");
		exit(1);
	}

	con->setSchema("school_system");
}

// MENU FUNCTIONS
inline void print_menu() {
	PRINTLN("\t\tSchool Management System\n");
	PRINTLN("1. Login\n2. Register\n0. Exit\n");
	PRINT("Choice -> ");
}

inline void login_menu() {
	PRINTLN("\t\tLogin\n");
	PRINTLN("1. Administrator\n2. Teacher\n0. Back\n");
	PRINT("Choice -> ");
}

inline void register_menu() {
	PRINTLN("\t\tRegister Account\n");
	PRINTLN("1. Administrator\n2. Teacher\n0. Back\n");
	PRINT("Choice -> ");
}

inline void admin_panel() {
	PRINTLN("\t\tAdmin Panel\n");
	PRINTLN("1. Add\n2. Remove\n3. Update\n0. Logout\n");
	PRINT("Choice -> ");
}

inline void admin_panel2() {
	PRINTLN("\t\tAdmin Panel\n");
	PRINTLN("1. Student\n2. Teacher\n3. Admin\n0. Logout\n");
	PRINT("Choice -> ");
}

inline void teacher_panel() {
	PRINTLN("\t\tTeacher Panel\n");
	PRINTLN("1. View Student\n2. View Grades\n3. Change Grades\n4. List Students\n0. Logout\n");
	PRINT("Choice -> ");
}
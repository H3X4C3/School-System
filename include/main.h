#pragma once
#include "mysql_connection.h"
#include "admin.h"

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

Admin* admin;
sql::Driver* driver;
sql::Connection* con;

// READ PASSWORD FROM FILE
string read_pass() {
	ifstream file;
	string pass = "";

	// for security purposes I'm opening a local .env file to read database password
	file.open("C:\\Users\\Me\\Documents\\c++ projects\\school system\\.env", ios::in);

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
void connect_db() {
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
void print_menu() {
	PRINTLN("\t\tSchool Management System\n");
	PRINTLN("1. Login\n2. Register\n0. Exit\n");
	PRINT("Choice -> ");
}

void login_menu() {
	PRINTLN("\t\tSchool Management System\n\t\tLogin\n");
	PRINTLN("1. Administrator\n2. Teacher\n0. Back\n");
	PRINT("Choice -> ");
}

void register_menu() {
	PRINTLN("\t\tSchool Management System\n\t\tRegister Account\n");
	PRINTLN("1. Administrator\n2. Teacher\n0. Back\n");
	PRINT("Choice -> ");
}

void admin_panel() {
	PRINTLN("\t\tAdmin Panel\n");
	PRINTLN("1. Add\n2. Remove\n3. Update\n");
	PRINT("Choice -> ");
}

void teacher_panel() {

}
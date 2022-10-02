#pragma once
#include <string>
using namespace std;

class Person {
private:
	string first_name;
	string surname;

public:
	Person() {};
	Person(string first_name, string surname);

	string get_firstname();
	string get_surname();

	void set_firstname(string name);
	void set_surname(string name);
};
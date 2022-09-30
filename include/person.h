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

	string get_first_name();
	string get_surname();

	void set_first_name(string name);
	void set_surname(string name);
};
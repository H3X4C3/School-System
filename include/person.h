#pragma once
#include <string>
using namespace std;

class Person {
private:
	string first_name;
	string surname;
	int age;

public:
	Person(string first_name, string surname, int age);

	string get_first_name();
	string get_surname();
	int get_age();

	void set_first_name(string name);
	void set_surname(string name);
	void set_age(int age);
};
#include <iostream>
#include <string>

#ifndef STUDENTS
#define STUDENTS

using std::string;
using std::cout;
using std::endl;

struct Student {
	string name;
	int english, math, program;
	Student *next;
	void show() {
		cout << "name: " << name << endl;
		cout << "score:" << endl;
		cout << "\tenglish: " << english << endl;
		cout << "\tmath: " << math << endl;
		cout << "\tprogram: " << program << endl;
	}
};

class Students {
private:
	Student *stus;
public:
	Students():length(0),stus(NULL){}
	void addStudent();
	void showAllStudent();
	void deleteStudent();
	void findStudent();
	int length;
};

#endif
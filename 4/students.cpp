#include <iostream>
#include <string>
#include "students.h"
#include "utils.h"

using std::cin;
using std::cout;
using std::string;

void Students::addStudent() {
	Student *stu = new Student;
	stu -> next = NULL;

	putln("please input name:");
	cin >> stu -> name;

	putln("please input english score:");
	cin >> stu -> english;

	putln("please input math score:");
	cin >> stu -> math;

	putln("please input program score:");
	cin >> stu -> program;

	length++;

	if (stus == NULL) stus = stu;
	else stus -> next = stu;

	putln("add user action success");
}

void Students::showAllStudent() {
	for (Student *stu=stus; stu != NULL; stu = stu -> next) {
		stu -> show();
	}

	putln("show all student action success");
}

void Students::deleteStudent() {
	string name;
	Student *pre = stus, *stu;
	putln("please input student name to delete");
	cin >> name;

	for (stu=stus; stu!=NULL; stu=stu->next) {
		if (stu -> name == name) {
			break;
		}
		pre = stu;
	}

	if (stu != NULL) {
		if (pre == stu) {
			stus = stu -> next;
			delete stu;
		} else {
			pre -> next = stu -> next;
			delete stu;
		}
		putln("delete student success");
	} else {
		putln("can't find student");
	}

	putln("delete student action finish");
}

void Students::findStudent() {
	string name;
	Student *stu;
	putln("please input studnet name to find");
	cin >> name;

	for (stu = stus; stu != NULL; stu = stu -> next) {
		if (stu -> name == name) {
			break;
		}
	}

	if (stu == NULL) {
		putln("can't find student");
	} else {
		stu -> show();
	}

	putln("find student actioin finish");
}
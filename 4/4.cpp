#include <iostream>
#include "students.h"
using namespace std;

int main() {
	int mode;
	Students students;

	cout << "welcome student manage system;" << endl;

	while (cout << "please input action code" << endl, cin>>mode, mode!=0) {
		switch (mode) {
			case 1:
				students.addStudent();
				break;
			case 2:
				students.showAllStudent();
				break;
			case 3:
				students.deleteStudent();
				break;
			case 4:
				students.findStudent();
				break;
			default:
				cout << "error mode" << endl;
		}
	}
	cout << "goodbye" << endl;
	return 0;
}
#include "CircleList.h"

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n,m;
	cout << "please input M,N" << endl;
	cin >> n >> m;

	CircleList c;

	for (int i=0; i<n; i++) {
		c.push(i+1);
	}

	while (c.length > 1) {
		for (int i=0; i<m-1; i++) {
			c.next();
		}
		cout << setw(4) << c.remove();
		c.next();
	}
	cout << setw(4) << c.remove();
	cout << endl;

	return 0;
}
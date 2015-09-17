#include <iostream>
#include "Number.h"
using namespace std;

int main() {
	char s1[200],s2[200];

	cin >> s1 >> s2;

	Number a(s1),b(s2),x(s1),y(s2);

	a.plus(b).show();
	x.minus(y).show();

	return 0;
}
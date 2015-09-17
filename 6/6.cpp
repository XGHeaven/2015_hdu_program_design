#include <iostream>
#include "Number.h"
using namespace std;

int main() {
	char s1[200],s2[200];

	cin >> s1 >> s2;

	Number a(s1),b(s2);

	a.show();
	b.show();

	a.plus(b);
	a.show();

	return 0;
}
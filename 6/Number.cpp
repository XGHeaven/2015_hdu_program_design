#include "Number.h"
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

Number::Number(char * s) {
	memset(num, 0, 200 * sizeof(short int));
	int i = 0;
	bool plus = true;

	length = strlen(s);

	if (s[0] == '-') plus = false, i = 1;

	for (; i < length; i++) {
		num[length - i - 1] = s[i] - '0';
	}

	if (!plus) length--, num[length] = -1;
}

bool Number::negative() {
	return num[length] == -1;
}

Number & Number::_plus(Number & n) {
	int l = max(length, n.length);

	for (int i=0; i < l; i++) {
		num[i] += n.num[i];
		num[i+1] += num[i] / 10;
		num[i] %= 10;
	}

	while(num[l] > 0) {
		num[l+1] += num[l] / 10;
		num[l] %= 10;
		l++;
	}

	length = l;

	return *this;
}

Number & Number::minus(Number & n) {
	for (int i=0; i<n.length; i++) {
		num[i] -= n.num[i];
		num[i]
	}
}

Number & Number::plus(Number & n) {
	if (negative()) {
		if (n.negative()) {
			num[length] = 0;
			n.num[n.length] = 0;
			plus(n);
			num[length] = -1;
			n.num[n.length] = -1;
			return *this;
		} else {
			num[length] = 0;
			n.minus(*this);
			return n;
		}
	} else if (n.negative()) {
		return minus(n);
	}

}

Number & Number::minus(Number & n) {
	n.num[n.length] = n.num[n.length] ? 0 : -1;
	this -> plus(n);
	return *this;
}

void Number::show() {
	if (num[length] == -1) cout << '-';
	for (int i=length-1; i>=0; i--) cout << num[i];
	cout << endl;
}
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

void Number::revert() {
	num[length] = num[length] == 0 ? -1 : 0;
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

Number & Number::_minus(Number & n) {
	if (length < n.length) {
		n.minus(*this);
		n.revert();
		return n;
	}

	int l = n.length;
	for (int i=0; i<l; i++) {
		num[i] -= n.num[i];
		if (num[i] < 0) {
			num[i+1] -- ;
			num[i] += 10;
		}
	}

	while (l<length) {
		if (num[l] < 0) {
			num[l+1] -- ;
			num[l] += 10;
		}
		l++;
	}

	cout << l << endl;

	while(l>1) {
		if (num[l-1] <= 0) {
			num[l-2] += num[l-1];
			num[l-1] = 0;
		} else break;
		l--;
	}


	length = l;

	return *this;
}

Number & Number::plus(Number & n) {
	if (negative()) {
		if (n.negative()) {
			revert();
			n.revert();
			_plus(n);
			revert();
			return *this;
		} else {
			num[length] = 0;
			n._minus(*this);
			return n;
		}
	} else if (n.negative()) {
		n.revert();
		n.show();
		return _minus(n);
	} else {
		return _plus(n);
	}

}

Number & Number::minus(Number & n) {
	n.revert();
	plus(n);
	return *this;
}

void Number::show() {
	if (num[length] == -1) cout << '-';
	for (int i=length-1; i>=0; i--) cout << num[i];
	cout << endl;
}
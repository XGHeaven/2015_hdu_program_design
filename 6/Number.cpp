#include "Number.h"
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

Number::Number(char * s) {
	memset(num, 0, 200 * sizeof(short int));
	int i = 0;

	negative = false;

	length = strlen(s);

	if (s[0] == '-') negative = true, i = 1;

	for (; i < length; i++) {
		num[length - i - 1] = s[i] - '0';
	}

	if (negative) length--;
}

void Number::revert() {
	negative = !negative; 
}

int Number::compare(Number & n) {
	if (length > n.length) return 1;
	else if (length < n.length) return -1;

	int l = max(length, n.length);

	for (int i=l ; i>=0; i--) {
		if (num[i] > n.num[i]) return 1;
		else if (num[i] < n.num[i]) return -1;
	}

	return 0;
}

// ignore negative
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
	if (compare(n) < 0) {
		n._minus(*this);
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
	if (negative) {
		if (n.negative) {
			revert();
			n.revert();
			_plus(n);
			revert();
			n.revert();
			return *this;
		} else {
			revert();
			return n._minus(*this);
		}
	} else if (n.negative) {
		n.revert();
		return _minus(n);
	} else {
		return _plus(n);
	}

}

Number & Number::minus(Number & n) {
	n.revert();
	return plus(n);
}

void Number::show() {
	if (negative) cout << '-';
	for (int i=length-1; i>=0; i--) cout << num[i];
	cout << endl;
}
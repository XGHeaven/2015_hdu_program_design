#include <iostream>
#include <cmath>
using namespace std;

inline double value(double x) {
	return x*x*x + 1.1*x*x + 0.9*x -1.4;
}

int main() {
	double start, end;
	cout << "please input the range" << endl;
	cin >> start >> end;
	if (start > end) {
		double t = start;
		start = end;
		end = t;
	}

	while (end > start ) {
		double mid = (start + end) / 2;
		double v = value(mid);
		if (fabs(v) < 1e-5) {
			break;
		}
		if (v * value(start) > 0) {
			start = mid;
		} else {
			end = mid;
		}
	}
	cout << start << endl;

	return 0;
}
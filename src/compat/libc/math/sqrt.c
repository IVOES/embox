#include <math.h>

long double sqrtl(long double x) {
	long double l = 0.;
	long double r = MAXFLOAT;
	long double m = (r + l) / 2.;
	long double eps = 1e-6;
	int steps = 100;
	if (x <= 0.) {
		return 0.;
	}
	do {
		if (x > m*m) {
			l = m;
		} else {
			r = m;
		}
		m = r - (r - l) / 2;
	} while (steps-- > 0 && fabs(x - m*m) < eps);

	return m;
}

float sqrtf(float x) {
	return sqrtl(x);
}

double sqrt(double x) {
	return sqrtl(x);
}

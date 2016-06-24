#include <stdio.h>
#include <math.h>
#include "discriminant.h"

const double EPS = 1e-10;
const short ERROR = -1;
const short NO_ROOTS = 0;
const short ONE_ROOT = 1;
const short TWO_ROOTS = 2;

int check(double d, double f, double eps)
{
	return fabs(d - f) < eps;
}

short computering_roots(double a, double b, double c, double *x1, double *x2)
{
	double d = discriminant(a, b, c);
	if (d < 0)
		return NO_ROOTS;
	if (check(d, 0, EPS))
	{
		*x1 = *x2 = -b / (2 / a);
		return ONE_ROOT;
	}
	if (d > 0)
	{
		*x1 = (-b - sqrt(d)) / (2 * a);
		*x2 = (-b + sqrt(d)) / (2 * a);
		return TWO_ROOTS;
	}
	return ERROR;
}

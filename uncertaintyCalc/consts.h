#pragma once

#define MAXN 101

#define COMMAND_NUM 8

char commandList[COMMAND_NUM][MAXN] = {
	"-h",
	"-H",
	"-a",
	"-A",
	"-b",
	"-B",
	"-t",
	"-T"
};

const double pPresent[4] = { 0.68, 0.90, 0.95, 0.99 };

const double acoefficient[4][11] = {
	{ 1.32, 1.20, 1.14, 1.11, 1.09, 1.08, 1.07, 1.06, 1.04, 1.03, 1.00 },
{ 2.92, 2.35, 2.13, 2.02, 1.94, 1.86, 1.83, 1.76, 1.73, 1.71, 1.65 },
{ 4.30, 3.18, 2.78, 2.57, 2.45, 2.37, 2.31, 2.26, 2.15, 2.09, 1.96 },
{ 9.93, 5.84, 4.60, 4.03, 3.71, 3.50, 3.36, 3.25, 2.98, 2.86, 2.58 }
};

const int alimits[11] = {
	3, 4, 5, 6, 7, 8, 9, 10, 15, 20, 0x3f3f3f3f
};

const double bcoefficient[2][4] = {
	{ 1.000, 1.650, 1.960, 2.580 },
{ 1.183, 1.559, 1.645, 1.715 }
};

const double bdiv[2] = { 3.0, 1.732050808 };

double average(int n, double *x)
{
	double ret = 0;

	for (int i = 0; i < n; i++)
		ret += x[i];
	ret /= n;

	return ret;
}

double sqr(double x)
{
	return x * x;
}
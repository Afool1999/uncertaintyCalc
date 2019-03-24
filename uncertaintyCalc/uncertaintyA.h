#pragma once

#include <iostream>
#include <cmath>

#include "consts.h"

class uncertaintyA
{
	public:

	void work();
	double unc(int typ);

	private:

	int n, stat;
	double *seq;
	double aver, uncertainty;

	void init();
	bool wantExit();
};

void uncertaintyA::init()
{
	n = 0;
	aver = 0.0;
	uncertainty = 0.0;
}

bool uncertaintyA::wantExit()
{
	return std::cin.eof();
}

double uncertaintyA::unc(int typ)
{
	double ret = uncertainty;
	ret *= acoefficient[typ][stat];
	return ret;
}

void uncertaintyA::work()
{
	const static char prefix[MAXN] = "mode A > ";
	init();
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl
		<< "You've entered the uncertaintyA mode. Use ^Z whenever you want to exit. Your number of data should be under 100, above 2."
		<< std::endl;
	std::cout << "Please input the number(n) of your data" << std::endl;
	
	std::cout << prefix;
	if (wantExit()) {
		return;
	}
	else std::cin >> n;
	seq = new double[n];
	for (int i = 0; i < 11; i++)
	{
		if (n <= alimits[i])
		{
			stat = i;
			break;
		}
	}

	std::cout << "Please Input data" << std::endl;
	std::cout << prefix;
	if (wantExit()) {
		return;
	}
	else {
		for (int i = 0; i < n; i++)
			if (wantExit()) {
				return;
			}
			else std::cin >> seq[i];
	}
	aver = average(n, seq);
	std::cout << "average: " << aver << std::endl;

	double temp = 0.0;
	for (int i = 0; i < n; ++i)
		temp += sqr(seq[i] - aver);
	temp /= n * (n - 1);
	uncertainty = sqrt(temp);

	for (int i = 0; i < 4; i++)
	{
		double tunc = unc(i);
		printf("Ua = %.6lf  p = %.2lf\n", tunc, pPresent[i]);
	}


	delete seq;

	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;

}
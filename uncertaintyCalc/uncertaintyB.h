#pragma once

#include <iostream>
#include <cmath>

#include "consts.h"

class uncertaintyB
{
	public:

	void work();
	double unc(int typ);

	private:

	int stat;
	double uncertainty;

	void init();
	bool wantExit();
};

void uncertaintyB::init()
{
	stat = -1;
	uncertainty = 0.0;
}

bool uncertaintyB::wantExit()
{
	return std::cin.eof();
}

double uncertaintyB::unc(int typ)
{
	double ret = uncertainty;
	ret *= bcoefficient[stat][typ];
	return ret;
}

void uncertaintyB::work()
{
	const static char prefix[MAXN] = "mode B > ";
	init();
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl
		<< "You've entered the uncertaintyB mode. Use ^Z whenever you want to exit. Your number of data should be under 100, above 2."
		<< std::endl;
	
	std::cout << "Please input delta" << std::endl;
	std::cout << prefix;
	if (wantExit()) {
		return;
	}
	else std::cin >> uncertainty;

	std::cout << "Please select type of distribution" << std::endl
		<< "    0 for Gaussian distribution" << std::endl
		<< "    1 for Uniform distribution" << std::endl;
		
	while (stat < 0 || stat > 1)
	{
		std::cout << prefix;
		if (wantExit()) {
			return;
		}
		else std::cin >> stat;
	}

	uncertainty /= bdiv[stat];

	for (int i = 0; i < 4; i++)
	{
		double tunc = unc(i);
		printf("Ub = %.6lf  p = %.2lf\n", tunc, pPresent[i]);
	}

	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;

}
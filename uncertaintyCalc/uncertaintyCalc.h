#pragma once

#include "uncertaintyA.h"
#include "uncertaintyB.h"

class uncertaintyCalc
{
	public:

	void showInfo();
	void work();
	double combinition(int typ);

	private:

	uncertaintyA uncA;
	uncertaintyB uncB;

};

void uncertaintyCalc::showInfo()
{
	puts("---------------------------------------------------+");
	puts("    [-h/-H] to show information                    |");
	puts("    [-a/-A] to enter measuring uncertainty A       |");
	puts("    [-b/-B] to enter measuring uncertainty B       |");
	puts("    [-t/-T] to enter measuring total uncertainty   |");
	puts("---------------------------------------------------+");
}

double uncertaintyCalc::combinition(int typ)
{
	double duncA = uncA.unc(typ);
	double duncB = uncB.unc(typ);
	double ret = sqrt(sqr(duncA) + sqr(duncB));

	return ret;
}

void uncertaintyCalc::work()
{
	char userCommand[MAXN];

	while (!std::cin.eof()) {

		std::cout << "> ";
		std::cin >> userCommand;

		bool flg = true;
		for (int i = 0; i < COMMAND_NUM; i++)
		{
			if (strcmp(userCommand, commandList[i]) == 0)
			{
				flg = false;
				switch (i >> 1)
				{
				case 0:

					showInfo();
					break;

				case 1:

					uncA.work();
					break;

				case 2:

					uncB.work();
					break;

				case 3:

					int typ;
					std::cout << "Please select type of p" << std::endl;
					std::cout << "    0 for p = 0.683" << std::endl
						<< "    1 for p = 0.900" << std::endl
						<< "    2 for p = 0.950" << std::endl
						<< "    3 for p = 0.990" << std::endl;
					std::cout << "> ";
					std::cin >> typ;

					double res = combinition(typ);
					printf("Ut = %.6lf  p = %.2lf\n", res, pPresent[typ]);
					break;
				}
			}
		}
		if (flg) puts("Invalid command! Use [-h/-H] for more information.");
	}
}
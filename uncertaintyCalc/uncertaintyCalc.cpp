#define _CRT_SECURE_NO_WARNINGS
#include "uncertaintyCalc.h"


int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		if (strcmp(argv[1], "-f") == 0)
		{
			puts("1");
			freopen(argv[2], "r", stdin);
		}
	}

	uncertaintyCalc calc;
	calc.work();

	return 0;
}
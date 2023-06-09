#include "./../../monty.h"
#include <string.h>
#include "../test.h"

#define NTC 2


int main()
{
	int i, rv = 0;
	char my_rv[11];
	char lib_rv[11];
	char *tc[] = {
		"                     ",
		"Mohamed       Mohamed",
		"1320342490139319124091309481390581309581309583109481309MOHAMED481",
		"- ~ * / @ - . ' ~ . *"
	};

	for (i = 0; i < NTC; i++)
	{
		_memcpy(my_rv, tc[i], 10);
		my_rv[10] = '\0'; // append null terminator for strcmp and printf to work properly
		memcpy(lib_rv, tc[i], 10);
		lib_rv[10] = '\0';

		if (strcmp(my_rv, lib_rv) == 0)
			continue;

		printf("Test Case %d: String(%s)\n", i, tc[i]);
		printf("Library's Return Value: %s\n", my_rv);
		printf("My Return Value: %s\n", lib_rv);

		rv = 1;
	}

	return (rv);
}

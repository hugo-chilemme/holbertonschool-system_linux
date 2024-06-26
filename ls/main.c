#include "imports.h"
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	int index = 1;
	char *path_name = argv[0];

	int countArgs = 0;
	char *separator = "  ";


	for (; index < argc; index++)
	{
		if (argv[index][0] != '-')
		{
			countArgs++;
		}
		else
		{
			if (argv[index][1] == '1')
			{
				separator = "\n";
			}
		}
	}

	if (argc == 1)
	{
		return (listFiles(".", path_name, countArgs, separator));
	}

	index = 1;

	for (; index < argc; index++)
	{
		if (argv[index][0] == '-')
		{
			continue;
		}

		listFiles(argv[index], path_name, countArgs, separator);

		if (countArgs > 1)
		{
			printf("\n");
		}

	}

	return (0);
}

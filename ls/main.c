#include "imports.h"



int statusPath(char *path, char *path_name)
{
	struct stat file_info;
	const char *M_ERR_FNF = "No such file or directory";

	if (lstat(path, &file_info) == -1)
	{
		fprintf(stderr, "%s: cannot access %s: %s\n", path_name, path, M_ERR_FNF);
		return (0);
	}
	if (lstat(path, &file_info) == 0 && S_ISREG(file_info.st_mode))
	{
		printf("%s\n", path);
		return (2);
	}
	return (1);
}
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
	int checkStatusPath = 0;


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
		return (listFiles(".", countArgs, separator));
	}

	index = 1;

	for (; index < argc; index++)
	{

		if (argv[index][0] == '-')
		{
			continue;
		}
		listFiles(argv[index], countArgs, separator);

		checkStatusPath = statusPath(argv[index], path_name);
		if (countArgs >= 2 && checkStatusPath == 1 && index < argc - 1)
		{
			printf("\n");
		}

		if (checkStatusPath == 2 || checkStatusPath == 0)
			continue;

	}

	return (0);
}

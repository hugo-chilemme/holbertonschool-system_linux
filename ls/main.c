#include "imports.h"



int statusPath(char *path)
{
	struct stat file_info;

	if (lstat(path, &file_info) == -1)
		return (0);
	
	if (lstat(path, &file_info) == 0 && S_ISREG(file_info.st_mode))
		return (2);

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

	int countArgs = 0;
	const char *M_ERR_FNF = "No such file or directory";
	char *separator = "  ";
	char *path_name = argv[0];
	int checkStatusPath = 0;


	for (; index < argc; index++)
	{
		if (argv[index][0] != '-')
		{

			checkStatusPath = statusPath(argv[index]);

			if (checkStatusPath == 0)
				fprintf(stderr, "%s: cannot access %s: %s\n", path_name, argv[index], M_ERR_FNF);

			countArgs++;
		}
		else
		{
			if (argv[index][1] == '1')
				separator = "\n";
		}
	}

	index = 1;

	for (; index < argc; index++)
	{
		if (argv[index][0] != '-')
		{
			checkStatusPath = statusPath(argv[index]);

			if (checkStatusPath == 2)
				printf("%s\n", argv[index]);
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

		checkStatusPath = statusPath(argv[index]);

		if (checkStatusPath == 2 || checkStatusPath == 0)
		{
			continue;
		}

		printf("\n");

		listFiles(argv[index], countArgs, separator);


	}

	return (0);
}

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>


/**
 * showDirectory - Display all folders and file a repository
 * @path: the target repository
 * Return: error code, 0 success
 */
void showDirectory(char *program_name, char *path)
{
	struct dirent *entry;
	DIR *dir;
	int count = 0;

	dir = opendir(path);

	if (!dir)
	{
		fprintf(stderr, "%s: cannot access %s: No such file or directory\n", program_name, path);
		return;
	}
	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] == '.')
			continue;
		printf("%s  ", entry->d_name);
		count++;
	}

	free(entry);
	free(dir);

	printf("\n");
}

/**
 * main - Function
 * @argc: number of @argv
 * @argv: argument passed in command line
 * Return: -1 for error, 0 for success
 */
int main(int argc, char *argv[])
{
	int argv_i = 1;
	char *program_name = argv[0];

	if (argc > 1)
	{
		for (; argc > 1 && argv_i < argc; argv_i++)
		{
			/** Display the path of repertory when he have multiple */
			if (argc > 2)
				printf("%s:\n", argv[argv_i]);

			showDirectory(program_name, argv[argv_i]);

			/** Display another backspace when he have multiple repository */
			if (argv_i != argc - 1)
				printf("\n");
		}
		return (0);
	}

	showDirectory(program_name, ".");

	return (0);
}

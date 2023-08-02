#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

void showDirectory(char *path)
{
	struct dirent *entry;
	DIR *dir;

	dir = opendir(path);

	if (!dir)
		return;

	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] == '.')
			continue;
		printf("%s  ", entry->d_name);
	}

	free(entry);
	free(dir);

	printf("\n");
}

/**
 * main - Function
 * Return: -1 for error, 0 for success
 */
int main(int argc, char *argv[])
{
	int argv_i = 1;

	if (argc > 1)
	{
		for (; argc > 1 && argv_i < argc; argv_i++)
		{
			// Display the path of repertory when he have multiple 
			if (argc > 2)
				printf("%s:\n", argv[argv_i]);

			showDirectory(argv[argv_i]);

			// Display another backspace when he have multiple repository
			if (argv_i != argc - 1)
				printf("\n");
		}
		return (0);
	}

	showDirectory(".");

	return (0);
}

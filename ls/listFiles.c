#include "imports.h"

/**
 * listFiles - list files in a directory
 * @path: path to the directory
 *
 * This function lists all the files in the specified directory.
 *
 * Return: 1 on success, 0 on failure
 */
int listFiles(char *path, const int MUL_ARGS, const char *separator)
{
	DIR *dir;
	struct dirent *entry;

	dir = opendir(path);
	if (dir == NULL)
	{
		return (0);
	}

	if (MUL_ARGS > 1)
	{
		printf("%s:\n", path);
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.')
		{
			printf("%s%s", entry->d_name, separator);
		}
	}

	if (separator[0] == ' ')
	{
		printf("\n");
	}


	closedir(dir);
	return (1);
}

#include "imports.h"

/**
 * listFiles - list files in a directory
 * @path: path to the directory
 *
 * This function lists all the files in the specified directory.
 *
 * Return: 1 on success, 0 on failure
 */
int listFiles(char *path)
{
	DIR *dir;
	struct dirent *entry;

	dir = opendir(path);
	if (dir == NULL)
	{
		perror("opendir");
		return (0);
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.')
		{
			printf("%s  ", entry->d_name);
		}
	}

	closedir(dir);
	printf("\n");

	return (1);
}

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
		printf("./hls: cannot access %s: No such file or directory\n", path);
		return (0);
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.')
		{
			printf("%s  ", entry->d_name);
		}
	}

	printf("\n");
	closedir(dir);
	return (1);
}

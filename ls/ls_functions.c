#include "imports.h"


#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
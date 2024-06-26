#include "imports.h"



void listFilesOrdered(DIR *d)
{
	struct dirent *dir;

	dir = readdir(d);

	if (dir == NULL)
	{
		closedir(d);
		return;
	}

	if (dir->d_name[0] == '.')
	{
		return;
	}
	printf("%s", dir->d_name);
	printf("  ");

	listFilesOrdered(d);
}

int listFiles(char *path)
{
	DIR *d;

	d = opendir(path);

	if (!d)
	{
		return (0);
	}

	listFilesOrdered(d);

	printf("\n");

	closedir(d);

	return (1);
}
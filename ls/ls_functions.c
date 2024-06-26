#include "imports.h"



void listFilesOrdered(DIR *d, int isFirst)
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
	if (!isFirst)
	{
		printf("  ");
	}

	listFilesOrdered(d, 0);
}

int listFiles(char *path)
{
	DIR *d;

	d = opendir(path);

	if (!d)
	{
		return (0);
	}

	listFilesOrdered(d, 1);

	printf("\n");

	closedir(d);

	return (1);
}
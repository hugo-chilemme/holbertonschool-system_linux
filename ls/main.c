#include <stdio.h>
#include <dirent.h>
#include <string.h>


void printDirectoryReversed(DIR *d, int isFirst)
{
	struct dirent *dir;

	dir = readdir(d);

	if (dir == NULL)
	{
		closedir(d);
		return;
	}
	printDirectoryReversed(d, 0);


	if (dir->d_name[0] == '.')
		return;

	printf("%s", dir->d_name);
	if (!isFirst)
	{
		printf("  ");
	}

}

int printDirectory(char *path)
{
	DIR *d;

	d = opendir(path);

	if (!d)
	{
		return (0);
	}

	printDirectoryReversed(d, 1);

	printf("\n");

	return (1);

}

int main(int argc, char *argv[])
{

	if (argc == 1)
	{
		return (printDirectory("."));
	}
	return (printDirectory(argv[1]));
}
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Function
 * Return: -1 for error, 0 for success
 */
int main(void)
{
	struct dirent *entry;
	DIR *dir;

	dir = opendir(".");

	if (!dir)
		return (-1);

	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] == '.')
			continue;
		printf("%s  ", entry->d_name);
	}

	printf("\n");

	free(entry);
	free(dir);

	return (0);
}

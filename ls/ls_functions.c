#include "imports.h"




int listFiles(char *path)
{
	struct dirent **namelist;
	int n;
	int i = 0;

	n = scandir(path, &namelist, NULL, alphasort);
	if (n < 0)
	{
		perror("scandir");
		return (0);
	}

	for (; i < n; i++)
	{
		if (strcmp(namelist[i]->d_name, ".") == 0 || strcmp(namelist[i]->d_name, "..") == 0)
		{
			free(namelist[i]);
			continue;
		}

		printf("%s  ", namelist[i]->d_name);
		free(namelist[i]);
	}
	free(namelist);

	printf("\n");

	return (1);
}
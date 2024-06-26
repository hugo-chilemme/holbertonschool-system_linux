#include "imports.h"

/**
 * listFiles - list files in a directory
 * @path: path to the directory
 *
 * This function lists all the files in the specified directory.
 *
 * Return: 1 on success, 0 on failure
 */
int listFiles(char *path, char *execn, const int MUL_ARGS)
{
	DIR *dir;
	struct dirent *entry;
    struct stat file_info;
	const char *M_ERR_FNF = "No such file or directory";

	memset(&file_info, 0, sizeof(struct stat));

	lstat(path, &file_info);

	if (S_ISREG(file_info.st_mode))
	{
		printf("%s\n", path);
		return (1);
	}


	dir = opendir(path);
	if (dir == NULL)
	{
		fprintf(stderr, "%s: cannot access %s: %s\n", execn, path, M_ERR_FNF);
		closedir(dir);
		return (0);
	}

	if (MUL_ARGS == 1)
	{
		printf("%s:\n", path);
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

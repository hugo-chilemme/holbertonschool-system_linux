#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void checkPath(char *program_name, char *path)
{
	struct stat buffer;
	int status;

	status = lstat(path, &buffer);

	if (status == -1)
	{
		fprintf(stderr, "%s: cannot access %s: No such file or directory\n", program_name, path);
		return;
	}
	
}
/**
 * showDirectory - Display all folders and file a repository
 * @path: the target repository
 * Return: error code, 0 success
 */
void showDirectory(char *path, int showPath, int backspace)
{
	struct dirent *entry;
	DIR *dir;
	int count = 0;

	dir = opendir(path);

	if (!dir) 
		return;

	if (showPath)
		printf("%s:\n", path);

	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] == '.')
			continue;
		printf("%s  ", entry->d_name);
		count++;
	}

	free(entry);
	free(dir);

	if (backspace)
		printf("\n");
	printf("\n");
}

/**
 * main - Function
 * @argc: number of @argv
 * @argv: argument passed in command line
 * Return: -1 for error, 0 for success
 */
int main(int argc, char *argv[])
{
	int argv_i = 1;
	char *program_name = argv[0];

	if (argc > 1)
	{
		for (; argc > 1 && argv_i < argc; argv_i++)
		{
			checkPath(program_name, argv[argv_i]);
			showDirectory(argv[argv_i], argc > 2, argv_i != argc - 1);
		}
		return (0);
	}

	showDirectory(".", 0, 0);

	return (0);
}

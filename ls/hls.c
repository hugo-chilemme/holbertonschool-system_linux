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
		exit(EXIT_FAILURE);
	}
	if (!(buffer.st_mode & S_IRUSR))
	{
		fprintf(stderr, "%s: cannot open directory %s: Permission denied\n", program_name, path);
		exit(EXIT_FAILURE);
	}

	if (!(buffer.st_mode & S_IFDIR))
	{
		printf("%s\n", path);
		exit(EXIT_SUCCESS);
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
	char *files[2000];

	dir = opendir(path);

	if (!dir) 
		return;

	if (showPath)
		printf("%s:\n", path);

	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] == '.')
			continue;
		files[count] = entry->d_name;
		count++;
	}

	while (count > 0)
	{
		count--;
		printf("%s  ", files[count]);
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

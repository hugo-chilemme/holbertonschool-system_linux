#include "imports.h"
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	int index = 1;
	char *path_name = argv[0];

	if (argc == 1)
	{
		return (listFiles(".", path_name));
	}

	for (; index < argc; index++)
	{
		if (argc > 2)
		{
			printf("%s:\n", argv[index]);
		}
		listFiles(argv[index], path_name);
		if (argc > 2 && argc - 1 != index)
		{
			printf("\n");
		}
	}

	return (0);
}

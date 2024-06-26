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
	const int MUL_ARGS = argc > 2;

	if (argc == 1)
	{
		return (listFiles(".", path_name, MUL_ARGS));
	}

	for (; index < argc; index++)
	{
		listFiles(argv[index], path_name, MUL_ARGS);
		if (argc > 2 && argc - 1 != index)
		{
			printf("\n");
		}
	}

	return (0);
}

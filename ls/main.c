#include "imports.h"
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		return (listFiles("."));
	}
	return (listFiles(argv[1]));
}

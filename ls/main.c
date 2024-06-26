#include "imports.h"


int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		return (listFiles("."));
	}
	return (listFiles(argv[1]));
}

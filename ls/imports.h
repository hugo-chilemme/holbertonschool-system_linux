# ifndef IMPORTS
# define IMPOTS

#include <stdio.h>
#include <dirent.h>
#include <string.h>

void listFilesOrdered(DIR *d, int isFirst);
int listFiles(char *path);

# endif
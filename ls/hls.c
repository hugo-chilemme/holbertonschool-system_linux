#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    struct dirent *entry;
    DIR *dir;

    dir = opendir(".");

    if (!dir)
    {
        printf("opendir: error");
        return (-1);
    }

    while ((entry = readdir(dir)))
    {   
        printf("%s  ", entry->d_name);
    }

    printf("\n");

    return (0);
}
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char *envp[])
{
    struct dirent *entry;
    DIR *dir;
    int envp_i = 0;
    char *pwd;

    for (; envp[envp_i]; envp_i++) 
    {
        char *split = strtok(envp[envp_i], "="); 
        if (strcmp(split, "PWD") == 0)
            pwd = strtok(NULL, "=");
    }
    
    dir = opendir(pwd);

    if (!dir)
    {
        printf("opendir: error");
        return (-1);
    }

    while ((entry = readdir(dir)))
    {   
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        printf("%s  ", entry->d_name);
    }

    printf("\n");

    return (0);
}
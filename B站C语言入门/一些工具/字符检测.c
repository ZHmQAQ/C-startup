#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

long long int count_characters(char* filename);

int main()
{
    char path[100];
    printf("Enter path of directory: ");
    scanf("%s", path);

    struct dirent* de;
    DIR* dr = opendir(path);

    if (dr == NULL)
    {
        printf("Could not open directory");
        return 0;
    }

    long long int total_characters = 0;
    while ((de = readdir(dr)) != NULL)
    {
        if (strcmp(de->d_name, "..") == 0 || strcmp(de->d_name, ".") == 0)
            continue;
        char filename[100];
        strcpy(filename, path);
        strcat(filename, "/");
        strcat(filename, de->d_name);

        total_characters += count_characters(filename);
    }

    printf("Total characters in directory: %lld", total_characters);
    closedir(dr);
}

long long int count_characters(char* filename)
{
    FILE* fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }

    long long int count = 0;
    int c;
    while ((c = getc(fp)) != EOF)
        count++;

    fclose(fp);

    return count;
}
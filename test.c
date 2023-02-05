#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <direct.h>
#include <errno.h>
#include <stdbool.h>

#define SIZE 1000000

void createfile(void);
void insertstr(void);
void cat(void);

int main()
{
    char fst[SIZE], snd[SIZE];
    while (true)
    {
        scanf("%s", fst);
        if (!(strcmp(fst, "exit")))
            break;
        if (!(strcmp(fst, "createfile")))
        {
            scanf("%s", snd);
            if (!(strcmp(snd, "--file")))
                createfile();
        }
        if (!(strcmp(fst, "insertstr")))
        {
            scanf("%s", snd);
            if (!(strcmp(snd, "--file")))
                insertstr();
        }
        if (!(strcmp(fst, "cat")))
        {
            scanf("%s", snd);
            if (!(strcmp(snd, "--file")))
                cat();
        }
    }
}
void createfile()
{
    char address[SIZE], file_name[SIZE];
    scanf("%s", address);
    scanf("%s", file_name);
    if (!(strcmp(address, "\root")))
    {
        FILE *fptr;
        fptr = fopen(file_name, "w");
        fclose(fptr);
    }
    else
    {
        mkdir(address);
        chdir(address);
        FILE *fptr;
        fptr = fopen(file_name, "w");
        fclose(fptr);
    }
}
void insertstr()
{
    char append[SIZE], file_name[SIZE], address[SIZE];
    scanf("%s", address);
    scanf("%s", file_name);
    if (!(strcmp(address, "\root")))
    {
        FILE *fptr;
        fptr = fopen(file_name, "a");
        scanf("%s", append);
        fprintf(fptr, "%s", append);
        fclose(fptr);
    }
    else
    {
        chdir(address);
        FILE *fptr;
        fptr = fopen(file_name, "w");
        scanf("%s", append);
        fprintf(fptr, "%s", append);
        fclose(fptr);
    }
}
void cat()
{
    char file_name[SIZE], content[SIZE];
    scanf("%s", file_name);
    FILE *fptr;
    fptr = fopen(file_name, "r");
    fscanf(fptr, "%s", content);
    printf("%s", content);
}
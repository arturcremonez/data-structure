#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "file_manager.h"

char *createUrl(char *path, char *fileName)
{
    const int slashSize = 1;
    int urlSize = strlen(path) + slashSize + strlen(fileName);
    char *url = (char *)malloc((urlSize + 1) * sizeof(char));
    if (url == NULL)
    {
        printf("ERROR: Could not allocate memory for url.\n");
        exit(EXIT_FAILURE);
    }
    sprintf(url, "%s/%s", path, fileName);
    return url;
}

char *getFileText(char *fileUrl)
{
    FILE *file = fopen(fileUrl, "r");
    char *content;
    size_t n = 0;
    int c;
    if (file == NULL)
    {
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    content = malloc(fileSize);
    while ((c = fgetc(file)) != EOF)
    {
        content[n++] = (char)c;
    }
    content[n] = '\0';
    return content;
}

char *removeFileNameType(char *fileName)
{
    int index = 0;
    while (fileName[index] != '.')
    {
        if (fileName[index] == '\0')
        {
            return NULL;
        }
        index++;
    }
    index--;
    int typeSize = strlen(fileName) - index;
    int size = strlen(fileName) - typeSize;
    char *nameSliced = (char *)malloc((size + 1) * sizeof(char));
    int j = 0;
    for (int i = 0; i <= (strlen(fileName) - typeSize); i++, j++)
    {
        nameSliced[j] = fileName[i];
    }
    nameSliced[j] = '\0';
    return nameSliced;
}

char *insertTypeOnFileName(char *fileName, char *type)
{
    const int dotSize = 1;
    int nameSize = strlen(fileName) + dotSize + strlen(type);
    char *name = (char *)malloc((nameSize + 1) * sizeof(char));
    if (name == NULL)
    {
        printf("ERROR: Could not allocate memory for name.\n");
        exit(EXIT_FAILURE);
    }
    sprintf(name, "%s.%s", fileName, type);
    return name;
}

char *joinFileNames(char *firstFileName, char *secondFileName)
{
    const int hyphen = 1;
    int nameSize = strlen(firstFileName) + hyphen + strlen(secondFileName);
    char *name = (char *)malloc((nameSize + 1) * sizeof(char));
    if (name == NULL)
    {
        printf("ERROR: Could not allocate memory for name.\n");
        exit(EXIT_FAILURE);
    }
    sprintf(name, "%s-%s", firstFileName, secondFileName);
    return name;
}

char *getFileInput(char *path, char *file)
{
    char *url = createUrl(path, file);
    return url;
}

char *getFileSvgOutput(char *path, char *fileWithType)
{
    char *file = removeFileNameType(fileWithType);
    char *name = insertTypeOnFileName(file, "svg");
    char *url = createUrl(path, name);
    return url;
}

char *getMixedFilesTxtOutput(char *path, char *file1WithType, char *file2WithType)
{
    char *file1 = removeFileNameType(file1WithType);
    char *file2 = removeFileNameType(file2WithType);
    char *fileName = joinFileNames(file1, file2);
    char *name = insertTypeOnFileName(fileName, "txt");
    char *url = createUrl(path, name);
    return url;
}

char *getMixedFilesSvgOutput(char *path, char *file1WithType, char *file2WithType)
{
    char *file1 = removeFileNameType(file1WithType);
    char *file2 = removeFileNameType(file2WithType);
    char *fileName = joinFileNames(file1, file2);
    char *name = insertTypeOnFileName(fileName, "svg");
    char *url = createUrl(path, name);
    return url;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "parameter_manager.h"

typedef struct _paramameters
{
    char *geoName;
    char *qryName;
    char *inputDirectory;
    char *outputDirectory;
    char *degradationFactor;
} PARAMETERS;

bool isArgumentsAllocated(Parameters arguments)
{
    return arguments != NULL;
}

bool isEndOfArguments(int i, int argc)
{
    return i >= argc;
}

bool isGeoNameTheArgument(int i, char *argv[])
{
    return strcmp(argv[i], "-f") == 0;
}

bool isQueryNameTheArgument(int i, char *argv[])
{
    return strcmp(argv[i], "-q") == 0;
}

bool isInputDirectoryTheArgument(int i, char *argv[])
{
    return strcmp(argv[i], "-e") == 0;
}

bool isOutputDirectoryTheArgument(int i, char *argv[])
{
    return strcmp(argv[i], "-o") == 0;
}

bool isDegradationFactorTheArgument(int i, char *argv[])
{
    return strcmp(argv[i], "-fd") == 0;
}

bool isEndOfPathWithSlash(int argvLength, char path[])
{
    return path[argvLength - 1] == '/';
}

PARAMETERS *newParameters()
{
    PARAMETERS *arguments = (PARAMETERS *)malloc(sizeof(PARAMETERS));
    if (isArgumentsAllocated(arguments))
    {
        arguments->geoName = NULL;
        arguments->qryName = NULL;
        arguments->inputDirectory = NULL;
        arguments->outputDirectory = NULL;
        arguments->degradationFactor = NULL;
    }
    else
    {
        printf("ERROR: Could not allocate memory for empty params.\n");
        exit(EXIT_FAILURE);
    }
    return arguments;
}

char *getFileName(char *argv)
{
    char *fileName = malloc((strlen(argv) + 1) * sizeof(char));
    strcpy(fileName, argv);
    return fileName;
}

char *getPath(char *argv)
{
    int argvLength = strlen(argv);
    char *path = malloc((argvLength + 1) * sizeof(char));
    strcpy(path, argv);
    if (isEndOfPathWithSlash(argvLength, path))
    {
        path[argvLength - 1] = '\0';
    }
    return path;
}

Parameters initializeParameters(int argc, char *argv[])
{
    PARAMETERS *arguments = newParameters();
    int i = 1;
    while (!isEndOfArguments(i, argc))
    {
        if (isGeoNameTheArgument(i, argv))
        {
            arguments->geoName = getFileName(argv[i + 1]);
            i++;
        }
        else if (isQueryNameTheArgument(i, argv))
        {
            arguments->qryName = getFileName(argv[i + 1]);
            i++;
        }
        else if (isInputDirectoryTheArgument(i, argv))
        {
            arguments->inputDirectory = getPath(argv[i + 1]);
            i++;
        }
        else if (isOutputDirectoryTheArgument(i, argv))
        {
            arguments->outputDirectory = getPath(argv[i + 1]);
            i++;
        }
        else if (isDegradationFactorTheArgument(i, argv))
        {
            arguments->degradationFactor = getFileName(argv[i + 1]);
            i++;
        }
        i++;
    }
    return arguments;
}

char *getInputDirectory(Parameters parameters)
{
    if (!isArgumentsAllocated(parameters))
    {
        return NULL;
    }
    PARAMETERS *arguments = (PARAMETERS *)parameters;
    return arguments->inputDirectory;
}

char *getGeoName(Parameters parameters)
{
    if (!isArgumentsAllocated(parameters))
    {
        return NULL;
    }
    PARAMETERS *arguments = (PARAMETERS *)parameters;
    return arguments->geoName;
}

char *getOutputDirectory(Parameters parameters)
{
    if (!isArgumentsAllocated(parameters))
    {
        return NULL;
    }
    PARAMETERS *arguments = (PARAMETERS *)parameters;
    return arguments->outputDirectory;
}

char *getQryName(Parameters parameters)
{
    if (!isArgumentsAllocated(parameters))
    {
        return NULL;
    }
    PARAMETERS *arguments = (PARAMETERS *)parameters;
    return arguments->qryName;
}

char *getDegradationFactor(Parameters parameters)
{
    if (!isArgumentsAllocated(parameters))
    {
        return NULL;
    }
    PARAMETERS *arguments = (PARAMETERS *)parameters;
    return arguments->degradationFactor;
}

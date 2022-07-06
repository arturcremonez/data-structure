#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "parameter_manager.h"

int main(int argc, char *argv[])
{
    Parameters parameters = initializeParameters(argc, argv);
    char *inputDirectory = getInputDirectory(parameters);
    char *outputDirectory = getOutputDirectory(parameters);
    char *geoName = getGeoName(parameters);
    char *qryName = getQryName(parameters);
    char *degradationFactor = getDegradationFactor(parameters);
    printf("Input directory: %s\n", inputDirectory);
    printf("Output directory: %s\n", outputDirectory);
    printf("Geo name: %s\n", geoName);
    printf("Qry name: %s\n", qryName);
    printf("Degradation factor: %s\n", degradationFactor);
    return 0;
}

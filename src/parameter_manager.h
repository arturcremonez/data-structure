#ifndef PARAMATER_MANAGER_H
#define PARAMATER_MANAGER_H

/*
 * Parameter/Argument    | Optional | Descricption
 * -e path               |    S     | Entry base directory (BED)
 * -f filegeo.geo        |    N     | File with the shapes. This file must be under BED
 * -o path               |    N     | Output base directory (BSD)
 * -q filequery.qry      |    S     | File with queries. This file must be under BSD
 */

typedef void *Parameters;

/**
 * Inputs: argc being number of arguments passed in the program call and argv being vector containing the arguments.
 * Output: parameters.
 */
Parameters initializeParameters(int argc, char *argv[]);

/**
 * Input: parameters -> struct created with the initializeParameters function.
 * Output: string with input directory.
 */
char *getInputDirectory(Parameters parameters);

/**
 * Input: parameters -> struct created with the initializeParameters function.
 * Output: string with geo name.
 */
char *getGeoName(Parameters parameters);

/**
 * Input: prms -> struct created with the initializeParameters function.
 * Output: string with output directory.
 */
char *getOutputDirectory(Parameters parameters);

/**
 * Input: prms -> struct created with the initializeParameters function.
 * Output: string with query name.
 */
char *getQryName(Parameters parameters);

/**
 * Input: prms -> struct created with the initializeParameters function.
 * Output: string with degradation factor.
 */
char *getDegradationFactor(Parameters parameters);

#endif

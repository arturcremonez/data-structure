#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

/*
 * This module handles text from files.
 */

/**
 * Inputs: string with path and string with name.
 * Output: string with url = path/name.
 */
char *createUrl(char *path, char *fileName);

/**
 * Input: string with url of a file.
 * Output: string with file text.
 */
char *getFileText(char *fileUrl);

/**
 * Input: string with file name.
 * Output: return the file name without its type.
 */
char *removeFileNameType(char *fileName);

/**
 * Inputs: string with file name and file type.
 * Output: file name with type.
 */
char *insertTypeOnFileName(char *fileName, char *type);

/**
 * Inputs: two strings with file names.
 * Output: string with joined file names.
 */
char *joinFileNames(char *firstFileName, char *secondFileName);

/**
 * Inputs: string with input file directory and string with file name.
 * Output: string with input file url.
 */
char *getFileInput(char *path, char *file);

/**
 * Inputs: string with output file directory and string with file name.
 * Output: string with output file url.
 */
char *getFileSvgOutput(char *path, char *file);

/**
 * Inputs: string with output file directory and two strings with first and second file names.
 * Output: string with url = path/file1-file2.txt
 */
char *getMixedFilesTxtOutput(char *path, char *file1, char *file2);

/**
 * Inputs: string with output file directory and two strings with first and second file names.
 * Output: string with url = path/file1-file2.svg
 */
char *getMixedFilesSvgOutput(char *path, char *file1, char *file2);

#endif

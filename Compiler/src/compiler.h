#ifndef COMPILER_H
#define COMPILER_H

#include <stdlib.h>
#include <stdio.h>

FILE * tmpFile;
#define TMP_FILE_NAME "compiler_mid.tmp.c"

void freeResources();
void printHeaders();

#endif

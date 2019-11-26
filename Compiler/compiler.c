#include "y.tab.h"
#include <ctype.h>
#include <getopt.h>
#include "compiler.h"

extern FILE *yyin;

struct op_values {
    char * output;
    char * input;
} op;

static char * strCatFunction = "char * concatStrings(char * str1, char * str2) {\n"
                                "\tchar * newstr = malloc(strlen(str1) + strlen(str2) + 1);\n"
                                "\tstrcpy(newstr, str1);\n"
                                "\tstrcat(newstr, str2);\n"
                                "\treturn newstr;\n"
                            "}\n";

static char * strIntCatFunction = "char * concatIntString(char * str, int num, int sort) {\n"
                                "\tchar * newstr = malloc(strlen(str) + 20);\n"
                                "\tif (sort > 0)\n"
                                "\t\tsprintf(newstr, \"%s%d\", str, num);\n"
                                "\telse\n"
                                "\t\tsprintf(newstr, \"%d%s\", num, str);\n"
                                "\treturn newstr;\n"
                            "}\n";

static char * strIntMultFunction = "char * multiplyString(char * str, int num) {\n"
                                    "\tint len = strlen(str);\n"
                                    "\tchar * newstr = malloc(len * num + 1);\n"
                                    "\tnewstr[0] = 0;\n"
                                    "\tfor (int i = 0; i < num; i++)\n"
                                    "\t\tstrcpy(newstr + i * len, str);\n"
                                    "\treturn newstr;\n"
                                    "}\n";

static char * getCharToVar = "char * readOneChar() {\n"
                                "\tchar * str = malloc(2);\n"
                                "\tstr[0] = getchar();\n"
                                "\tstr[1] = 0;\n"
                                "\treturn str;\n"
                                "}\n\n\n";

void argParse(int argc, char *argv[], struct op_values * op)
{
    if(argc == 1)
    {
      fprintf(stderr, "Type the file to process as your first argument.\n");
	    exit(1);
    }

    op->input = argv[1];
    op->output = "a.out";
    opterr = 0; // If zero, getopt does not print any messages, but it still returns the character ? to indicate an error.
}

void initializeCompiler(char * inputFile) {
    FILE * read_file = fopen (inputFile, "r");
    if (read_file == NULL)
    {
        printf ("File not found or could not be opened.\n");
        exit(1);
    }

    yyin = read_file;

    tmpFile = fopen(TMP_FILE_NAME, "w");
    if (tmpFile == NULL) {
        printf ("An error occured while creating temporary C code file. Compiltion aborted.\n");
        exit(1);
    }
}

void freeResources() {
    fclose(tmpFile);
    fclose(yyin);
}

void printHeaders() {
    fprintf(tmpFile, "#include <stdio.h>\n");
    fprintf(tmpFile, "#include <stdlib.h>\n");
    fprintf(tmpFile, "#include <math.h>\n");
    fprintf(tmpFile, "#include <time.h>\n");
    fprintf(tmpFile, "#include <unistd.h>\n");
    fprintf(tmpFile, "#include <string.h>\n");
		fprintf(tmpFile, "#include \"Compiler/music.h\"\n\n");

    fprintf(tmpFile, "%s" , strCatFunction);
    fprintf(tmpFile, "%s" , strIntCatFunction);
    fprintf(tmpFile, "%s" , strIntMultFunction);
    fprintf(tmpFile, "%s" , getCharToVar);
}

void compileC(char * outputFile, int debug) {
    char commandBuffer[256];
    sprintf(commandBuffer, "gcc %s Compiler/music.c -o %s -L./Libraries/openal-soft/build -lopenal", TMP_FILE_NAME, outputFile);

    int gccStatus = system(commandBuffer);

    if(!debug && remove(TMP_FILE_NAME)) {
        printf ("An error occured while deleting temporary C code file.\n");
        exit(1);
    }

    if(gccStatus != 0) {
        printf ("An error occured while compiling temporary C code file.\n");
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    argParse(argc, argv, &op);
    initializeCompiler(op.input);
    yyparse();
    freeResources();

    // cambiar de true a false para version final
    compileC(op.output, 1);
    return 0;
}

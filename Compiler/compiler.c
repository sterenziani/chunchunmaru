#include "y.tab.h"
#include <ctype.h>
#include <getopt.h>
#include "compiler.h"
#include "music.h"

extern FILE *yyin;

struct op_values {
    char * output;
    char * input;
} op;

static char * functions =     "static struct termios old, current;\n\n"
                              "void initTermios(int echo){\n"
                                "tcgetattr(0, &old);\ncurrent = old;\ncurrent.c_lflag &= ~ICANON;\n"
                                "if(echo){\ncurrent.c_lflag |= ECHO;\n"
                                "}\nelse{\ncurrent.c_lflag &= ~ECHO;}\n"
                                "tcsetattr(0, TCSANOW, &current);\n}\n\n"
                              "void resetTermios(void){\ntcsetattr(0, TCSANOW, &old);\n}\n\n"
                              "char getch_(int echo){\nchar ch;\ninitTermios(echo);\nch = getchar();\nresetTermios();\nreturn ch;\n}\n\n"
                              "char getch(void){\nreturn getch_(0);\n}\n\n"
                              "char * readOneChar() {\n"
                                "char * str = malloc(2);\nstr[0] = getch();\n"
                                "str[1] = 0;\nreturn str;\n}\n\n"
                              "char* concatStrings(char * str1, char * str2){\n"
                                "char* newstr = malloc(strlen(str1) + strlen(str2) + 1);\nstrcpy(newstr, str1);\n"
                                "strcat(newstr, str2);\nreturn newstr;}\n\n"
                              "char * concatIntString(char * str, int num, int sort) {\n"
                                "char * newstr = malloc(strlen(str) + 20);\nif (sort > 0)\nsprintf(newstr, \"%s%d\", str, num);\n"
                                "else\nsprintf(newstr, \"%d%s\", num, str);\nreturn newstr;\n}\n"
                              "char * multiplyString(char * str, int num) {\n\n"
                                "int len = strlen(str);\nchar * newstr = malloc(len * num + 1);\nnewstr[0] = 0;\n"
                                "for (int i = 0; i < num; i++)\nstrcpy(newstr + i * len, str);\nreturn newstr;}\n\n\n";

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
    fprintf(tmpFile, "#include <termios.h>\n");
    fprintf(tmpFile, "#include <stdio.h>\n");
		fprintf(tmpFile, "#include \"Compiler/music.h\"\n\n");
    fprintf(tmpFile, "%s" , functions);
}

void compileC(char * outputFile, int debug, int music) {
    char commandBuffer[256];
    if(music)
      sprintf(commandBuffer, "gcc %s Compiler/music.c -o %s -L./Libraries/openal-soft/build -lopenal", TMP_FILE_NAME, outputFile);
    else
      sprintf(commandBuffer, "gcc %s Compiler/alt_music.c -o %s -L./Libraries/openal-soft/build", TMP_FILE_NAME, outputFile);

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
    compileC(op.output, 0, isThereMusic());
    return 0;
}

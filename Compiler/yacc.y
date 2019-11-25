%{
	#include <stdio.h>
  #include "node.h"
  #include "operations.h"
  #include "compiler.h"
	#include "music.h"

  extern int lines;

  int yylex();
	void yyerror(char * s);
%}

%union {
	struct Node * node;
	char * value;
}

/* Tokens */
%token          start end print play isnow endline if_token else_token endif while_token until endloop and or num_t text_t note_t plus minus times div_token open_p close_p equals ge le lt gt dif
%token<value>   num_c text_c note_c id
%type<node>     PROGRAM CODE INSTRUCTION ELIF CONDITION EXPRESSION TERM COMPARATOR TYPE DECLARATION ASSIGNMENT REASSIGNMENT
%start          PROGRAM

/* Precedencia */
%left plus minus
%left times div_token
%nonassoc equals dif ge gt lt le
%left and
%left or

/* Producciones */
%%
    PROGRAM:    start endline CODE end                                          { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, newNode(TYPE_LITERAL, "int main(){\n"));
                                                                                  append($$, $3);
                                                                                  append($$, newNode(TYPE_LITERAL, "}"));
                                                                                  printHeaders();
                                                                                  printInorder($$);
                                                                                }
    				    | start end                                                     {
                                                                                  $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, newNode(TYPE_LITERAL, "int main(){}\n"));
                                                                                };
                | start endline end                                             {
                                                                                  $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, newNode(TYPE_LITERAL, "int main(){}\n"));
                                                                                };

    CODE:       INSTRUCTION                                                     { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, $1);
                                                                                  append($$, newNode(TYPE_LITERAL, ";\n"));
                                                                                }
    				    | INSTRUCTION CODE                                              { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, $1);
                                                                                  append($$, newNode(TYPE_LITERAL, ";\n"));
                                                                                  append($$, $2);
                                                                                };


    INSTRUCTION:print EXPRESSION endline                                        { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  if ($2->type == TYPE_TEXT)
                                                                                      append($$, newNode(TYPE_LITERAL, "printf(\"%s\", "));
                                                                                  if ($2->type == TYPE_NUM)
                                                                                      append($$, newNode(TYPE_LITERAL, "printf(\"%d\", "));
                                                                                  if ($2->type == TYPE_NOTE)
                                                                                      append($$, newNode(TYPE_LITERAL, "printf(\"%s\", "));
                                                                                  append($$, $2);
                                                                                  append($$, newNode(TYPE_LITERAL, ")"));
                                                                                }
      				  | play EXPRESSION endline                                       { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  if ($2->type != TYPE_NOTE)
                                                                                      yyerror("Can't play text or numbers. Only notes.\n");
                                                                                  else
                                                                                  {
                                                                                    append($$, newNode(TYPE_LITERAL, "playNote("));
                                                                                    append($$, $2);
                                                                                    append($$, newNode(TYPE_LITERAL, ")"));
                                                                                  }
                                                                                }
      				  | DECLARATION endline                                           { $$ = $1;}
          			| ASSIGNMENT endline                                            { $$ = $1;}
          			| REASSIGNMENT endline                                          { $$ = $1;}
                | if_token CONDITION endline CODE endif endline                 { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, newNode(TYPE_LITERAL, "if("));
                                                                                  append($$, $2);
                                                                                  append($$, newNode(TYPE_LITERAL, "){\n"));
                                                                                  append($$, $4);
                                                                                  append($$, newNode(TYPE_LITERAL, "}\n"));
                                                                                }
          			| if_token CONDITION endline CODE ELIF endline                  { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, newNode(TYPE_LITERAL, "if("));
                                                                                  append($$, $2);
                                                                                  append($$, newNode(TYPE_LITERAL, "){\n"));
                                                                                  append($$, $4);
                                                                                  append($$, newNode(TYPE_LITERAL, "}\n"));
                                                                                  append($$, $5);
                                                                                }
          			| while_token CONDITION endline CODE endloop endline            { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, newNode(TYPE_LITERAL, "while("));
                                                                                  append($$, $2);
                                                                                  append($$, newNode(TYPE_LITERAL, "){\n"));
                                                                                  append($$, $4);
                                                                                  append($$, newNode(TYPE_LITERAL, "}"));
                                                                                }
          			| until CONDITION endline CODE endloop endline                  { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, newNode(TYPE_LITERAL, "while(!("));
                                                                                  append($$, $2);
                                                                                  append($$, newNode(TYPE_LITERAL, ")){\n"));
                                                                                  append($$, $4);
                                                                                  append($$, newNode(TYPE_LITERAL, "}"));
                                                                                };



    ELIF:       else_token if_token CONDITION endline CODE endif endline        { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, newNode(TYPE_LITERAL, "else if ("));
                                                                                  append($$, $3);
                                                                                  append($$, newNode(TYPE_LITERAL, "){\n"));
                                                                                  append($$, $5);
                                                                                  append($$, newNode(TYPE_LITERAL, "}\n"));
                                                                                }
      				  | else_token if_token CONDITION endline CODE ELIF               { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, newNode(TYPE_LITERAL, "else if("));
                                                                                  append($$, $3);
                                                                                  append($$, newNode(TYPE_LITERAL, "){\n"));
                                                                                  append($$, $5);
                                                                                  append($$, newNode(TYPE_LITERAL, "}\n"));
                                                                                  append($$, $6);
                                                                                }
      				  | else_token endline CODE endif endline                         { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, newNode(TYPE_LITERAL, "else {\n"));
                                                                                  append($$, $3);
                                                                                  append($$, newNode(TYPE_LITERAL, "}\n"));
                                                                                };



    CONDITION:    CONDITION or CONDITION                                        { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, $1);
                                                                                  append($$, newNode(TYPE_LITERAL, " || "));
                                                                                  append($$, $3);
                                                                                }
          				| CONDITION and CONDITION                                     { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, $1);
                                                                                  append($$, newNode(TYPE_LITERAL, " && "));
                                                                                  append($$, $3);
                                                                                }
                  | open_p CONDITION close_p                                    { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, newNode(TYPE_LITERAL, "("));
                                                                                  append($$, $2);
                                                                                  append($$, newNode(TYPE_LITERAL, ")"));
                                                                                }
                  | EXPRESSION COMPARATOR EXPRESSION                            { $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  if($1->type == TYPE_TEXT && $3->type == TYPE_TEXT)
                                                                                  {
                                                                                    append($$, newNode(TYPE_LITERAL, "strcmp("));
                                                                                    append($$, $1);
                                                                                    append($$, newNode(TYPE_LITERAL, ", "));
                                                                                    append($$, $3);
                                                                                    append($$, newNode(TYPE_LITERAL, ")"));
                                                                                    append($$, $2);
                                                                                    append($$, newNode(TYPE_LITERAL, "0"));
                                                                                  }
                                                                                  else if($1->type == TYPE_NUM && $3->type == TYPE_NUM)
                                                                                  {
                                                                                    append($$, $1);
                                                                                    append($$, $2);
                                                                                    append($$, $3);
                                                                                  }
                                                                                  else if($1->type == TYPE_NOTE && $3->type == TYPE_NOTE)
                                                                                  {
                                                                                    append($$, newNode(TYPE_LITERAL, "noteCmp("));
                                                                                    append($$, $1);
                                                                                    append($$, newNode(TYPE_LITERAL, ", "));
                                                                                    append($$, $3);
                                                                                    append($$, newNode(TYPE_LITERAL, ")"));
                                                                                    append($$, $2);
                                                                                    append($$, newNode(TYPE_LITERAL, "0"));
                                                                                  }
                                                                                };



    COMPARATOR:   equals                                                        {   $$ = newNode(TYPE_LITERAL, " == "); }
                  | gt                                                          {   $$ = newNode(TYPE_LITERAL, " > "); }
                  | ge                                                          {   $$ = newNode(TYPE_LITERAL, " >= "); }
                  | lt                                                          {   $$ = newNode(TYPE_LITERAL, " < "); }
                  | le                                                          {   $$ = newNode(TYPE_LITERAL, " <= "); }
                  | dif                                                         {   $$ = newNode(TYPE_LITERAL, " != "); };


    EXPRESSION:   EXPRESSION plus EXPRESSION                                    { $$ = expSum($1, $3); }
    				      | EXPRESSION minus EXPRESSION                                 { $$ = expSub($1, $3); }
    				      | EXPRESSION times EXPRESSION                                 { $$ = expMult($1, $3); }
    				      | EXPRESSION div_token EXPRESSION                             { $$ = expDiv($1, $3); }
                  | TERM                                                        { $$ = $1; };
                  | open_p EXPRESSION close_p                                   { if ($2->value != NULL)
                                                                                  $$ = $2;
                                                                                  else
                                                                                  {
                                                                                    $$ = newNode($2->type, NULL);
                                                                                    append($$, newNode(TYPE_LITERAL, "("));
                                                                                    append($$, $2);
                                                                                    append($$, newNode(TYPE_LITERAL, ")"));
                                                                                  }
                                                                                };



    TERM:         text_c                                                        { $$ = newNode(TYPE_TEXT, $1); }
    				      | num_c                                                       { $$ = newNode(TYPE_NUM, $1); }
                  | note_c                                                      { $$ = newNode(TYPE_NOTE, $1); }
                  | id                                                          { int type = getType($1);
																																									if (type == -1 || !isInCurrentScope($1))
																																										yyerror("Undeclared variable\n");
                                                                                  $$ = newNode(type, NULL);
                                                                                  append($$, newNode(TYPE_LITERAL, $1));
                                                                                };



    TYPE:         text_t                                                        { $$ = newNode(TYPE_TEXT, "char* "); }
                  | num_t                                                       { $$ = newNode(TYPE_NUM, "int "); }
                  | note_t                                                      { $$ = newNode(TYPE_NOTE, "note "); };



    DECLARATION: TYPE id ASSIGNMENT                                             { if (isInCurrentScope($2) == 1)
                                                                                    yyerror("Variable already declared\n");
                                                                                  if (addVar($2, $1->type) == -1)
                                                                                    yyerror("Exceeded max amount of variables.\n");
                                                                                  if ($3 != NULL && $1->type != $3->type) {
                                                                                    yyerror("Can't assign that value to a variable of that type.\n");
                                                                                  }
                                                                                  $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, $1);
                                                                                  append($$, newNode(TYPE_LITERAL, $2));
                                                                                  append($$, $3);
                                                                                };



    ASSIGNMENT:                                                                 { $$ = NULL;}
                | isnow EXPRESSION                                              { $$ = newNode($2->type, NULL);
                                                                                  append($$, newNode(TYPE_LITERAL, " = "));
                                                                                  append($$, $2);
                                                                                };



    REASSIGNMENT: id isnow EXPRESSION                                           { int type = getType($1);
																																									if (type == -1 || !isInCurrentScope($1))
																																										yyerror("Undeclared variable\n");
                                                                                  if (type != $3->type)
                                                                                      yyerror("Can't assign that value to a variable of that type\n");
                                                                                  $$ = newNode(TYPE_EMPTY, NULL);
                                                                                  append($$, newNode(TYPE_LITERAL, $1));
                                                                                  append($$, newNode(TYPE_LITERAL, " = "));
                                                                                  append($$, $3);
                                                                                };
%%

void yyerror(char * s){
    fprintf(stderr, "Error discovered in line %d: %s\n", lines, s);

    freeResources();

    if(remove(TMP_FILE_NAME)) {
        printf ("An error happened while deleting temporary C code file.\n");
        exit(1);
    }

	exit(1);
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

extern void yyerror(const char * msg);
int lines = 1;
%}

%x comment

alpha       [a-zA-z]
digit       [0-9]
number      {digit}+
n_length    [1-4]
octave      [0-2]
key         ([rR]|[acdfgACDFG]#?|[eEbB])
note        {n_length}{octave}{key}
newline		  [\n]
space       [ \t]
varname     {alpha}({alpha}|{digit}|'_')*

%%
"start"     {return start;}
"end"       {return end;}
"print"		  {return print;}
"play"      {return play;}
"="			    {return isnow;}
"\n"        {lines++; return endline;}
"//".*			{;}
"const"			{return const_token;}
"#"					{ yyerror("Invalid note value."); }

"if"			  {return if_token;}
"else"		  {return else_token;}
"end if"		{return endif;}
"while"     {return while_token;}
"until"     {return until;}
"end loop"  {return endloop;}

"and"				{return and;}
"or"				{return or;}

"num"		    {return num_t;}
"text"		  {return text_t;}
"note"      {return note_t;}

"+"				  {return plus;}
"-"				  {return minus;}
"*"				  {return times;}
"/"				  {return div_token;}
"("				  {return open_p;}
")"				  {return close_p;}

"=="        {return equals;}
">="			  {return gt;}
"<="			  {return lt;}
"<"					{return lt;}
">"					{return gt;}
"!="				{return dif;}

{space}		  {;}

-?{number}	{ char* str = malloc(strlen(yytext) + 1);
						  strcpy(str, yytext);
							yylval.value = str;
							return num_c;
            }

\"[^"]*\"   { char* str = malloc(strlen(yytext) + 1);
              strcpy(str, yytext);
              yylval.value = str;
              return text_c;
            }

{note}	    { char* str = malloc(strlen(yytext) + 1);
              strcpy(str, yytext);
              yylval.value = str;
              return note_c;
            }

{varname}   {	char* str = malloc(strlen(yytext) + 1);
						  strcpy(str, yytext);
							yylval.value = str;
							return id;
            }
%%

int yywrap(void){
	return 1;
}

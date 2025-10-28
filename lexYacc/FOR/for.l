%{
#include "y.tab.h"
%}

%option noyywrap

%%
"for"       {return FOR;}
"if"        {return IF;}
"else"      {return ELSE;}
"printf"    {return PRINT;}
"=="        {return EQL;}
"("         {return LP;}
")"         {return RP;}
[0-9]+      {return NUM;}
[a-zA-Z][a-zA-Z0-9]*    {return ID;}
"="         {return EQ;}
"+"         {return ADD;}
"-"         {return SUB;}
"<"         {return LT;}
">"         {return GT;}
">="        {return GE;}
"<="        {return LE;}
"++"        {return INC;}
"--"        {return DEC;}
";"         {return SEMI;}
"{"         {return LC;}
"}"         {return RC;}
"%"         {return MOD;}


[ \t\n]     ;
.
%%

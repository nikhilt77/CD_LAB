
%{
#include "y.tab.h"
%}
%option noyywrap
%%
"("     {return LP;}
")"     {return RP;}
";"     {return SEMI;}
">"     {return GT;}
"<"     {return LT;}
"+"     {return ADD;}
"-"     {return SUB;}
"*"     {return MUL;}
"/"     {return DIV;}
"&&"    {return AND;}
"||"    {return OR;}
"="     {return ASSIGN;}
"=="    {return EQ;}
"++"    {return INC;}
"--"    {return DEC;}
"!="    {return NOTEQ;}
[0-9]+  {return NUM;}
[a-zA-Z][a-zA-Z0-9]*    {return ID;}
[ \t\n]  ;
.
%%

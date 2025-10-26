%{
#include "y.tab.h"
%}
%option noyywrap
%%
"switch"                    {return SWITCH;}
":"                         {return FC;}
"default"                   {return DEFAULT;}
"break"                     {return BREAK;}
"return"                    {return RETURN;}
"case"                      {return CASE;}
"printf"                    {return PRINT;}
"if"                        {return IF;}
[0-9]+                      {return NUM;}
[a-zA-Z_][0-9a-zA-Z_]*      {return ID;}
"="                         {return EQ;}
";"                         {return SEMI;}
"++"                        {return INC;}
"--"                        {return DEC;}
"{"                         {return LC;}
"}"                         {return RC;}
"+"                         {return ADD;}
"-"                         {return SUB;}
"*"                         {return MUL;}
"/"                         {return DIV;}
"("                         {return LP;}
")"                         {return RP;}

">"                         {return LT;}
"<"                         {return GT;}
[ \t\n]                     ;
.                           {}
%%

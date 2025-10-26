
%{
#include "y.tab.h"
#include<stdio.h>
extern int yylval;

%}



%%
[0-9]+  {
            yylval=atoi(yytext);
            return digit;
        }
"+"     return ADD;
"-"     return SUB;
"*"     return MUL;
"/"     return DIV;
[ \t\n]+     ;
.
%%
int yywrap(void){
return 1;
}

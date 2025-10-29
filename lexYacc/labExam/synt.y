%{
#include<stdio.h>
#include<string.h>
int yylex();
void yyerror(const char *s);
%}

%token ADD SUB MUL DIV ID NUM LP RP EQ NOTEQ SEMI LT GT OR AND INC DEC ASSIGN
%left OR AND
%right EQ NOTEQ
%left LT GT
%left ADD SUB
%left MUL DIV

%left INC DEC

%%
S:
ID ASSIGN LP E RP EVL LP E RP BIN E
{printf("Valid Syntax\n");}
;
EVL:
LT|
GT
;
BIN:
OR|
AND
;
E:
NUM|
ID|
INC E|
DEC E|
E ADD T|
E SUB T|
E EQ T|
E NOTEQ T|
;
T:
T MUL F|
T DIV F|
F
;
F:
NUM|
ID|
INC F|
DEC F
;
%%

void yyerror(const char *s){
printf("Error occured:%s\n",s);
}

int main(){
printf("Enter expression:");
yyparse();
return 0;
}

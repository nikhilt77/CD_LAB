%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int yylex();
void yyerror(const char *s);
%}

%token INC DEC EQ LP RP ID NUM SEMI LT GT LC RC EQL MOD PRINT IF ELSE FOR LE GE ADD SUB

%left LT GT LE GE
%left ADD SUB
%left MOD
%right EQ
%right INC DEC



%%
S:
FOR LP EXP SEMI EXP SEMI EXP RP BODY
{printf("Valid String\n");}
;
BODY
:LC STMT_LIST RC
;
STMT_LIST:
STMT|
STMT STMT_LIST
;
STMT:
S|
EXP SEMI
;
EXP:
ID|
NUM|
ID EQ EXP|
ID INC|
ID DEC|
EXP LT EXP|
EXP GT EXP|
EXP LE EXP|
EXP GE EXP|
EXP MOD EXP|
EXP ADD EXP|
EXP SUB EXP
;
%%

void yyerror(const char *s){
printf("Error:%s\n",s);
}

int main(){
printf("Enter the expression:");
yyparse();
return 0;
}

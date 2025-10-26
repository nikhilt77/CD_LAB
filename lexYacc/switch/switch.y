%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int yylex(void);
void yyerror(const char *s);
%}
%token LP RP SWITCH CASE DEFAULT LC RC MUL DIV FC PRINT LT GT SEMI ID NUM RETURN IF ELSE BREAK EQ INC DEC ADD SUB
%left ADD SUB
%left INC DEC
%right ASSIGN

%%
S:
SWITCH LP ID RP FC BODY
{printf("Valid Syntax\n");exit(0);}
;
BODY:
CASE_LIST DEFAULT FC STMT_LIST BREAK SEMI
;
CASE_LIST:
CASE STUFF FC CASE_BODY BREAK SEMI CASE_LIST|

;
CASE_BODY:
RETURN NUM SEMI|
IF LP EXP RP LC STMT_LIST RC|
STMT_LIST
;
STMT_LIST:
STMT_LIST STMT|
;
STMT:
PRINT LP STUFF RP SEMI|
ID EQ ID SEMI|
ID EQ NUM SEMI|
INC ID SEMI|
DEC ID SEMI|
ID EQ ID ADD ID SEMI|
ID EQ ID SUB ID SEMI|
ID EQ ID MUL ID SEMI|
ID EQ ID DIV ID SEMI
;
EXP:
ID LT EQ ID|
ID GT EQ ID|
ID EQ EQ ID|
ID LT ID|
ID GT ID
;
STUFF:
ID|
NUM
;
%%
void yyerror(const char *s){
printf("Error:%s\n",s);
}
int main(){
printf("Enter Statement:");
yyparse();
return 0;
}

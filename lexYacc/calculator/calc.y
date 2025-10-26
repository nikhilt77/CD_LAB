
%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
void yyerror(const char *s);
%}

%token digit ADD MUL DIV SUB

%%
S:
E{printf("The value:%d\n",$1);}
;
E:
E ADD T{$$=$1+$3;}|
E SUB T{$$=$1-$3;}|
T{$$=$1;}
;
T:
T MUL F{$$=$1*$3;}|
T DIV F{$$=$1/$3;}|
F{$$=$1;}
F:
digit{$$=$1;}|
'(' E ')'{$$=$2;}
;
%%

void yyerror(const char *s){
printf("Error Occured Somewhere:%s\n",s);
}
int main(){
printf("Enter the statement:");
yyparse();
return 0;
}

%{
#include<stdio.h>
#include<string.h>

char name[20];
char first[5];
%}

%%
[a-zA-Z]+ {
            if(strstr(yytext,first)!=NULL){
                printf("%s is a substring of %s\n",yytext,first);
                exit(0);
            }
            else{
                printf("Not a substring\n");
            }
        }
[ \n]   ;
.       ;
%%

int yywrap(void){
    return 1;
}

int main(){
    printf("Enter Something:");
    scanf("%s",name);
    strncpy(first,name,4);
    while((getchar())!='\n');
    first[4]='\0';
    printf("Enter Something Else:");
    yylex();
    return 0;
}

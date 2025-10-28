#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define maxLength 20

char expression[maxLength];
char offset='Z';

void gen(char op){
    int i=0,j=0;
    char inter[maxLength];
    while(expression[i]!='\0'){
        if(expression[i]==op){
            printf("\n%c\t\t%c\t\t%c\t\t%c\n",op,offset,expression[i-1],expression[i+1]);
            inter[j-1]=offset;
            offset--;
            i+=2;
            continue;
        }
        inter[j++]=expression[i++];
    }
    inter[j]='\0';
    strcpy(expression,inter);
}

void genCode(){
    gen('*');
    gen('+');
    gen('=');
    gen('-');
    gen('/');
}

int main(){
    printf("Enter Expression:");
    scanf("%s",expression);
    printf("%-15s%-15s%-15s%-15s\n","Operator","Offset","Op1","Op2");
    genCode();
    return 0;
}

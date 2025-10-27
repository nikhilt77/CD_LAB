#include <_time.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define maxLength 20

char input[maxLength];
char lookahead;
int ind=0;

void E();
void F();
void EPrime();
void FPrime();
void TPrime();
void T();

void check(char c){
    if(c==lookahead){
        lookahead=input[ind++];
    }
    else{
        printf("%c not matched with %c\n",c,lookahead);
        exit(1);
    }
}

void E(){
    printf("E->TE'\n");
    T();
    EPrime();
}

void T(){
    printf("T->FT'\n");
    F();
    TPrime();
}

void EPrime(){
    if(lookahead=='+'){
        printf("E'->+TE'\n");
        check('+');
        T();
        EPrime();
    }
    else{
        printf("E'->e\n");
    }
}

void TPrime(){
    if(lookahead=='*'){
        printf("T'->*FT'\n");
        check('*');
        F();
        TPrime();
    }
    else{
        printf("T'->e\n");
    }
}

void F(){
    if(lookahead=='i'){
        printf("F->id\n");
        check('i');
    }
    else if(lookahead=='('){
        printf("F->(E)\n");
        check('(');
        E();
        check(')');
    }
    else{
        printf("Syntax error near %c\n",lookahead);
        exit(1);
    }
}

int main(){
    printf("Enter the input with i for id and terminate with $:");
    scanf("%s",input);
    ind=0;
    lookahead=input[ind++];
    E();
    if(lookahead=='$'){
        printf("Valid String\n");
    }
    else {
        printf("Syntax error at end of input\n");
    }
    return 0;
}

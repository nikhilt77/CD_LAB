#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define stackSize 20
#define inputSize 20

char stack[stackSize];
char input[inputSize];
int stackTop=-1;
int inputPointer=0;

void push(char c){
    stack[++stackTop]=c;
}

char pop(){
    if(stackTop==-1) return '\0';
    return stack[stackTop--];
}

bool isReducible(){
    if(stack[stackTop]=='i'){
        return true;
    }
    else if(stackTop>=2&&stack[stackTop-2]=='E'&&(stack[stackTop-1]=='+'||stack[stackTop-1]=='*')&&stack[stackTop]=='E'){
        return true;
    }
    else if(stackTop>=2&&stack[stackTop-2]=='('&&stack[stackTop-1]=='E'&&stack[stackTop]==')'){
        return true;
    }
    return false;
}

void reduce(){
    if(stack[stackTop]=='i'){
        pop();
        push('E');
        printf("Reduce E->i\n");
    }
    else if(stackTop>=2&&stack[stackTop-2]=='E'&&(stack[stackTop-1]=='+'||stack[stackTop-1]=='*')&&stack[stackTop]=='E'){
        pop();
        pop();
        pop();
        push('E');
        printf("Reduce E->E+E/E*E\n");
    }
    else if(stackTop>=2&&stack[stackTop-2]=='('&&stack[stackTop-1]=='E'&&stack[stackTop]==')'){
        pop();
        pop();
        pop();
        push('E');
        printf("Reduce E->(E)\n");
    }
}

void print(const char *action){
    char stackString[stackSize]="";
    char inputString[inputSize]="";
    int i;
    for(i=0;i<=stackTop;i++){
        stackString[i]=stack[i];
    }
    stackString[i]='\0';
    for(i=0;i<strlen(input)-inputPointer;i++){
        inputString[i]=input[inputPointer+i];
    }
    inputString[i]='\0';

    printf("%-30s%-30s%-30s\n",stackString,inputString,action);
}

int main(){
    printf("Enter input string and end with $:");
    scanf("%s",input);
    //input[strlen(input)]='\0';
    inputPointer=0;
    printf("%-30s%-30s%-30s\n","Stack","Input","Action");
    while(input[inputPointer]!='$'){
        print("Shift");
        push(input[inputPointer]);
        inputPointer++;
        while(isReducible()){
            reduce();
            print("Reduce");
        }
    }

    while(isReducible()){
        reduce();
        print("Reduce");
    }
    print("End");
    if(stackTop==0&&stack[stackTop]=='E'){
        printf("String accepted\n");
    }
    else{
        printf("String not accepted\n");
    }
    return 0;
}

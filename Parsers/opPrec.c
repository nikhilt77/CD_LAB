#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

#define inputLength 20
#define stackSize 20
#define maxLength 10

int stackPointer=0;
int inputPointer=0;
int row=0;
int col=0;
int numterminals=0;

char stack[stackSize];
char input[inputLength];
char optable[maxLength][maxLength][2];
char terminals[maxLength];

void printTable(){
    printf("\t");
    for(int i=0;i<numterminals;i++) printf("%c\t", terminals[i]);
    printf("\n");
    for(int i=0;i<numterminals;i++) {
        printf("%c\t", terminals[i]);
        for(int j=0;j<numterminals;j++) {
            printf("%c\t", optable[i][j][0]);
        }
        printf("\n");
    }
}

void stackAndInput(){
    for(int i=0;i<=stackPointer;i++){
        printf("%c",stack[i]);
    }
    printf("%*s",15-(stackPointer-1),"");
    for(int i=0;i<=inputPointer;i++){
        printf("%c",input[i]);
    }
    printf("%*s",15-(inputPointer+1),"");
}

int main(){

    printf("Enter no. of terminals:");
    scanf("%d",&numterminals);
    printf("Enter the terminals:");
    scanf("%s",terminals);

    printf("Enter input string:");
    scanf("%s",input);
    strcat(input,"$");
    stack[stackPointer]='$';

    printTable();

    printf("Enter the precedency stuff:\n");
    for(int i=0;i<numterminals;i++){
        for(int j=0;j<numterminals;j++){
            printf("Precedency [%c__%c]:",terminals[i],terminals[j]);
            scanf(" %c",&optable[i][j][0]);
        }
    }

    printf("The Table with...the stuff\n");
    printf("%-15s %-15s %-15s","Stack","Input","Action");
    printf("%-15s %-15s %-15s",stack,input,"Initial");
    while(inputPointer<=strlen(input)){
        for(int i=0;i<strlen(terminals);i++){
            if(stack[stackPointer]==terminals[i]) row=i;
            if(input[inputPointer]==terminals[i]) col=i;
        }
        if(stack[stackPointer]=='$'&&input[inputPointer]=='$'){
            printf("Accept\n");
            break;
        }
        else{
            if(optable[row][col][0]=='<'||optable[row][col][0]=='='){
                stack[++stackPointer]=optable[row][col][0];
                stack[++stackPointer]=input[inputPointer++];
                printf("Shift");
            }
            else if(optable[row][col][0]=='>'){
                while(stack[stackPointer]!='<'&&stackPointer>=0){
                    stackPointer--;
                }
                if(stack[stackPointer]=='<')stackPointer--;
                printf("Reduce\n");
            }
            else{
                printf("Not Accepted\n");
                break;
            }
        }
        printf("\n");
        stackAndInput();
    }
}

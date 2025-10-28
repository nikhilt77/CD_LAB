#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define maxLength 30
#define maxLines 10

char inters[maxLines][maxLength];
char assemb[10];
char currString[maxLength];
int currLine=0;

int main(){
    printf("Enter the intermediate codes(end with END):\n");
    while(1){
        scanf("%s",inters[currLine]);
        if(strcmp(inters[currLine],"END")==0){
            break;
        }
        currLine++;
    }
    for(int i=0;i<currLine;i++){
        strcpy(currString,inters[i]);
        printf("Target Code Table\n");
        switch(currString[3]){
            case '+':strcpy(assemb,"ADD");
                    break;
            case '-':strcpy(assemb,"SUB");
                    break;
            case '*':strcpy(assemb,"MUL");
                    break;
            case '/':strcpy(assemb,"DIV");
                    break;
            default:strcpy(assemb,"");
                    break;
        }
        printf("MOV %c,R%d\t",currString[2],i);
        printf("%s %c,R%d\t",assemb,currString[4],i);
        printf("MOV R%d,%c\n",i,currString[0]);
    }
}

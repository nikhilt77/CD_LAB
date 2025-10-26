
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define max_length 256
char line[max_length];

bool isOp(char c){
    char operators[]="+-*/&!";
    for(int i=0;i<strlen(operators);i++){
        if(c==operators[i]){
            return true;
        }
    }
    return false;
}

bool isDel(char c){
    char delimiters[]="{}():;\'\",=";
    for(int i=0;i<strlen(delimiters);i++){
        if(c==delimiters[i]){
            return true;
        }
    }
    return false;
}

bool isInt(char token[]){
    for(int i=0;i<strlen(token);i++){
        if(token[i]<'0'||token[i]>'9'){
            return false;
        }
    }
    return true;
}

bool isFloat(char token[]){
    for(int i=0;i<strlen(token);i++){
        if(token[i]!='.'&&(token[i]<'0'||token[i]>'9')){
            return false;
        }
        if(token[i]=='.'&&i==strlen(token)-1){
            return false;
        }
    }
    return true;
}

bool isKeyword(char token[]){
    char keywords[32][10]={"auto", "break", "case", "char", "const", "continue", "default", "do",
            "double", "else", "enum", "extern", "float", "for",
            "goto", "if", "int", "long", "register", "return", "short", "signed",
            "sizeof", "static", "struct", "switch", "typedef", "union",
            "unsigned", "void", "volatile", "while"};
    for(int i=0;i<32;i++){
        if(!strcmp(token,keywords[i])){
            return true;
        }
    }
    return false;
}



int main(){
    FILE *f=fopen("input.c","r");
    if(f==NULL){
        perror("Create the fucking file first\n");
        exit(0);
    }
    while(fgets(line,sizeof(line),f)){
        bool flag=false;
        for(int i=0;i<strlen(line);i++){
            if(line[i]=='/'&&line[i+1]=='/'){
                printf("Ignoring comments\n");
                flag=true;
            }
        }
        if(flag) continue;
        for(int i=0;i<strlen(line);i++){
            if(line[i]=='/'&&line[i+1]=='*'){
                printf("Found a multi line comment beginning\n");
                bool eF=false;
                while(fgets(line,sizeof(line),f)){
                    for(int j=0;j<strlen(line);j++){
                        if(line[j]=='*'&&line[j+1]=='/'){
                            printf("Multi line comment end found\n");
                            eF=true;
                        }
                    }
                    if(eF) break;
                }
                flag=true;
                break;
            }
        }
        if(flag) continue;
        char token[max_length];
        int ind=0;
        for(int i=0;i<strlen(line);i++){
            if(line[i]==' '||line[i]=='\t'||line[i]=='\n'||isOp(line[i])||isDel(line[i])){
                if(strcmp(token,"")){
                    if(isKeyword(token)){
                        printf("Keyword:%s\n",token);
                    }
                    else if(isInt(token)||isFloat(token)){
                        printf("Number:%s\n",token);
                    }
                    else {
                        printf("Identifier:%s\n",token);
                    }
                }
                strcpy(token,"");
                ind=0;
            }
            else{
                token[ind++]=line[i];
                token[ind]='\0';
            }
        }
    }
}

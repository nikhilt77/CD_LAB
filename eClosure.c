#include<stdio.h>
#include<stdbool.h>

#define states 20

int eTransTable[states][2];
int visited[states];
char result[states];
int totStates=0;
int totClosures=0;
int ind=0;

bool isVisited(int state){
    for(int i=0;i<ind;i++){
        if(visited[i]==state){
            return true;
        }
    }
    return false;
}

void eClosure(int state){
    result[ind]=state;
    visited[ind++]=state;
    printf("%d\n",state);
    for(int i=0;i<totClosures;i++){
        if(eTransTable[i][0]==state){
            int next=eTransTable[i][1];
            if(!isVisited(next)){
                eClosure(next);
            }
        }
    }
}

int main(){

    printf("Enter the no. of states:");
    scanf("%d",&totStates);
    printf("Enter no. of e transitions:");
    scanf("%d",&totClosures);
    printf("Enter e Transitions:\n");
    for(int i=0;i<totClosures;i++){
        scanf("%d%d",&eTransTable[i][0],&eTransTable[i][1]);
    }
    for(int i=0;i<totStates;i++){
        printf("E closure(%d):{",i);
        eClosure(i);
        printf("}\n");
        ind=0;
        for(int j=0;j<totStates;j++) visited[j]=0;
    }
}

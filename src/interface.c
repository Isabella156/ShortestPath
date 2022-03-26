#include "../include/interface.h"

int checkAnswer(char string1[]){
    int i;
    // check invalid answer
    for(i = 0;string1[i] != '\0';i++){
        if((string1[i] < '0' && string1[i] != '-') || string1[i] > '9'){
            printf("Invalid id!\n");
            return -1;
        }
    }
    // check if the id is correct
    i = findNodeById(atol(string1));
    if(i == -1){
        printf("No such location!\n");
        return -1;
    }else{
        ArcNode * arcNodePtr;
        arcNodePtr = map.vertices[i].firstArc->nextArc;
        if(arcNodePtr==NULL){
            printf("Isolated points!\n");
            return -1;
        }else{
            return i;
        }
    } 
}

static void printNode(){
    int i;
    ArcNode * arcNodePtr;
    for(i=0;i<VERTEX_NUM;i++){
        arcNodePtr = map.vertices[i].firstArc->nextArc;
        if(arcNodePtr == NULL){
            continue;
        }else{
            printf("%ld\n",map.vertices[i].id);
        }
    }
    printf("Please enter two IDs from the list above\n");
}

int interface(char answer1[], char answer2[]){
    if(readFile() == -1){
        return -1;
    }
    long int start;
    long int end;
    while(1){
        memset(answer1,'\0',100);
        printf("Enter y to continue, and enter others to exit:");
        scanf("%s",answer1);
        if(!strcmp(answer1,"y")){

        }else{
            break;
        }

        memset(answer1, '\0', 100);
        printNode();
        printf("Please enter the first node id:");
        scanf("%s",answer1);
        start = checkAnswer(answer1);
        if(start == -1){
            continue;
        }
        printf("Please enter the second node id:");
        scanf("%s",answer2);
        end = checkAnswer(answer2);
        if(end == -1){
            continue;
        }
        if(dijkstra(start, end) == -1){
            continue;
        }
    }
    return 0;
}
#include "../include/adjList.h"

int findNodeById(long int id){
    int i = 0;
    int find = 0;
    for(i=0;i<VERTEX_NUM;i++){
        if(map.vertices[i].id == id){
            find = 1;
            break;
        }
    }
    if(find){
        return i;
    }else{
        return -1;
    }
}

int checkNumberString(char string1[]){
    int i;
    const char check[50] = "Error in map file, please check the map file!\n"; 
    for(i=0;i<strlen(string1);i++){
        if(string1[i] != '-' && string1[i] != '.' && (string1[i] < '0' || string1[i] > '9')){
            printf("%s", check);
            return -1;
        }
    }
    return 0;
}

int readFile(){
    const char handle[50] = "Error in handling files!\n";
    FILE* fp = fopen("Final_Map.map","r");
    FILE* original = fopen("original.dat","w");
    if(fp == NULL || original == NULL){
        printf("%s", handle);
        return -1;
    }
    
    // string to store the data wihle reading file
    char string1[1000];
    // string to store the symbol in the data
    char symbol[6];
    // string to store the number
    char number[20];
    memset(string1,'\0',200);
    memset(symbol,'\0',6);
    // get the first line
    fscanf(fp,"%[^\n]s",string1);
    memset(string1,'\0',1000);

    // get the symbol
    fscanf(fp,"%s",symbol);
    
    // skip all edges
    while(!strcmp(symbol,"<link")){
        fscanf(fp,"%[^\n]s",string1);
        fgetc(fp);
        memset(string1,'\0',1000);
        fscanf(fp,"%s",symbol);
    }

    // count the vertex number
    int i = 0;
    ArcNode *arcNode;
    ArcNode *arcNode1, *arcNode2;
    map.vexNum = VERTEX_NUM;
    // scan the vertex
    while(!strcmp(symbol,"<node")){
        // scan the "id="
        fscanf(fp,"%3s",string1);
        // scan the id number;
        fscanf(fp,"%s",number);
        if(checkNumberString(number) == -1){
            return -1;
        }
        map.vertices[i].id = atol(number);
        memset(number,'\0',20);
        arcNode = (ArcNode*)malloc(sizeof(arcNode));
        arcNode->adjvex = map.vertices[i].id;
        arcNode->weight = 0;
        arcNode->nextArc = NULL;
        map.vertices[i].firstArc = arcNode;
        // scan the "lat="
        fscanf(fp,"%4s",string1);
        // scan the latitude number
        fscanf(fp,"%s",number);
        if(checkNumberString(number) == -1){
            return -1;
        }
        map.vertices[i].lat = atof(number);
        memset(number,'\0',20);
        // scan the "lon="
        fscanf(fp,"%4s",string1);
        // scan the longitude number
        fscanf(fp,"%s",number);
        if(checkNumberString(number) == -1){
            return -1;
        }
        map.vertices[i].lon = atof(number);
        // scan the rest line
        fscanf(fp,"%[^\n]s",string1);
        memset(string1,'\0',1000);
        fgetc(fp);
        i++;
        memset(symbol,'\0',6);
        fscanf(fp,"%s",symbol);
    }

    rewind(fp);
    // get the first line
    fscanf(fp,"%[^\n]s",string1);
    memset(string1,'\0',1000);

    // get the symbol
    fscanf(fp,"%s",symbol);
    int index1, index2;

    // scan the edges
    while(!strcmp(symbol,"<link")){
        // scan the id number
        fscanf(fp,"%s",string1);
        memset(string1,'\0',50);
        // scan "node="
        fscanf(fp,"%5s",string1);
        memset(string1,'\0',5);
        // scan the node1 id
        fscanf(fp,"%s",number);
        if(checkNumberString(number) == -1){
            return -1;
        }
        index1 = findNodeById(atol(number));
        arcNode1 = (ArcNode*)malloc(sizeof(arcNode1));
        memset(number,'\0',30);
        // scan "node="
        fscanf(fp,"%5s",string1);
        memset(string1,'\0',5);
        // scan the node2 id
        fscanf(fp,"%s",number);
        if(checkNumberString(number) == -1){
            return -1;
        }
        index2 = findNodeById(atol(number));
        arcNode2 = (ArcNode*)malloc(sizeof(arcNode2));
        memset(number,'\0',30);
        // scan the way string
        fscanf(fp,"%s",string1);
        memset(string1,'\0',30);
        // scan "length="
        fscanf(fp,"%7s",string1);
        memset(string1,'\0',7);
        // scan the length number
        fscanf(fp,"%s",number);
        if(checkNumberString(number) == -1){
            return -1;
        }
        arcNode1->weight = atof(number);
        arcNode2->weight = atof(number);
        /**********directed graph
        The first node scanned is taken as the starting point,
        the second node as the end point, vice versa**********/

        // first points to the second
        arcNode1->adjvex = map.vertices[index2].id;
        arcNode1->nextArc = map.vertices[index1].firstArc->nextArc;
        map.vertices[index1].firstArc->nextArc = arcNode1;

        // second points to the first
        arcNode2->adjvex = map.vertices[index1].id;
        arcNode2->nextArc = map.vertices[index2].firstArc->nextArc;
        map.vertices[index2].firstArc->nextArc = arcNode2;

        memset(number,'\0',30);
        // scan the rest line
        fscanf(fp,"%[^\n]s",string1);
        memset(string1,'\0',1000);
        fgetc(fp);
        memset(symbol,'\0',6);
        fscanf(fp,"%s",symbol);

        // output the data of the original file
        fprintf(original,"%f %f \"%ld\"\n",map.vertices[index1].lon,map.vertices[index1].lat,map.vertices[index1].id);
        fprintf(original,"%f %f \"%ld\"\n\n",map.vertices[index2].lon, map.vertices[index2].lat, map.vertices[index2].id);
    }
    fclose(fp);
    fclose(original);
    return 0;
}

int dijkstra(long int vs, long int ve){
    // index of start and end location
    const int vsIndex = vs;
    const int veIndex = ve;
    // for iteration and flag
    int i,k,currentIndex;
    // number of visited vertex
    int visited = 0;
    double pathDistance;
    if(vsIndex == veIndex){
        printf("Same location!\n");
        return -1;
    }
    ArcNode * arcNodePtr;

    // flag [i] - whether the shortest path from vertex vs to vertex i was obtained
    int flag[VERTEX_NUM]; 
    // distance[i] - the distance between the node and the parent node
    double distance[VERTEX_NUM];

    // initialization
    for(i=0;i<map.vexNum;i++){
        flag[i] = 0;
        distance[i] = INF;
        precursor[i] = -1;
    }

    // initialization for vertex vs
    flag[vsIndex] = 1;
    distance[vsIndex] = 0;
    currentIndex = vsIndex;

    

    while(currentIndex != veIndex){
        arcNodePtr = map.vertices[currentIndex].firstArc->nextArc;
        // update
        while(arcNodePtr){
            int arcNodeIndex = findNodeById(arcNodePtr->adjvex);
            // if the distance of the current vertex plus the weight of the edge
            // is less than the corresponding vertex distance
            if(distance[currentIndex] + arcNodePtr->weight < distance[arcNodeIndex] && flag[arcNodeIndex] == 0){
                // update the distance
                distance[arcNodeIndex] = distance[currentIndex] + arcNodePtr->weight;
                precursor[arcNodeIndex] = currentIndex;
                visited ++;
                // no path between two locations
                if(visited == VERTEX_NUM){
                    printf("There is no path between two locations!\n");
                    return -1;
                }
            }
            arcNodePtr = arcNodePtr->nextArc;
        }

        double min = INF;

        // scan the distance to find the smallest distance among the unselected vertices
        for(i=0;i<map.vexNum;i++){
            if(flag[i]==0&&distance[i]<=min){
                min = distance[i];
                k=i;
            }
        }

        // add - change the flag of the vertex
        flag[k]=1;
        // change current index
        currentIndex = k;
    }
    pathDistance = distance[veIndex];
    
    printf("shortest distance: %lf\n",pathDistance);
    printf("path:\n");

    i = veIndex;
    int j;
    j = map.vertices[veIndex].id;
    printf("%d\n",j);
    FILE *shortest = fopen("shortest.dat","w");
    if(shortest == NULL){
        return -1;
    }
    while(i != vsIndex){
        j = precursor[i];
        i = j;
        fprintf(shortest,"%f %f\n",map.vertices[j].lon,map.vertices[j].lat);
        j = map.vertices[j].id;
        printf("%d\n",j);
    }
    fclose(shortest);
    return 0;
}
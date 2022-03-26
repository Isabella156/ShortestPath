#ifndef GLOBAL_GUARD__H
#define GLOBAL_GUARD__H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define VERTEX_NUM 3941
#define INF 20000

// edge node definition
typedef struct arcNode{
    long int adjvex;
    struct arcNode *nextArc;
    double weight;
}ArcNode;

// vertext definition
typedef struct vNode{
    long int id;
    double lat;
    double lon;
    ArcNode *firstArc;
}VNode, adjList[VERTEX_NUM];

// graph definition
typedef struct{
    adjList vertices;
    int vexNum;
    int arcNum;
}graph;

graph map;
int precursor[VERTEX_NUM];

#endif
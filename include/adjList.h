#ifndef ADJLIST_GUARD__H
#define ADJLIST_GUARD__H
#include "global.h"

// find the index of the corresponding id
int findNodeById(long int id);
// check if the string stands for number
int checkNumberString(char string1[]);
// read in file and store data
int readFile();
// compute the shortest path
int dijkstra(long int vs, long int ve);

#endif
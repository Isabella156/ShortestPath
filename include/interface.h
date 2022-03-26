#ifndef INTERFACE_GUARD__H
#define INTERFACE_GUARD__H
#include "global.h"

extern int findNodeById(long int id);
extern int readFile();
extern int dijkstra(long int vs, long int ve);
// check whether the answer is legal
int checkAnswer(char string1[]);
// print the node
static void printNode();
// interface of the program
int interface(char answer1[], char answer2[]);

#endif
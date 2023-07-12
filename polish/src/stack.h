#ifndef STACK_H
#define STACK_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500
#define HEIGHT 25
#define WIDTH 80
#define CENTER_X (HEIGHT / 2)
#define CENTER_Y 0

typedef struct {
    double data[MAX];
    int top;
} Stack;

void init(Stack* stack);
int empty(Stack* stack) ;
void push(Stack* stack, double elem);
double take(Stack* stack);
void algorithm(char* strArray, char* newArray);
double function(char* array, int* flag, double numb);
void revers(char* array);
void tAw(char* newArray, int* j, Stack* temp);
#endif
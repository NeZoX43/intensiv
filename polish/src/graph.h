#ifndef ANN_H
#define ANN_H

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
int empty(Stack* stack);
void push(Stack* stack, double elem);
double take(Stack* stack);
int parseOper(char c);
int priority(char c);
double mathBase(double oper1, double oper2, char array);
double mathFunc(double oper1, char oper);
void algorithm(char* expression, char* prefixExpression);
double function(char* array, int* flag, double numb);
void revers(char* convNotation);
void tAw(char* newArray, int* j, Stack* temp);
int isdig(char a);
double chToDig(char* array, int* i);
int inputCheck(char* strArray);
void plot(int x, int y, char field[][WIDTH]);
void display(char field[HEIGHT][WIDTH]);
#endif

#ifndef OPER_H
#define OPER_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parseOper(char c);
int priority(char c);
double mathBase(double oper1, double oper2, char oper);
double mathFunc(double oper1, char oper);
int isdig(char a);

#endif
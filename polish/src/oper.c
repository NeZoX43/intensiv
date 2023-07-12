#include "graph.h"

int parseOper(char c) {
    int flag = 0;
    if (c == '+' || c == '-' || c == '*' || c == '/') flag = 1;
    if (c == 's' || c == 'c' || c == 't' || c == 'g' || c == 'q' || c == 'l' || c == 'u') flag = 2;

    return flag;
}

int priority(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case 's':
        case 'c':
        case 't':
        case 'g':
        case 'l':
        case 'q':
        case 'b':
            return 3;
    }
    return 0;
}

double mathBase(double oper1, double oper2, char oper) {
    switch (oper) {
        case '+':
            return oper1 + oper2;
        case '-':
            return oper1 - oper2;
        case '*':
            return oper1 * oper2;
        case '/':
            return oper1 / oper2;
    }
    return 0;
}

double mathFunc(double oper1, char oper) {
    switch (oper) {
        case 's':
            return sin(oper1);
        case 'c':
            return cos(oper1);
        case 't':
            return tan(oper1);
        case 'g':
            return 1 / tan(oper1);
        case 'l':
            return log(oper1);
        case 'q':
            return sqrt(oper1);
        case 'b':
            return -1 * (oper1);
    }
    return 0;
}

int isdig(char a) {
    return (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' ||
            a == '8' || a == '9');
}
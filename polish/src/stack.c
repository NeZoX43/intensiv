
#include "graph.h"


void init(Stack* stack) { stack->top = -1; }

int empty(Stack* stack) { return (stack->top == -1); }

void push(Stack* stack, double elem) {
    if (stack->top >= MAX - 1) {
        printf("n/a");
    }
    stack->data[++(stack->top)] = elem;
}

double take(Stack* stack) {
    if (empty(stack)) {
        printf("n/a");
    }
    return stack->data[(stack->top)--];
}
void algorithm(char* strArray, char* newArray) {
    Stack temp;
    init(&temp);

    int j = 0;

    for (int i = strlen(strArray) - 1; i >= 0; i--) {
        if (strArray[i] == ' ') {
            continue;  
        } else if (isdig(strArray[i]) != 0) {
            newArray[j++] = strArray[i];
        } else if (strArray[i] == 'x') {
            newArray[j++] = strArray[i];
        } else if (strArray[i] == ')') {
            push(&temp, strArray[i]);
        } else if (strArray[i] == '(') {
            for (; !empty(&temp) && temp.data[temp.top] != ')';) tAw(newArray, &j, &temp);

            if (!empty(&temp) && temp.data[temp.top] == ')') take(&temp);

        } else if (parseOper(strArray[i])) {
            for (; !empty(&temp) && priority(temp.data[temp.top]) > priority(strArray[i]);)
                tAw(newArray, &j, &temp);
            newArray[j++] = ' ';
            push(&temp, strArray[i]);
        }
    }
    for (; !empty(&temp);) tAw(newArray, &j, &temp);
    newArray[j] = '\0';
    

    revers(newArray);
}

double function(char* array, int* flag, double numb) {
    Stack temp;
    init(&temp);
    *flag = 0;
    
    double oper1, oper2;
    
    for (int i = strlen(array) - 1; i >= 0; i--) {
        if (array[i] == ' ') {
            continue;
        } else if (array[i] == 'x') {
            for (int i = 0; i < 200; i++)
            {
               push(&temp, numb);
                
            }
        }else if ((isdig(array[i]) != 0) ) {
            push(&temp, chToDig(array, &i));

        } else if (parseOper(array[i]) == 1) {
            oper1 = take(&temp);
            oper2 = take(&temp);
            push(&temp, mathBase(oper1, oper2, array[i]));
            *flag = 1;

        } else if (parseOper(array[i]) == 2) {
            oper1 = take(&temp);
            push(&temp, mathFunc(oper1, array[i]));
            *flag = 2;
        } else if (parseOper(array[i]) == 3) {
            oper1 = take(&temp);
            push(&temp, mathFunc(oper1, array[i]));
            *flag = 3;
        }
    }

    return take(&temp);
}
void revers(char* array) {
    int lenght = strlen(array);
    for (int i = 0; i < lenght / 2; i++) {
        char temp = array[i];
        array[i] = array[lenght - i - 1];
        array[lenght - i - 1] = temp;
    }
}



void tAw(char* newArray, int* j, Stack* temp) {
    newArray[(*j)++] = ' ';
    newArray[(*j)++] = take(temp);
}
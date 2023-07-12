#include "graph.h"

int main() {
    char strArray[MAX];char polishNot[MAX];
    int flag = 1; double res;
    fgets(strArray, sizeof(strArray), stdin);
    int arrS = strcspn(strArray, "\n");
    strArray[arrS] = '\0';
    int cout1=0;
    int cout2=0;
    int raz = strlen(strArray);
    for(int i = 0;i < raz;i++){
        if(strArray[i] == '('){
            cout1++;
        }
        else if(strArray[i] == ')'){
            cout2++;
        }
    }
    if(cout1 == cout2){
    flag=inputCheck(strArray);
 
        algorithm(strArray, polishNot);
    printf("%s\n", polishNot);
    double massX[200];
    char field[HEIGHT][WIDTH];
    if((flag ==1) || (flag==2)) {
        res = function(polishNot, &flag, 0);
        printf("%.2lf", res);
    } else if(flag == 3) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            field[i][j] = '.';
        }
    }   
    field[CENTER_X][CENTER_Y] = '+';
    for (int j=0; j < 200 ; j++)
    {
        massX[j]=j*0.16;

        res = function(polishNot, &flag, massX[j]);
        int graphX = CENTER_X - (int)(res * 4);  
        int graphY = CENTER_Y + (int)(j);   

        plot(graphX, graphY, field);
    }
    display(field);
    }
    }
    else{
        printf("n/a");
    }
    return 0;
}

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

double chToDig(char* array, int* i) {
    char arr[sizeof(array)];
    int j = 0;
    char* end;
    for (; (isdig(array[*i]) != 0); (*i)--) arr[j++] = array[*i];
    arr[j] = '\0';
    revers(arr);

    return strtod(arr, &end);
}

int inputCheck(char* strArray) {
    int flag =1;
    char* func[] = {"sin", "cos", "tan", "ctg", "sqrt", "ln", "--", "x"};
    const char s[] = {'s', 'c', 't', 'g', 'q', 'l', 'b'};
    for (int i = 0; i < 7; i++) {
        if (strArray[i] == 'x') flag =3;
        while ((strstr(strArray, func[i]) != NULL) && (strArray[i] != '\0')) {
            char* arr = strstr(strArray, func[i]);
            int j = strlen(strArray) - strlen(arr);
            strArray[j] = s[i];
            j++;
            int size = strlen(func[i]) + j;
            for (; j < size - 1; j++) {
                strArray[j] = ' ';
            }
            
        }
        int l, m;
        for (l = m = 0; strArray[l] != '\0'; l++)
            if (strArray[l] != ' ') strArray[m++] = strArray[l];
        strArray[m] = '\0';
    }
    return flag;
}

void plot(int x, int y, char field[HEIGHT][WIDTH])
{
    if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH) {
        field[x][y] = '*';
    }
}

void display(char field[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", field[i][j]);
        }
        printf("\n");
    }
}

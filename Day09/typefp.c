#include <stdio.h>
#include <stdlib.h>

typedef unsigned count_t;
typedef unsigned long liters_t;
typedef int (*operation_t)(int, int);

int sum(int, int);
int sub(int, int);
int mult(int, int);
int div(int, int);
//int (*getOp(char))(int,int);
operation_t getOp(char op);

int main(){
    // int (*fp)(int, int)
    operation_t fp;
    fp = sum;
    printf("Result = %d\n", fp(2, 4));
    printf("New ...\n");
    return EXIT_SUCCESS;
}

int sum(int a, int b){
    return a + b;
}


int mult(int a, int b){
    return a * b;
}


int sub(int a, int b){
    return a - b;
}


int div(int a, int b){
    return a / b;
}

/*int (*getOp(char op))(int,int){
    switch (op){
        case '+': 
            return sum;
        case '-': 
            return sub;
        case '*': 
            return mult;
        case '/': 
            return div;
        default:
             return NULL;
    }
} */

operation_t getOp(char op){
    switch (op){
        case '+': 
            return sum;
        case '-': 
            return sub;
        case '*': 
            return mult;
        case '/': 
            return div;
        default:
             return NULL;
    }
}
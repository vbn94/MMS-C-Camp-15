#include <stdio.h>

int sum(int, int);
int sub(int, int);
int mult(int, int);
int div(int, int);
int (*getOp(char))(int,int);

int main(){
    printf("Result = %d\n", getOp('+')(9, 100));
    printf("Result = %d\n", getOp('-')(9, 100));
    printf("Result = %d\n", getOp('*')(9, 100));
    printf("Result = %d\n", getOp('/')(900, 100));
    int (*f)(int, int) = getOp('+');
    int a = f(10, 45);
    printf("a = %d\n", a);
    return 0;
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

int (*getOp(char op))(int,int){
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
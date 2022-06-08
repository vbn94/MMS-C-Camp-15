#include <stdio.h>

double sum(double,double);
double sub(double,double);
double mult(double,double);
double div(double,double);

int main(){
    double (*operations[4])(double, double) = {sum, sub, mult, div};
    //operations[0] = sum;
    //operations[1] = sub;
    int opCode;
    double num1, num2;
    printf("Enter two numbers ");
    scanf("%lf %lf", &num1, &num2);
    printf("Enter operation (0->+, 1->-, 2->*, 3->/): ");
    scanf("%d", &opCode);
    printf("Result = %.2lf\n", operations[opCode](num1, num2));
    return 0;
}



double sum(double a, double b){
    return a + b;
}

double sub(double a, double b){
    return a - b;
}

double mult(double a, double b){
    return a * b;
}

double div(double a, double b){
    return a / b;
}
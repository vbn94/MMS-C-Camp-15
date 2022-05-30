#include <stdio.h>

int main(){
    double num1, num2, result;
    printf("Enter number 1: ");
    scanf("%lf", &num1);
    printf("Enter number 2: ");
    scanf("%lf", &num2);
    result = num1 + num2;
    printf("Sum = %.2lf\n", result);
    return 0;
}
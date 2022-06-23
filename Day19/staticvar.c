#include <stdio.h>

#define PI 3.1415


const int pi;

void printvalue(){
    static int a = 10;
    a++;
    printf("A = %d\n", a);
}

int main(){
    /*printvalue();
    printvalue();
    printvalue();*/

    double r = 2.5;
    double S = pi * r * r;

    return 0;
}
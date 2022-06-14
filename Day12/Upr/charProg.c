#include <stdio.h>
#include "chars.h"

int main(void){
    /*printf("%d\n", isDigit('7'));
    printf("%d\n", isDigit('y'));
    printf("%d\n", isAlpha('7'));
    printf("%d\n", isAlpha('y'));*/
    
    double num = 45e10;
    printf("%.2lf\n", num);
    /*int num = 20;
    if(!toInt("-125", &num)){
        printf("%d\n", num);
    } else {
        printf("Not a number!\n");
    }*/
    return 0;
}


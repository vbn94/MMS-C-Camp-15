#include <stdio.h>
#include <stdarg.h>

void printNums(int n, ...){
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++){
        int num = va_arg(args, int);
        printf("%d ", num);
    }
    putchar('\n');
    va_end(args);
}

int main(){
    printNums(4, 10, 4, 56, 3);
    printNums(2, -5, 100);
    printNums(8, 10, 40, 560, 30, 100, -50, 60, 70);
    return 0;
}
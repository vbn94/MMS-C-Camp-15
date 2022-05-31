#include <stdio.h>

int main(){
    int num;
    double x;
    char sym;
    int sNum = scanf("%d %c %lf", &num, &sym, &x);
    int pNum = printf("num = %d, x = %.2lf, sym = %c\n", num, x, sym);
    printf("sNum = %d, pNum = %d\n", sNum, pNum);
    return 0;
}
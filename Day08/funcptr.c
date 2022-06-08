#include <stdio.h>

int sum(int,int);
int sub(int,int);

int main(){
    int (*fp)(int,int);
    fp = sum;
    printf("Result = %d\n", fp(5, 6));
    fp = sub;
    printf("Result = %d\n", fp(5, 6));
    printf("Fp = %p\n", fp);
    printf("Sum = %p\n", sum);
    printf("Sub = %p\n", sub);
    printf("Size of Fp: %lu\n", sizeof(fp));
    return 0;
}



int sum(int a, int b){
    return a + b;
}


int sub(int a, int b){
    return a - b;
}
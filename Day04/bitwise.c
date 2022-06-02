#include <stdio.h>

int main(){
    int mask = 0;
    int bit = 2;
    mask |= (1 << bit); // set bit 2
    printf("mask = %d\n", mask);
    mask &= ~(1 << bit); // clear bit 2
    printf("mask = %d\n", mask);
    return 0;
}
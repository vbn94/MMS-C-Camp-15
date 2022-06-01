#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(){
    float a = 1.1;
    float b = 0;
    for (int i = 0; i < 12; i++){
        b += 0.1;
    }
    printf("a = %.20lf, b = %.20lf\n", a, b);
    /*if (a == b){
        printf("Equals\n");
    } else {
        printf("Not Equals\n");
    } */
    if (fabs(a - b) < 0.001){
        printf("Equals\n");
    } else {
        printf("Not Equals\n");
    }
    return 0;
}
#include <stdio.h>
#include <math.h>

// comment
int cylinder(double,double,double*,double*);

int main(){
    double r, h, S, V;
    while (scanf("%lf %lf", &r, & h) != EOF){
        if (!cylinder(r, h, &S, &V)){
            printf("S = %.2lf, V = %.2lf\n", S, V);
        } else {
            fprintf(stderr, "Invalid input data!\n");
        }
    }
    return 0;
}

int cylinder(double r, double h, double* V, double* S) {
    if (r <= 0 || h <= 0){
        return -1;
    }
    *V =  M_PI * r * r * h;
    *S = 2 * M_PI * r * r + 2 * M_PI * r * h;
    return 0;
}
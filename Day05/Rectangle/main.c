#include <stdio.h>

int rectInfo(double,double,double*,double*);

int main(){
    double area, perimeter, w, h;
    while (scanf("%lf %lf", &w, &h) != EOF){
        if(!rectInfo(w, h, &perimeter, &area)){
            printf("P = %.2lf, S = %.2lf\n", perimeter, area);
        } else {
            fprintf(stderr, "Invalid input data!\n");
        }
    }
    return 0;
}

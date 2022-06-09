#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int,int);
double randReal(double,double);

int main(){
    printf("RAND_MAX: %lu\n", RAND_MAX);
    srand(time(NULL));
    for (int i = 0; i < 100; i++){
        //printf("%.2lf\n", randReal(15, 20));
        printf("%c\n", randint('A', 'z'));
    }
    return 0;
}

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// suma
int main(int argc, char** argv){
    double sum = 0;
    if (!strcmp(argv[1], "-s")){
        for (int i = 2; i < argc; i++){
            double num;
            sscanf(argv[i], "%lf", &num);
            sum += num;
        }
        printf("Sum = %.2lf\n", sum);
    } else if (!strcmp(argv[1], "-M")){
        double max;
        sscanf(argv[2], "%lf", &max);
        for (int i = 3; i < argc; i++){
            double num;
            sscanf(argv[i], "%lf", &num);
            max = (num > max) ? num : max;
        }
        printf("Max = %.2lf\n", max);
    }
    return 0;
}
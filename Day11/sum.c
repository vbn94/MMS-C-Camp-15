#include <stdio.h>
#include <stdlib.h>

// suma
int main(int argc, char** argv){
    double sum = 0;
    for (int i = 0; i < argc; i++){
        double num = 0;
        sscanf(argv[i], "%lf", &num);
        sum += num;
        // sum += atoi(argv[i]);
    }
    printf("Sum = %lf\n", sum);
    return 0;
}
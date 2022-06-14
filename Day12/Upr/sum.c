#include <stdio.h>
#include "chars.h"

int main(int argc, char** argv){
    int sum = 0;
    for (int i = 1; i < argc; i++){
        int num;
        if(toInt(argv[i], &num)){
            fprintf(stderr, "%s is not a number!\n", argv[i]);
        } else {
            sum += num;
        }
    }
    printf("Sum = %d\n", sum);
    return 0;
}
#include <stdio.h>

int main(int argc, char **argv){
    int num1, num2, result;
    sscanf(argv[1], "%d", &num1);
    sscanf(argv[2], "%d", &num2);
    result = num1 + num2;
    printf("Result = %d\n", result);
    return 0;
}
#include <stdio.h>

int main(){
    int a = 1;
    int b = 0;
    if ((!a && b) || (a && !b)){
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}
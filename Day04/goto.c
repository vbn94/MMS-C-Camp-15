#include <stdio.h>

int main(){
    int a = 10;
    L1:
    printf("%d\n", a);
    a++;
    if(a < 20){
        goto L1;
    }
    return 0;
}
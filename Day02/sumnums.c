#include <stdio.h>
// MAX number
int main(){
    int num, sum = 0;
    while (scanf("%d", &num) != EOF){
        sum += num;
    }
    printf("%d\n", sum);
    return 0;
}
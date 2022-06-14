#include <stdio.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define PRINTNAME(name) printf(#name"\n")
#define PRINTVAL(num) printf("%s = %d\n", #num, num)
#define DEFINENUM(n,val) int num##n = val
#define PRINTNUM(n) printf("%d\n", num##n)

int max(int,int);

#define COUNT 3

int main(void){

    #if !defined(COUNT)    // #ifndef COUNT

    #endif

    #ifndef COUNT
        #error Count is not defined!
    #elif COUNT < 10
        #warning Count is too low!
    #endif

    printf("%s\n", __TIME__);
    /*printf("%s\n", __DATE__);
    printf("%s\n", __TIMESTAMP__);
    printf("%d\n", __LINE__);
    printf("%d\n", __STDC__);*/
    /*DEFINENUM(1, 20);
    DEFINENUM(2, 50);
    PRINTNUM(2);*/

    /*int a = 3, b = 5;
    int num = max(a, b);
    a++;
    b++;
    printf("Num = %d\n", num);
    printf("A = %d\n", a);
    printf("B = %d\n", b);*/
    /*PRINTNAME(Ivan);
    int a = 20;
    PRINTVAL(a);*/
    return 0;
}

int max(int a, int b){
    return a > b ? a : b;
}
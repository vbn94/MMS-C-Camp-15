#include <stdio.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define PRINTNAME(name) printf(#name"\n")
#define PRINTVAL(num) printf("%s = %d\n", #num, num)
#define DEFINENUM(n,val) int num##n = val
#define PRINTNUM(n) printf("%d\n", num##n)

int max(int,int);

#define OS 344

int main(void){
    #ifndef OS
        #error OS is not defined!
    #elif OS == 1
        printf("Windows!\n");
        #warning Windows OS is here! Be careful!
    #elif OS == 2
        printf("Linux\n");
    #elif OS == 3
        printf("MacOS\n");
    #else
        #error Invalid OS!
    #endif
    return 0;
}

int max(int a, int b){
    return a > b ? a : b;
}
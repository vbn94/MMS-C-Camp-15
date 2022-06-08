#include <stdio.h>
#include <string.h>

int main(){
    /*char* str1 = "aaa";
    char* str2 = "aca";
    printf("%d\n", strcmp(str1, str2));
    printf("%d\n", strcmp(str2, str1));
    printf("%d\n", strcmp("Hello", str1));*/

    char str[100];
    int num = 20;
    char sym = 'Y';
    double pi = 3.14;
    sprintf(str, "Number = %d, Symobol = %c, PI = %.2lf", num, sym, pi);
    printf("String: %s\n", str);
    char *text = "20 5.6 r";
    sscanf(text, "%d %lf %c", &num, &pi, &sym);
    printf("%d\n", num);
    return 0;
}
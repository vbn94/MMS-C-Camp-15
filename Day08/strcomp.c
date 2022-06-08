#include <stdio.h>
#include <string.h>

int main(){
    char* str1 = "aaa";
    char* str2 = "aca";
    printf("%d\n", strcmp(str1, str2));
    printf("%d\n", strcmp(str2, str1));
    printf("%d\n", strcmp("Hello", str1));
    return 0;
}
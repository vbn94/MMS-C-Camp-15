#include <stdio.h>
#include <string.h>

size_t mystrlen(const char*);

char* mystrncpy(char* dest, const char* src, size_t n){
    if (dest == NULL){
        return NULL;
    }
    int i = 0;
    while(*(src + i) && i < n){
        *(dest + i) = *(src + i);
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int main(void){
    /*char* str = "MMSCC"; // .rodata segment
    char str2[] = {'H', 0, 'e', 'l', 'l', 'o', '\0'};
    str[0] = 'N';
    printf("%s\n", str2);
    printf("Len str: %lu, Len str2: %lu\n", strlen(str), strlen(str2));
    printf("Size of str: %lu, Size of str: %lu \n", sizeof(str), sizeof(str2));*/

    /*char text[] = "MMS C Camp 15";
    printf("%lu ", mystrlen(text));
    printf("%lu\n", strlen(text));
    printf("%lu ", mystrlen("1234z"));
    printf("%lu\n", strlen("1234z"));
    printf("%lu ", mystrlen(""));
    printf("%lu\n", strlen(""));*/
    char str1[20], str2[20], str3[40];
    /*str3[0] = '\0';
    strncpy(str1, "MMS C Camp 15", 19);
    strncpy(str2, " 2022", 19);
    strncat(str3, str1, 19);
    strncat(str3, str2, 19);
    printf("Str3: %s\n", str3);
    printf("Str1 ptr: %lu\n", (size_t)str1);
    printf("Str2 ptr: %lu\n", (size_t)str2);*/
    printf("Str1: %s\n", mystrncpy(str1, "Hello MMS", 30));
    return 0;
}

size_t mystrlen(const char* str){
    size_t count = 0;
    while (*(str + count)){
        count++;
    }
    return count;
}
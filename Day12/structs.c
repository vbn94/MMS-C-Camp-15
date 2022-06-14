#include <stdio.h>
#include <stdint.h>

typedef struct {
    int a;
    int b;
    int c;
} str_a;

typedef struct {
    char a;
    char b;
    char c;
} str_b;

typedef struct {
    char a;
    int b;
    char c;
} str_c;

typedef struct {
    char a;
    char c;
    int b;
} str_d;




typedef struct {
    double a;
    int b;
    char c;
    char e;
    char f;
    char g;
} str_e;

typedef struct {
    char *s;
    int a;
} str_f;

typedef struct {
    int a;
    char sym;
    int *b;
    char c;
    uint16_t d;
    float f;
} str_g;

typedef struct {
    int a;
    char b[10];
} str_h;

typedef struct {
    int a;
    double b;
} str_i;


typedef struct {
    str_i a;
    int b;
} str_j;

int main(void){
    printf("Size of str_a: %lu B\n", sizeof(str_a));
    printf("Size of str_b: %lu B\n", sizeof(str_b));
    printf("Size of str_c: %lu B\n", sizeof(str_c));
    printf("Size of str_d: %lu B\n", sizeof(str_d));
    printf("Size of str_e: %lu B\n", sizeof(str_e));
    printf("Size of str_f: %lu B\n", sizeof(str_f));
    printf("Size of str_f: %lu B\n", sizeof(str_g));
    printf("Size of str_h: %lu B\n", sizeof(str_h));
    printf("Size of str_h: %lu B\n", sizeof(str_j));
    return 0;
}
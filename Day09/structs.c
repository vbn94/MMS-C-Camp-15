#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

// #pragma pack(1)

int randint(int,int);
double randReal(double,double);
char* randomName(char*);

/*struct point {
    double x;
    double y;
};
typedef struct point point_t;*/

typedef struct {
    double x;
    double y;
} point_t;

struct student {
    char name[50];
    uint8_t age;
    double grade;
};

int main(){
    point_t p1;
    p1.x = 5.6;
    p1.y = 18.3;
    point_t p2;
    p2.x = 20;
    p2.y = 50;
    printf("Point 1: %.1lf %.1lf\n", p1.x, p1.y);
    printf("Point 2: %.1lf %.1lf\n", p2.x, p2.y);
    printf("Sizeof point: %lu Bytes\n", sizeof(point_t));
    struct student st1, st2;
    strncpy(st1.name, "Pesho", 50);
    st1.age = 45;
    st1.grade = 4.50;
    printf("Sizeof student: %lu Bytes\n", sizeof(st1));
    return 0;
}

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

char* randomName(char* name){
    // [A-Z][a-z]{5,10} [A-Z][a-z]{5,10}
    // Stanislav Ivanov 
    unsigned index = 0;
    name[index++] = randint('A', 'Z');
    int n = randint(5, 10);
    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }
    name[index++] = ' ';
    n = randint(5, 10);
    name[index++] = randint('A', 'Z');
    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }
    name[index] = '\0';
    return name;
}
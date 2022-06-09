#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define COUNT 10

// #pragma pack(1)

int randint(int,int);
double randReal(double,double);
char* randomName(char*);

typedef struct student {
    char name[50];
    uint8_t age;
    double grade;
} student_t;

void studentInfo(student_t st){
    printf("Name: %24s, Age: %d, Grade: %.2lf\n", st.name, st.age, st.grade);
}

int main(){
    student_t st1 = { 
        .name="Ivan",
        .age=34,
        .grade=4.5
    };
    student_t st2 = {
        .name="Pesho",
        .age=15,
        .grade=5.6
    };
    //studentInfo(st1);
    //studentInfo(st2);

    student_t mmsStudents[COUNT];
    for (int i = 0; i < COUNT; i++){
        randomName(mmsStudents[i].name);
        mmsStudents[i].age = randint(10, 60);
        mmsStudents[i].grade = randReal(2.0, 6.0);
    }
    for (int i = 0; i < COUNT; i++){
        studentInfo(mmsStudents[i]);
    }
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
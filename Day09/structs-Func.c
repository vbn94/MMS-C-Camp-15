#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define COUNT 10

// #pragma pack(1)
typedef struct student {
    char name[50];
    uint8_t age;
    double grade;
} student_t;


int randint(int,int);
double randReal(double,double);
char* randomName(char*);
void studentInfo(student_t);
int compGrades(const void*, const void*);
int compAge(const void*, const void*);
int compName(const void*, const void*);

int main(){
    srand(time(NULL));
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

    // qsort(mmsStudents, COUNT, sizeof(*mmsStudents), compGrades);
    //qsort(mmsStudents, COUNT, sizeof(*mmsStudents), compAge);
    qsort(mmsStudents, COUNT, sizeof(*mmsStudents), compName);

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

void studentInfo(student_t st){
    printf("Name: %24s, Age: %d, Grade: %.2lf\n", st.name, st.age, st.grade);
}

int compGrades(const void* st1p, const void* st2p){
    student_t st1 = *(student_t*)st1p;
    student_t st2 = *(student_t*)st2p;
    if (fabs(st1.grade - st2.grade) < 0.01){
        return 0;
    } else if (st1.grade > st2.grade){
        return -1;
    }
    return 1;
}

int compAge(const void* st1p, const void* st2p){
    student_t st1 = *(student_t*)st1p;
    student_t st2 = *(student_t*)st2p;
    return st1.age - st2.age;
}

int compName(const void* st1p, const void* st2p){
    student_t st1 = *(student_t*)st1p;
    student_t st2 = *(student_t*)st2p;
    return strcmp(st1.name, st2.name);
}


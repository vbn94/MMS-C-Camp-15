#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int,int);
double randReal(double,double);
char* randomName(char*);


int main(){
    srand(time(NULL));
    char name[24];
    for (int i = 0; i < 10; i++){
        printf("%s\n", randomName(name));
    }
   /* printf("RAND_MAX: %lu\n", RAND_MAX);
    srand(time(NULL));
    for (int i = 0; i < 100; i++){
        //printf("%.2lf\n", randReal(15, 20));
        printf("%c\n", randint('A', 'z'));
    }*/
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
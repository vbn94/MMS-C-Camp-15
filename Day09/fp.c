#include <stdio.h>

int* map(int*, size_t, int (*)(int));
int* filter(const int* src, int* dest, size_t ns, size_t* nd, int (*check)(int));

int doubleNum(int);
int inc(int);

int isEven(int num){
    return !(num % 2);
}


int isOdd(int num){
    return (num % 2)
}

int main(){
    int nums[] = {1, 10, 5, 40, 6};
    /*map(nums, 5, inc);
    for (int i = 0; i < 5; i++){
        printf("%d ", nums[i]);
    }
    putchar('\n');*/
    int dest[10];
    size_t cnt;
    filter(nums, dest, 5, &cnt, isOdd);
    for (int i = 0; i < cnt; i++){
        printf("%d ", dest[i]);
    }
    putchar('\n');
    return 0;
}


int* map(int* array, size_t n, int (*func)(int)){
    for (int i = 0; i < n; i++){
        array[i] = (*func)(array[i]);
    }
    return array;
}

int doubleNum(int n){
    return 2*n;
}

int inc(int n){
    return n + 1;
}

int* filter(const int* src, int* dest, size_t ns, size_t* nd, int (*check)(int)){
    size_t destCount = 0;
    for (int i = 0; i < ns; i++){
        if (check(src[i])){
            dest[destCount] = src[i];
            destCount++;
        }
    }
    *nd = destCount;
    return dest;
}

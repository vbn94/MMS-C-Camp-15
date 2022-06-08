#include <stdio.h>
#include <stdlib.h>

#define LEN 10

int compare1(const void* num1, const void* num2){
    int n1 = *(int*)num1;
    int n2 = *(int*)num2;
    return n1 - n2;
}

int compare2(const void* num1, const void* num2){
    return *(int*)num2 - *(int*)num1;
}


int main(){
    int nums[LEN];
    for(int i = 0; i < LEN; i++){
        scanf("%d", nums + i);
    }

    // sorting
    qsort(nums, LEN, sizeof(nums[0]), compare1);
    for(int i = 0; i < LEN; i++){
        printf("%d ", nums[i]);
    }
    putchar('\n');

    qsort(nums, LEN, sizeof(nums[0]), compare2);
    for(int i = 0; i < LEN; i++){
        printf("%d ", nums[i]);
    }
    putchar('\n');

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define LEN 10

int compare1(const void* num1, const void* num2){
    int n1 = *(int*)num1;
    int n2 = *(int*)num2;
    return n1 - n2;
}

int main(){
    int nums[LEN];
    for(int i = 0; i < LEN; i++){
        scanf("%d", nums + i);
    }

    // sorting
    qsort(nums, LEN, sizeof(nums[0]), compare1);

    int key = 5;

    int* target = bsearch(&key, nums, LEN, sizeof(nums[0]), compare1);
    if (NULL == target){
        printf("%d not found!\n", key);
    } else {
        printf("%d found!\n", *target);
        printf("Index: %ld\n", ((size_t)target - (size_t)nums) / sizeof(int));
    }
    return 0;
}
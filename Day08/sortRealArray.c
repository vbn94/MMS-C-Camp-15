#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEN 4
#define EPS 0.001

int compare1(const void* num1, const void* num2){
    double n1 = *(double*)num1;
    double n2 = *(double*)num2;
    if (fabs(n1 - n2) < EPS){
        return 0;
    } else if (n1 > n2){
        return 1;
    }
    return -1;
}

int compare2(const void* num1, const void* num2){
    double n1 = *(double*)num1;
    double n2 = *(double*)num2;
    if (fabs(n1 - n2) < EPS){
        return 0;
    } else if (n1 > n2){
        return -1;
    }
    return 1;
}


int main(){
    double nums[LEN] = {6.7, 6.3, 6.8, 6.25};
   /* for(int i = 0; i < LEN; i++){
        scanf("%d", nums + i);
    }*/

    // sorting
    qsort(nums, LEN, sizeof(nums[0]), compare1);
    for(int i = 0; i < LEN; i++){
        printf("%lf ", nums[i]);
    }
    putchar('\n');

    qsort(nums, LEN, sizeof(nums[0]), compare2);
    for(int i = 0; i < LEN; i++){
        printf("%lf ", nums[i]);
    }
    putchar('\n');

    return 0;
}
#include <stdio.h>

int main(){
    int nums[4]; //= { 5, 3, -30, 10 };
    //printf("%d\n", 2[nums]);
    /*printf("%lu\n", (unsigned long)nums);
    printf("%lu\n", (unsigned long)(nums + 1));
    printf("%d\n", *nums);
    printf("%d\n", *(nums + 1));*/
    /*nums[0] = 5;
    nums[1] = 3;
    nums[2] = -30;
    nums[3] = 10;*/

    for (int i = 0; i < 4; i++){
        //scanf("%d", &nums[i]);
        //scanf("%d", &(*(nums + i)));
        scanf("%d", nums + i);
    }
    for (int i = 0; i < 4; i++){
        //printf("%d ", nums[i]);
        printf("%d ", *(nums + i));
        //printf("%d ", i[nums]);
        //printf("%d ",  *(i + nums));
    }
    putchar('\n');
    return 0;
}
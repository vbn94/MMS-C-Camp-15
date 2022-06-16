#include <stdio.h>
#include <math.h>

int printArr(int matrix[][10]){
    printf("%lu\n", (size_t)matrix);
    printf("%lu\n", (size_t)(matrix + 1));
    printf("%d\n", abs(((size_t)matrix - (size_t)(matrix + 1))));
    return 0;
}

int main(){

    int matrix[][3] = {
        {3, 4, 5},
        {1, 2, 4},
        {5, 67, 3},
        {-5, 23, 45},
    };

    printArr(matrix);

    return 0;
}
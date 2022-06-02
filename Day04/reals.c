#include <stdio.h>

int main(){
    float numf = 167883448.3f;
    double numd = 167883448.3;
    long double numld = 167883448.3L;
    printf("Float number = %.20f\n", numf);
    printf("Double number = %.30lf\n", numd);
    printf("Long double number = %.30Lf\n", numld);
    return 0;
}
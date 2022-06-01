#include <stdio.h>

int main(){
    // HEX <-> DEC
    unsigned num, opt;
    printf("1. HEX -> DEC\n2. DEC -> HEX\nEnter option: ");
    scanf("%d", &opt);
    if (opt == 1){
        scanf("%x", &num);
        printf("%x(16) = %d(10)\n", num, num);
    } else if (opt == 2) {
        scanf("%d", &num);
        printf("%d(10) = %x(16)\n", num, num);
    } else {
        fprintf(stderr, "Invalid option!\n");
        return 1;
    }
    return 0;
}
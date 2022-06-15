#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

union intchar {
    uint32_t numi;
    uint8_t numc[4];
}; 

struct bytes {
    uint8_t byte0;
    uint8_t byte1;
    uint8_t byte2;
    uint8_t byte3;
};

union intchar2 {
    uint32_t numi;
    struct bytes b;
};

#define BE

#if defined(LE)
union intchar3 {
    uint32_t numi;
    struct {
        uint8_t byte0;
        uint8_t byte1;
        uint8_t byte2;
        uint8_t byte3;
    };
}; 
#elif defined(BE)
union intchar3 {
    uint32_t numi;
    struct {
        uint8_t byte3;
        uint8_t byte2;
        uint8_t byte1;
        uint8_t byte0;
    };
};
#endif

typedef struct  {
    uint8_t u : 3;
    uint8_t g : 3;
    uint8_t o : 3;
} perm;

typedef union {
    uint8_t data;
    struct {
        uint8_t bit0 : 1;
        uint8_t bit1 : 1;
        uint8_t bit2 : 1;
        uint8_t bit3 : 1;
        uint8_t bit4 : 1;
        uint8_t bit5 : 1;
        uint8_t bit6 : 1;
        uint8_t bit7 : 1;
    };
} Reg;

int main(){
    /*perm p1;
    printf("%lu Bytes\n", sizeof(p1));
    p1.u = 0;
    for (int i = 0; i < 20; i++){
        printf("%d\n", p1.u);
        p1.u++;
    }
   /* //bool isRain = true;
    //printf("%lu\n", sizeof(bool));
    union  intchar ic;
    ic.numi = 0x11223344;
    printf("%x\n", ic.numc[0]);
    printf("%x\n", ic.numc[1]);
    printf("%x\n", ic.numc[2]);
    printf("%x\n", ic.numc[3]);

    union  intchar2 ic2;
    ic2.numi = 0x11223344;
    printf("%x\n", ic2.b.byte0);
    printf("%x\n", ic2.b.byte1);
    printf("%x\n", ic2.b.byte2);
    printf("%x\n", ic2.b.byte3);

    union  intchar3 ic3;
    ic3.numi = 0x11223344;
    printf("%x\n", ic3.byte0);
    printf("%x\n", ic3.byte1);
    printf("%x\n", ic3.byte2);
    printf("%x\n", ic3.byte3);*/

    Reg reg1;
    reg1.data = 0;
    reg1.bit0 = 0;
    reg1.bit1 = 1;
    reg1.bit2 = 1;
    reg1.bit3 = 1;
    reg1.bit4 = 1;
    reg1.bit5 = 1;
    reg1.bit6 = 1;
    reg1.bit7 = 1;
    printf("%d\n", reg1.data);
    return 0;
}
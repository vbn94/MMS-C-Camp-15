#include <stdio.h>
#include <stdint.h>

typedef union {
    int a;
    int b1;
    int d;
    int h;
    int u;
    double b;
} unA;

void printBits(uint64_t num){
    for (int i = 63; i >= 0; i--){
        printf("%llu", (num & (1ull << i)) >> i);
    }
    putchar('\n');
}

void printBitsD(double num){
    union {
        uint64_t a;
        double b;
    } u;
    u.b = num;
    for (int i = 63; i >= 0; i--){
        printf("%llu", (u.a & (1ull << i)) >> i);
    }
    putchar('\n');
}

typedef union {
    uint64_t num;
    double realNum;
} intreal_t;


union byteAccess {
    uint16_t number;
    uint8_t byte[2];
};

union byteAccess4 {
    uint32_t num;
    uint8_t byte[4];
};

int main(void){
   /* intreal_t u;
    u.realNum = 12.45;
    u.num = 0;
    printBits(u.num);
    printf("Number: %lf\n", u.realNum);
    u.num |= (1ull << 63);
    printf("Number: %lf\n", u.realNum);
    */
    union byteAccess un;
    un.number = 0xfa56; // byte[0] = 56, byte[1] = fa
    printf("Byte[0] = %x\n", un.byte[0]);
    printf("Byte[1] = %x\n", un.byte[1]);

    union byteAccess4 un2;
    un2.num = 0x01020304;
    printf("%d\n", un2.byte[0]);
    printf("%d\n", un2.byte[1]);
    printf("%d\n", un2.byte[2]);
    printf("%d\n", un2.byte[3]);

    union {
     uint8_t u8; uint16_t u16; uint32_t u32; uint64_t u64;
    } u = { .u64 = 0x4A };
    puts(u.u8 == u.u16 && u.u8 == u.u32 && u.u8 == u.u64 ? "LE" : "BE");
    return 0;
}
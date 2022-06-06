#include <stdio.h>
#include <stdint.h>

unsigned bitsNCount(uint64_t,uint32_t,uint16_t,uint8_t);
void flipOddBits(uint64_t*);
int checkBit(uint16_t, unsigned);
void setBit(uint16_t*, unsigned);
void clearBit(uint16_t*,unsigned);
void mirrorBits(uint16_t*);

int main(){
    printf("Ones count: %u\n", bitsNCount(-1ULL, -1, -1, -1));
    printf("Ones count: %u\n", bitsNCount(-1ULL, -1, -1, 0));
    uint64_t m = -1ul;
    flipOddBits(&m);
    printf("Mask: %lu\n", m);

    uint16_t mask2 = 0xff00;
    mirrorBits(&mask2);
    printf("Mask2 = %u\n", mask2);
    return 0;
}

unsigned bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4){
    unsigned count = 0;
    for (int bit = 0; bit < sizeof(uint64_t) * __CHAR_BIT__; bit++){
        count += (mask1 & (1UL << bit)) >> bit;
    }
    for (int bit = 0; bit < sizeof(uint32_t) * __CHAR_BIT__; bit++){
        count += (mask2 & (1U << bit)) >> bit;
    }
    for (int bit = 0; bit < sizeof(uint16_t) * __CHAR_BIT__; bit++){
        count += (mask3 & (1U << bit)) >> bit;
    }
    for (int bit = 0; bit < sizeof(uint8_t) * __CHAR_BIT__; bit++){
        count += (mask4 & (1U << bit)) >> bit;
    }
    return count;
}

void flipOddBits(uint64_t* mask){
    for (int bit = 1; bit < sizeof(uint64_t) * __CHAR_BIT__; bit += 2){
        *mask ^= (1UL << bit);
    }
}

int checkBit(uint16_t mask, unsigned bit){
    return (mask & (1 << bit)) >> bit; // 0, 1
}

void setBit(uint16_t* mask, unsigned bit){
    *mask |= (1 << bit);
}


void clearBit(uint16_t* mask, unsigned bit){
    *mask &= ~(1 << bit);
}

void mirrorBits(uint16_t* mask){
    for (int bit = 0; bit < sizeof(*mask) * __CHAR_BIT__ / 2; bit++){
        int bit1 = checkBit(*mask, bit);   
        int bit2 = checkBit(*mask, 15 - bit); 
        if (bit1){
            setBit(mask, 15 - bit);
        } else {
            clearBit(mask, 15 - bit);
        }
        if (bit2){
            setBit(mask, bit);
        } else {
            clearBit(mask, bit);
        }
    }
}


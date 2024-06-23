//
// Created by jfetko on 6/23/24.
//
#include "Utilities.h"

uint64_t gen_bitboard(int squares[], int len){
    uint64_t bitboard = 0;
    for(int i = 0; i < len; i++){
        bitboard |= (1 << squares[i]);
    }
    return bitboard;
}

// Reverses the bits of a 64-bit integer
uint64_t reverse_bits(uint64_t n){
    uint64_t mask = ((uint64_t)1);
    uint64_t reversed = 0;
    while(mask > 0){
        reversed <<= 1;
        if(n & mask){
            reversed |=1;
        }
        mask <<= 1;
    }
    return reversed;
}

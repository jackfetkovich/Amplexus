//
// Created by jfetko on 6/23/24.
//
#include "Utilities.h"
#include "AmplexusTypes.h"

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

Move generate_move_string(int white, uint64_t start, uint64_t end, int piece, int capture, int en_pass, int promo, int k_castle, int q_castle){
    Move move;
    move = (((uint32_t)white) << 31) | ((start) << 30) | ((end) << 24) |
            (((uint32_t)piece) << 18) | (((uint32_t)capture) << 15) | (((uint32_t)en_pass) << 14) |
            (((uint32_t)promo) << 13) | (((uint32_t)k_castle) << 10) | (((uint32_t)q_castle) << 9);
    return move;
}

//
// Created by jfetko on 6/23/24.
//

#ifndef AMPLEXUS_UTILITIES_H
#include <inttypes.h>
#include "AmplexusTypes.h"

uint64_t gen_bitboard(int squares[], int len);
uint64_t reverse_bits(uint64_t n);
Move generate_move_string(int, int, int, int, int, int, int , int, int);



#define AMPLEXUS_UTILITIES_H

#endif //AMPLEXUS_UTILITIES_H

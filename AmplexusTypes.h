//
// Created by jfetko on 6/14/24.
//

#ifndef AMPLEXUS_AMPLEXUSTYPES_H
#define AMPLEXUS_AMPLEXUSTYPES_H

#include <inttypes.h>

#define OCCUPIED_SQUARES(pos) \
        pos.wk & pos.wr & pos.wn & \
        pos.wb & pos.wq & pos.wp & \
        pos.bk & pos.br & pos.bn & \
        pos.bb & pos.bb & pos.bq & \
        pos.bp

// Defines a position
typedef struct {
    uint64_t wk; // white king
    uint64_t wr; // white rook
    uint64_t wn; // white knight
    uint64_t wb; // white bishop
    uint64_t wq; // white queen
    uint64_t wp; // white pawn

    uint64_t bk; // black king
    uint64_t br; // black rook
    uint64_t bn; // black knight
    uint64_t bb; // black bishop
    uint64_t bq;
    uint64_t bp;

    int num_moves;
    int wcastled;
    int wk_moved;
    int wr1_moved;
    int wr2_moved;

    int bcastled;
    int bk_moved;
    int br1_moved;
    int br2_moved;

    int last_capture_move;
    int last_pawn_move;
} Position;


// Move
/*
 * Color - 1 bit
 * Starting square - 6 bits
 * End square - 6 bits
 * Piece type - 3 bits
 * Capture - 1 bit
 * En passant - 1 bit
 * Promotion - 3 bits (one for flag, others for piece type)
 * Kingside castle - 1 bit
 * Queenside castle - 1 bit
 *
 *
 * (Starting square)(End Square)(PT)(Capture)(EP)(Promote)(KC)(QC)
 *
 * */
typedef uint32_t Move;



#endif //AMPLEXUS_AMPLEXUSTYPES_H

//
// Created by jfetko on 6/20/24.
//
#include "Amplexus.h"

void generate_moves(Position pos, TreeNode root){

    uint64_t full_board = OCCUPIED_SQUARES(pos);
    // Pointers to current turn's player and opposition piece locations
    uint64_t p, r, n, b, q, k, o_p, o_r, o_n, o_b, o_q, o_k;
    if(pos.white_turn){
        p = pos.wp, r = pos.wr, n=pos.wn, b=pos.wb, q=pos.wq, k=pos.wk;
        o_p = pos.bp, o_r = pos.br, o_n=pos.bn, o_b=pos.bb, o_q=pos.bq, o_k=pos.bk;
    } else {
        uint64_t rev_bitboards[] = {pos.wp,  pos.wr, pos.wn, pos.wb, pos.wq,pos.wk,
                                    pos.bp, pos.br, pos.bn, pos.bb, pos.bq, pos.bk};
        for(int i = 0; i< 12; i++) rev_bitboards[i] = reverse_bits(rev_bitboards[i]);
        o_p = rev_bitboards[0], o_r = rev_bitboards[1], o_n=rev_bitboards[2], o_b=rev_bitboards[3], o_q=rev_bitboards[4], o_k=rev_bitboards[5];
        p = rev_bitboards[6], r = rev_bitboards[7], n=rev_bitboards[8], b=rev_bitboards[9], q=rev_bitboards[10], k=rev_bitboards[11];
        full_board = reverse_bits(full_board);
    }

    // Check if king is in check

    // Pawn moves

    // Rook moves


    // Knight moves

    // Bishop moves

    // Queen moves

    //
}
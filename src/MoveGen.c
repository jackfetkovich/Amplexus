//
// Created by jfetko on 6/20/24.
//
#include "MoveGen.h"

#define HFILE (uint64_t) 0x8080808080808080
#define AFILE (uint64_t) 0x0101010101010101

void generate_moves(Position pos, TreeNode *root){

    uint64_t full_board = OCCUPIED_SQUARES(pos);
    // Pointers to current turn's player and opposition piece locations
    uint64_t p, r, n, b, q, k, o_p, o_r, o_n, o_b, o_q, o_k;
    if(pos.white_turn){
        p = pos.wp, r = pos.wr, n=pos.wn, b=pos.wb, q=pos.wq, k=pos.wk;
        o_p = pos.bp, o_r = pos.br, o_n=pos.bn, o_b=pos.bb, o_q=pos.bq, o_k=pos.bk;
    } else {
        uint64_t rev_bitboards[] = {pos.wp,  pos.wr, pos.wn, pos.wb, pos.wq,pos.wk,
                                    pos.bp, pos.br, pos.bn, pos.bb, pos.bq, pos.bk};
//        for(int i = 0; i< 12; i++) rev_bitboards[i] = reverse_bits(rev_bitboards[i]);
//        full_board = reverse_bits(full_board);
        o_p = rev_bitboards[0], o_r = rev_bitboards[1], o_n=rev_bitboards[2], o_b=rev_bitboards[3], o_q=rev_bitboards[4], o_k=rev_bitboards[5];
        p = rev_bitboards[6], r = rev_bitboards[7], n=rev_bitboards[8], b=rev_bitboards[9], q=rev_bitboards[10], k=rev_bitboards[11];
    }
    uint64_t my_pieces = p | r | n | b | q | k;
    uint64_t op_pieces = o_p | o_r | o_n | o_b | o_q | o_k;

    // Check if king is in check

    // Pawn moves

    // Moves for rook, queen, and bishop
    uint64_t rqb = r | q | b;
    uint64_t mask = (uint64_t) 1;
    while(mask){
        if(mask & rqb){
            int piece_type;
            if(mask & q) piece_type = QUEEN;
            if(mask & r) piece_type = ROOK;
            if(mask & b) piece_type = BISHOP;

            uint64_t og_piece = mask; // starting position of piece
            uint64_t moving_piece;

            // Up and down
            for(int i = 0; i < 2; i++) {
                moving_piece = mask; // Isolate found piece on bitboard
                while ((piece_type == QUEEN || piece_type == ROOK) && moving_piece) {
                    switch(i){
                        case 0:
                            moving_piece <<=8; // moves going up
                            break;
                        case 1:
                            moving_piece >>=8; // moves going down
                            break;
                    }
                    if (moving_piece && !(moving_piece & full_board)) { // if new square is empty
                        Move new_move;
                        new_move = generate_move_string(pos.white_turn, __builtin_ctzll(og_piece), __builtin_ctzll(moving_piece), piece_type, 0, 0, 0, 0,
                                                        0);
                        add_move(root, new_move);
                    } else if (moving_piece & op_pieces) {// capturing an enemy piece
                        Move new_move;
                        new_move = generate_move_string(pos.white_turn, __builtin_ctzll(og_piece), __builtin_ctzll(moving_piece), piece_type, 1, 0, 0, 0,
                                                        0);
                        add_move(root, new_move);
                        break;
                    } else break; // Can't land on my own piece
                }
            }

            // Left
            moving_piece = og_piece;
            while((piece_type == QUEEN || piece_type == ROOK) && moving_piece){
                moving_piece >>= 1;
                moving_piece &= ~HFILE;
                if (moving_piece && !(moving_piece & full_board)) { // if new square is empty
                    Move new_move;
                    new_move = generate_move_string(pos.white_turn, __builtin_ctzll(og_piece), __builtin_ctzll(moving_piece), piece_type, 0, 0, 0, 0,
                                                    0);
                    add_move(root, new_move);
                } else if (moving_piece & op_pieces) {// capturing an enemy piece
                    Move new_move;
                    new_move = generate_move_string(pos.white_turn, __builtin_ctzll(og_piece), __builtin_ctzll(moving_piece), piece_type, 1, 0, 0, 0,
                                                    0);
                    add_move(root, new_move);
                    break;
                } else break; // Can't land on my own piece or on H file
            }

            // Right
            moving_piece = og_piece;
            while((piece_type == QUEEN || piece_type == ROOK) && moving_piece){
                moving_piece <<= 1;
                moving_piece &= ~AFILE;
                if (moving_piece && !(moving_piece & full_board)) { // if new square is empty
                    Move new_move;
                    new_move = generate_move_string(pos.white_turn, __builtin_ctzll(og_piece), __builtin_ctzll(moving_piece), piece_type, 0, 0, 0, 0,
                                                    0);
                    add_move(root, new_move);
                } else if (moving_piece & op_pieces) {// capturing an enemy piece
                    Move new_move;
                    new_move = generate_move_string(pos.white_turn, __builtin_ctzll(og_piece), __builtin_ctzll(moving_piece), piece_type, 1, 0, 0, 0,
                                                    0);
                    add_move(root, new_move);
                    break;
                } else break; // Can't land on my own piece or on H file
            }

        }

        mask <<= 1;
    }

}
//
// Created by jfetko on 7/27/24.
//

#include "DevUtilities.h"
#include<string.h>
#include<stdio.h>
#include <malloc.h>
#include "AmplexusTypes.h"


void reverse_str(char * str){
    int len = strlen(str);
    char copy[len -1];
    strcpy(copy, str);
    for(int i = len -1; i >= 0; i--){
        str[i] = copy[len-1-i];
    }
}

Position* position_from_fen(char* fen){
    Position* pos = malloc(sizeof(Position));

    char fen_mut[100];
    char* rank;
    char* delim = " /";
    int square = 63;
    int read_fields_after_pieces = 0;

    strcpy(fen_mut, fen);
    rank = strtok(fen_mut, delim);
    while(rank != NULL){
        // Reading piece positions
        if(square >= 0){
            reverse_str(rank);
            int len = (int)strlen(rank);
            for(int i = 0; i < len; i++){
                char single = rank[i];
                // Check if entry is a space number
                if(single >= '1' && single <= '8'){
                    int num_empty_square = single - '0';
                    square -= num_empty_square;
                } else {
                    uint64_t * bb;
                    switch(single){
                        case 'r':
                            bb = &(pos->br);
                            break;
                        case 'b':
                            bb = &(pos->bb);
                            break;
                        case 'n':
                            bb = &(pos->bn);
                            break;
                        case 'k':
                            bb = &(pos->bk);
                            break;
                        case 'q':
                            bb = &(pos->bq);
                            break;
                        case 'p':
                            bb = &(pos->bp);
                            break;
                        case 'R':
                            bb = &(pos->wr);
                            break;
                        case 'B':
                            bb = &(pos->wb);
                            break;
                        case 'N':
                            bb = &(pos->wn);
                            break;
                        case 'K':
                            bb = &(pos->wk);
                            break;
                        case 'Q':
                            bb = &(pos->wq);
                            break;
                        case 'P':
                            bb = &(pos->wp);
                            break;
                        default:
                            bb=NULL;
                            printf("SOMETHING WRONG IN FEN PARSING!!!!!\n");

                    }
                    *bb |= ((uint64_t)1) << square;
                    square--;
                }
            }
        // Reading information after piece positions
        } else if(read_fields_after_pieces <= 4){
            switch (read_fields_after_pieces) {

                // White or black turn
                case 0:
                    if(rank[0] == 'w') {
                        pos->white_turn = 1;
                    } else {
                        pos->white_turn = 0;
                    }
                    break;

                // Castling rights
                case 1: {
                    int len = (int)strlen(rank);
                    for(int i = 0; i < len; i++){
                        char character = rank[i];
                        switch (character) {
                            case '-':
                                pos->w_k_castle_allowed = 0;
                                pos->w_q_castle_allowed = 0;
                                pos->b_k_castle_allowed = 0;
                                pos->b_q_castle_allowed = 0;
                                break;
                            case 'K':
                                pos->w_k_castle_allowed = 1;
                                break;
                            case 'Q':
                                pos->w_q_castle_allowed = 1;
                                break;
                            case 'k':
                                pos->b_k_castle_allowed = 1;
                                break;
                            case 'q':
                                pos->b_q_castle_allowed = 1;
                                break;
                            default:
                                printf("CASTLING RIGHTS FEN ISSUE!!!\n");
                        }
                    }
                    break;
                }

                // En passant target
                case 2: {
                    int target_square = 0;
                    int len = (int) strlen(rank);
                    for(int i = 0; i < len; i++){
                        char character = rank[i];
                        switch (character) {
                            case '-':
                                break;
                            default: {
                                if(character >= 'a' && character <= 'h'){
                                    target_square += character - 'a';
                                } else if(character >= '1' && character <= '8'){
                                    target_square += 8 * (character - '1');
                                }
                            }
                        }
                    }
                    if(target_square == 0){
                        pos->en_passant_target = -1;
                    } else {
                        pos->en_passant_target = target_square;
                    }
                }

                // Half move clock
                case 3: {
                    int total = 0;
                    int len = (int) strlen(rank);
                    for(int i = 0; i < len; i++){
                        char character = rank[i];
                        total *= 10;
                        total += character - '0';
                    }
                    pos->half_moves = total;
                }

                // Full move clock
                case 4: {
                    int total = 0;
                    int len = (int) strlen(rank);
                    for(int i = 0; i < len; i++){
                        char character = rank[i];
                        total *= 10;
                        total += character - '0';
                    }
                    pos->full_moves = total;
                }
            }
            read_fields_after_pieces++;
        }

        rank = strtok(NULL, delim);
    }
    return pos;
}
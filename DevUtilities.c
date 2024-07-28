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

    strcpy(fen_mut, fen);
    rank = strtok(fen_mut, delim);
    while(rank != NULL){
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
        }
        rank = strtok(NULL, delim);
    }
    return pos;
}
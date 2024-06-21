//
// Created by jfetko on 6/20/24.
//

#ifndef AMPLEXUS_LINKEDLIST_H
#include "AmplexusTypes.h"

typedef struct node_struct{
    Move move;
    double eval;
    struct node_struct *next;
} node;

typedef struct {
    struct node_struct *head;
} ChildMoveList;

void add_move(ChildMoveList *list, Move move);

#define AMPLEXUS_LINKEDLIST_H

#endif //AMPLEXUS_LINKEDLIST_H

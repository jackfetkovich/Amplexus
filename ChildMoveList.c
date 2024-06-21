//
// Created by jfetko on 6/20/24.
//
#include <stdlib.h>
#include "ChildMoveList.h"

void add_move(ChildMoveList *list, Move move) {
    node *new_node = malloc(sizeof(node));
    new_node->move = move;
    new_node->next = NULL;

    node *p = list->head;
    if(p == NULL) {
        list->head = new_node;
        return;
    }
    while(p && p->next != NULL){
        p = p->next;
    }
    p->next = new_node;
}

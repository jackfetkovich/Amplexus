//
// Created by jfetko on 6/20/24.
//
#include <stdlib.h>
#include "DataStructures.h"

void add_move(TreeNode *parent, Move move) {

    TreeNode *node = malloc(sizeof(TreeNode));
    node->parent = parent;
    node->move = move;
    node->num_children = 0;
    node->child_moves = malloc(sizeof (MoveNodeList));


    ListItem *list_item = malloc(sizeof(ListItem));
    list_item->move_node = node;
    list_item->next = NULL;
    ListItem *p = parent->child_moves->head;

    (parent->num_children)++;
    if(p == NULL) {
        parent->child_moves->head = list_item;
        return;
    }
    while(p && p->next != NULL){
        p = p->next;
    }
    p->next = list_item;

}

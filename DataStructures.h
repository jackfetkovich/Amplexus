//
// Created by jfetko on 6/20/24.
//

#ifndef AMPLEXUS_LINKEDLIST_H
#include "AmplexusTypes.h"

/*
 * ListItem, MoveNodeList, Tree, TreeNode Explanation
 * A Tree is composed of TreeNodes. In each node, there is a pointer to its parent node.
 * A TreeNode also includes a Move and the evaluation associated with it.
 * Finally, a TreeNode contains a MoveNodeList, a linked list composed of pointers to ListItems, wrappers around a
 * MoveNode with a pointer to the next sibling node.
 * */

// List used for child nodes
typedef struct list_item_struct{
    struct tree_node_struct *move_node;
    struct list_item_struct *next;
} ListItem;

typedef struct {
    struct list_item_struct *head;
} MoveNodeList;

// Tree node, which contains child node list
typedef struct tree_node_struct {
    struct tree_node_struct *parent;
    Move move;
    int num_children;
    MoveNodeList *child_moves;
    double eval;
} TreeNode;

typedef struct tree_struct {
    struct tree_node_struct *root;
} Tree;

void add_move(TreeNode *parent, Move move);



#define AMPLEXUS_LINKEDLIST_H

#endif //AMPLEXUS_LINKEDLIST_H

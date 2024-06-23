#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "AmplexusTypes.h"
#include "DataStructures.h"

int main() {
    Tree tree;
    TreeNode root;
    Move root_move = 0;
    MoveNodeList *children = malloc(sizeof (MoveNodeList));
    children->head = NULL;

    root.move = root_move;
    root.parent = NULL;
    root.num_children = 0;
    root.child_moves = children;
    tree.root = &root;

    ///////////////
    add_move(&root, 2);
    add_move(&root, 3);
    add_move(&root, 4);

    int k = 0;
    ListItem *p = root.child_moves->head;
    while(p){
        add_move(p->move_node, k);
        k++;
        p=p->next;
    }

    printf("%d", root.num_children);
    free(children);

}

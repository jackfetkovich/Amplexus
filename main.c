#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "AmplexusTypes.h"
#include "DataStructures.h"
#include "Utilities.h"


int main() {
//    Tree tree;
//    TreeNode root;
//    Move root_move = 0;
//    MoveNodeList *children = malloc(sizeof (MoveNodeList));
//    children->head = NULL;
//
//    root.move = root_move;
//    root.parent = NULL;
//    root.num_children = 0;
//    root.child_moves = children;
//    tree.root = &root;
//
//    ///////////////
//    add_move(&root, 2);
//    add_move(&root, 3);
//    add_move(&root, 4);
//
//    int k = 0;
//    ListItem *p = root.child_moves->head;
//    while(p){
//        add_move(p->move_node, k);
//        k++;
//        p=p->next;
//    }
//
//    printf("%d", root.num_children);
//    free(children);

//***********************************************

//    int wp_ar[] = {8,9,10,11,12,13,14,15};
//    int wr_ar[] = {0, 7};
//    int wn_ar[] = {1, 6};
//    int wb_ar[] = {2, 5};
//    int wq_ar[] = {3};
//    int wk_ar[] = {4};
//
//    int wp_bb = gen_bitboard(wp_ar, 8);
//    int wr_bb = gen_bitboard(wr_ar, 2);
//    int wn_bb = gen_bitboard(wn_ar, 2);
//    int wb_bb = gen_bitboard(wb_ar, 2);
//    int wq_bb = gen_bitboard(wq_ar, 2);
//    int wk_bb = gen_bitboard(wk_ar, 2);
//
//    Position pos;
//    pos.wp = wp_bb;
//    pos.wr = wr_bb;
//    pos.wn = wn_bb;
//    pos.wb = wb_bb;
//    pos.wq = wq_bb;
//    pos.wk = wk_bb;
//    pos.bp = 0;
//    pos.br = 0;
//    pos.bn = 0;
//    pos.bb = 0;
//    pos.bq = 0;
//    pos.bk = 0;
//
//    uint64_t all_white_pieces = OCCUPIED_SQUARES(pos);
//
//    printf("%lu", all_white_pieces);


//************************************************

//uint64_t rev = reverse_bits((uint64_t) 2);
//printf("%lu", rev);
    Move m;
    m = generate_move_string(1, 0,0,0,0,0,0,0,0);
    printf("%u", m);

}

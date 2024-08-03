#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "AmplexusTypes.h"
#include "DataStructures.h"
#include "DevUtilities.h"
#include "MoveGen.h"


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

//    char fen_str[] = "1r2n2q/3k1b2/3p2p1/1pp2p2/8/PP1PR1P1/1B3K2/R1QN4 b - - 0 1";
//    char fen_str[] = "r1k1b2r/1p4q1/2pp4/4pP2/2PPP1P1/PP6/8/R1Q1K2R w KQkq e6 0 1";
//    Position * pos = position_from_fen(fen_str);
//    Position repos = *pos;

// Testing basic move generation

    char fen_str[] = "8/8/3B4/2BRB3/3B4/8/8/8 w - - 0 1";
    Position *pos = position_from_fen(fen_str);

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

    generate_moves(*pos, tree.root);

//// Test Move String Generator
//    int white = 1;
//    int start_pos = 0;
//    int end_pos = 16;
//    int piece_type = ROOK;
//    int capture = 0;
//    int en_pass = 0;
//    int promo = 0;
//    int k_c = 0;
//    int q_c = 0;
//    uint32_t expected = 0x80850000;
//
//    uint32_t move_str = generate_move_string(white, start_pos, end_pos, piece_type, capture, en_pass, promo, k_c, q_c);
//    printf("Expected: %u\n", expected);
//    printf("Actual: %u\n", move_str);
//    printf("Pass: %d\n", expected == move_str);
//
}
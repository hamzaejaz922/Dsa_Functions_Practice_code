#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

struct node {
    int info;
    node *lchild;
    node *rchild;
};

struct bst {
    node *root = NULL;
    void find(int item, node **par, node **loc);
    void insert(int item);
    void del(int item);
    void case_a(node *par, node *loc);
    void case_b(node *par, node *loc);
    void case_c(node *par, node *loc);
    void inorder(node *ptr);
    void preorder(node *ptr);
    void postorder(node *ptr);
    void search(node *ptr, int item);
    void display_level(node *ptr, int level);
    void display_left_nodes(node *ptr);
    void display_right_nodes(node *ptr);
    void largest_at_level(node *ptr, int level);
    void findMaxAtLevel(node *ptr, int level, int &maxVal);
    void delete_terminal(node *ptr);
    void display_terminal(node *ptr);
    void inorder_succ_pred(node *ptr, int item);
    void insert_reverse(int item);
    void inorder_reverse(node *ptr);
    void nrpreorder();
    void nrinorder();
    void nrpostorder();
    void printReverse(node *from, node *to);
    void reversePath(node *start, node *end);
    
};

#endif
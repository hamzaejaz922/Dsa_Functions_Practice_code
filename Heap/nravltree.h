#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

struct node
{
    int info;
    int balance;
    node *lchild;
    node *rchild;
};

struct student
{
    int roll;
    string name;
    float marks;

    int balance;
    student *lchild;
    student *rchild;
};

struct bst
{
    node *root;
    student *sroot;

    bst()
    {
        root = NULL;
        sroot = NULL;
    }

    node* insertAVL(node *pptr, int info, bool &ht_inc);
    node* deleteAVL(node *r, int key, bool &ht_dec);

    void inorder(node *ptr);
    void preorder(node *ptr);
    void postorder(node *ptr);

    void search(node *ptr, int item);

    void nrpreorder();
    void nrinorder();
    void nrpostorder();

    student* insert_student(student *pptr,
                            int roll,
                            string name,
                            float marks,
                            bool &ht_inc);

    void search_student(int roll);

    // NEW FUNCTIONS
    void node_type_nonrecursive();
    void root_right_left();
    void right_root_left();
    void children_sum();
    void balance_factor(int item);
    int height(node *ptr);
};

#endif
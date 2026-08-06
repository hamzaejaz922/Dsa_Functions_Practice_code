#ifndef LINK_LIST
#define LINK_LIST
#include <cstdlib>
#include <iostream>
using namespace std;

struct node
{
    int info;
    node *left;
    node *right;
    int rollNo;
    string name;
    float gpa;
};

struct func
{
    node *start = NULL;

    void insert(int data);
    void deleteNode(int data);

    void preorder_NR();
    void inorder_NR();
    void postorder_NR();

    void insert_reversed(int data);
    void display_reversed();

    void insert_student(int roll, string sname, float sgpa);
    void search_student(int roll);

    void display_leaves();
    void delete_leaves();

    void inorder_successor(int data);
    void inorder_predecessor(int data);

    void display_level(int level);

    void display_left_nodes();

    void largest_at_level(int level);

    void display_right_nodes();

    void display();
};

void return_menu();

#endif

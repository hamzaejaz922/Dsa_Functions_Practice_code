#include <iostream>
#include "linked_list.h"
using namespace std;

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node
{
    int info;
    node *point;
};

struct func
{
    node *start = NULL;

    void add_at_beg(int data);
    void add_at_middle(int data, int pos);
    void add_at_end(int data);

    void delete_at_beg();
    void delete_at_middle(int pos);
    void delete_at_end();
    void delete_by_value(int data);

    void display();
    void count();
    void reverse();
    void search(int data);
    void largest();
    void smallest();
    void average();
    void even_odd_count();
    void occurrence(int data);
};

#endif
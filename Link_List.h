#ifndef LINK_LIST
#define LINK_LIST
#include <cstdlib>
#include <iostream>

using namespace std;
struct node
{
    int info;
    node *next;
};
struct func
{
    node *start = NULL;
    void add_at_beg(int data);
    void add_after(int data, int pos);
    void add_at_end(int data);
    void del_from_start();
    void del_after(int data);
    void del_at_end();
    void del_after_position(int pos);
    void display();
    void count();
    void rev();
    void search(int data);
    void concat(node *str1, node *str2);
    void split(node *&str1, node *&str2, int cnt);
    void maximum();
    void minimum();
    void total();
    void evenodd(node *&str1, node *&str2);
    void occurrence(int data, node *&str);
};

void return_menu();

#endif
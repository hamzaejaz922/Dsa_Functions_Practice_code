#ifndef LINK_LIST
#define LINK_LIST

#include <cstdlib>
#include <iostream>
#include <cctype>
using namespace std;

#define MAX 5   

struct node {
    char info;      
    node* point;
};

struct func {
    node* dq = NULL;
    int count = 0;   

    void reverse_queue(node*& front);
    void sort_dequeue_desc(node*& front);

    void insert_front(node*& front, char data);
    void insert_rear(node*& front, char data);
    void delete_front(node*& front);
    void delete_rear(node*& front);

    bool identical_queues(node* q1, node* q2);

    bool is_palindrome_deque(node* front);

    void call_center_simulation(node* queues[], int qCount);

    void display_queue(node* front);
};

#endif
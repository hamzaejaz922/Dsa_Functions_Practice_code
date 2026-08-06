#ifndef LINK_LIST
#define LINK_LIST

#include <cstdlib>
#include <iostream>
using namespace std;

struct node {
    int info;
    node* point;
};

struct func {
    // Queue/Deque front pointers
    node* dq = NULL;

    // Q1: Reverse queue
    void reverse_queue(node*& front);

    // Q2: Sort dequeue descending
    void sort_dequeue_desc(node*& front);

    // Q3: Circular dequeue insert/delete
    void insert_front(node*& front, int data);
    void insert_rear(node*& front, int data);
    void delete_front(node*& front);
    void delete_rear(node*& front);

    // Q4: Check if two queues are identical
    bool identical_queues(node* q1, node* q2);

    // Q5: Palindrome check ignoring non-alphanumeric
    bool is_palindrome_deque(node* front);

    // Q6: Call center simulation using multiple queues
    void call_center_simulation(node* queues[], int qCount);

    // Utility
    void display_queue(node* front);
};

#endif
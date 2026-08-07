#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};


struct LinkedList {
    Node* head;
    Node* tail;
    LinkedList();              
    void insertAtStart(int value);  
    void insertAtEnd(int value);  
    void deleteAtStart();  
    void deleteFromEnd();  
    int peekFront();  
    int peekRear();  
    void insertAtPosition(int value, int position);  
    void deleteAtPosition(int position);  
    bool search(int value);
    int countNodes();
    void reverse();  
    void concatenate(LinkedList& otherList);
    void split(int position, LinkedList& secondList);  
    int findLargest();
    int findSmallest();
    int getSum();
    double getAverage();
    void display();  
    int findThirdLargest();      
};

#endif
#define MAX 10
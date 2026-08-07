#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data=value;
        next=NULL;
    }
};

struct LinkedList{
    Node* head;

    LinkedList();

    void insertAtEnd(int value);
    void deleteAtStart();
    int peek();

    void insertAtStart(int value);
    void insertAtPosition(int value,int position);
    void deleteFromEnd();
    void deleteAtPosition(int position);

    bool search(int value);
    int countNodes();
    void reverse();
    void concatenate(LinkedList& otherList);
    void split(int position,LinkedList& secondList);

    int findLargest();
    int findSmallest();
    int getSum();
    double getAverage();
    void display();
    int findThirdLargest();
};

#endif
#define MAX 10
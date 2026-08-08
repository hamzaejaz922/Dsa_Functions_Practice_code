#include <iostream>
#include "linked_list.h"
using namespace std;

// Create
void func::create_list(int data){
    node *temp = new node();
    temp->info = data;
    temp->point = NULL;

    if(start == NULL)
        start = temp;
    else{
        node *q = start;
        while(q->point != NULL)
            q = q->point;
        q->point = temp;
    }
}

// INSERT FUNCTIONS

void func::add_at_beg(int data){
    node *temp = new node();
    temp->info = data;
    temp->point = start;
    start = temp;
}

void func::add_at_end(int data){
    node *temp = new node();
    temp->info = data;
    temp->point = NULL;

    if(start == NULL){
        start = temp;
        return;
    }

    node *q = start;
    while(q->point != NULL)
        q = q->point;

    q->point = temp;
}

void func::add_at_middle(int data, int pos){
    node *q = start;
    for(int i=1; i<pos-1 && q!=NULL; i++)
        q = q->point;

    if(q == NULL){
        cout<<"Invalid Position\n";
        return;
    }

    node *temp = new node();
    temp->info = data;
    temp->point = q->point;
    q->point = temp;
}

// DELETE FUNCTIONS

void func::delete_at_beg(){
    if(start == NULL) return;
    node *temp = start;
    start = start->point;
    delete temp;
}

void func::delete_at_end(){
    if(start == NULL) return;

    if(start->point == NULL){
        delete start;
        start = NULL;
        return;
    }

    node *q = start;
    while(q->point->point != NULL)
        q = q->point;

    delete q->point;
    q->point = NULL;
}

void func::delete_at_middle(int pos){
    if(start == NULL) return;

    node *q = start;
    for(int i=1; i<pos-1 && q->point!=NULL; i++)
        q = q->point;

    node *temp = q->point;
    q->point = temp->point;
    delete temp;
}

void func::delete_by_value(int data){
    if(start == NULL) return;

    if(start->info == data){
        delete_at_beg();
        return;
    }

    node *q = start;
    while(q->point != NULL && q->point->info != data)
        q = q->point;

    if(q->point == NULL){
        cout<<"Not Found\n";
        return;
    }

    node *temp = q->point;
    q->point = temp->point;
    delete temp;
}

// DISPLAY
void func::display(){
    node *q = start;
    while(q != NULL){
        cout<<q->info<<" -> ";
        q = q->point;
    }
    cout<<"NULL\n";
}

// COUNT
void func::count(){
    int cnt=0;
    node *q=start;
    while(q!=NULL){
        cnt++;
        q=q->point;
    }
    cout<<"Total nodes: "<<cnt<<endl;
}

// REVERSE
void func::reverse(){
    node *prev=NULL, *curr=start, *next=NULL;

    while(curr!=NULL){
        next=curr->point;
        curr->point=prev;
        prev=curr;
        curr=next;
    }
    start=prev;
}

// SEARCH
void func::search(int data){
    node *q=start;
    int pos=1;
    while(q!=NULL){
        if(q->info==data){
            cout<<"Found at position "<<pos<<endl;
            return;
        }
        q=q->point;
        pos++;
    }
    cout<<"Not Found\n";
}

// LARGEST
void func::largest(){
    if(start==NULL) return;
    int max=start->info;
    node *q=start;
    while(q!=NULL){
        if(q->info>max) max=q->info;
        q=q->point;
    }
    cout<<"Largest: "<<max<<endl;
}

// SMALLEST
void func::smallest(){
    if(start==NULL) return;
    int min=start->info;
    node *q=start;
    while(q!=NULL){
        if(q->info<min) min=q->info;
        q=q->point;
    }
    cout<<"Smallest: "<<min<<endl;
}

// AVERAGE
void func::average(){
    int sum=0,count=0;
    node *q=start;
    while(q!=NULL){
        sum+=q->info;
        count++;
        q=q->point;
    }
    cout<<"Average: "<<(float)sum/count<<endl;
}

// EVEN ODD COUNT
void func::even_odd_count(){
    int even=0, odd=0;
    node *q=start;
    while(q!=NULL){
        if(q->info%2==0) even++;
        else odd++;
        q=q->point;
    }
    cout<<"Even: "<<even<<" Odd: "<<odd<<endl;
}

// OCCURRENCE
void func::occurrence(int data){
    int cnt=0;
    node *q=start;
    while(q!=NULL){
        if(q->info==data) cnt++;
        q=q->point;
    }
    cout<<"Occurrence of "<<data<<" : "<<cnt<<endl;
}
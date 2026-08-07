#include "linkedlist3.h"

LinkedList::LinkedList() {
    head=NULL;
}

void LinkedList::insertAtEnd(int value) {
    Node* newNode=new Node(value);

    if(head==NULL){
        head=newNode;
        newNode->next=head;
        cout<<"Enqueued "<<value<<" into queue.\n";
        return;
    }

    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }

    temp->next=newNode;
    newNode->next=head;
    cout<<"Enqueued "<<value<<" into queue.\n";
}

void LinkedList::deleteAtStart() {
    if(head==NULL){
        cout<<"Queue is empty! Underflow\n";
        return;
    }

    if(head->next==head){
        cout<<"Dequeued "<<head->data<<" from queue.\n";
        delete head;
        head=NULL;
        return;
    }

    Node* temp=head;
    Node* last=head;

    while(last->next!=head){
        last=last->next;
    }

    cout<<"Dequeued "<<head->data<<" from queue.\n";
    head=head->next;
    last->next=head;
    delete temp;
}

int LinkedList::peek() {
    if(head==NULL){
        cout<<"Queue is empty!\n";
        return -1;
    }
    return head->data;
}

void LinkedList::insertAtStart(int value) {
    cout<<"Not allowed in queue! Use insertAtEnd (enqueue) instead.\n";
}

void LinkedList::insertAtPosition(int value,int position) {
    cout<<"Not allowed in queue! Use insertAtEnd (enqueue) instead.\n";
}

void LinkedList::deleteFromEnd() {
    cout<<"Not allowed in queue! Use deleteAtStart (dequeue) instead.\n";
}

void LinkedList::deleteAtPosition(int position) {
    cout<<"Not allowed in queue! Use deleteAtStart (dequeue) instead.\n";
}

bool LinkedList::search(int value) {
    if(head==NULL) return false;

    Node* temp=head;

    do{
        if(temp->data==value){
            return true;
        }
        temp=temp->next;
    }while(temp!=head);

    return false;
}

int LinkedList::countNodes() {
    if(head==NULL) return 0;

    int count=0;
    Node* temp=head;

    do{
        count++;
        temp=temp->next;
    }while(temp!=head);

    return count;
}

void LinkedList::reverse() {
    cout<<"Operation not allowed in queue!\n";
}

void LinkedList::display() {
    if(head==NULL){
        cout<<"Queue is empty!\n";
        return;
    }

    Node* temp=head;
    cout<<"Queue (Front to Rear): ";

    do{
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }while(temp!=head);

    cout<<"HEAD"<<endl;
}

void LinkedList::concatenate(LinkedList& otherList) {
    if(head==NULL){
        head=otherList.head;
        cout<<"Queue concatenated successfully.\n";
        return;
    }

    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }

    Node* temp2=otherList.head;
    while(temp2->next!=otherList.head){
        temp2=temp2->next;
    }

    temp->next=otherList.head;
    temp2->next=head;
    cout<<"Queue concatenated successfully.\n";
}

void LinkedList::split(int position,LinkedList& secondList) {
    cout<<"Not allowed in queue! FIFO violation\n";
}

int LinkedList::findLargest() {
    if(head==NULL){
        cout<<"Queue is empty!\n";
        return -1;
    }

    int largest=head->data;
    Node* temp=head->next;

    while(temp!=head){
        if(temp->data>largest){
            largest=temp->data;
        }
        temp=temp->next;
    }

    return largest;
}

int LinkedList::findThirdLargest() {
    if(countNodes()<3){
        cout<<"Less than 3 elements!\n";
        return -1;
    }

    int first,second,third;
    Node* temp=head;

    first=head->data;
    temp=head->next;

    while(temp!=head){
        if(temp->data>first)
            first=temp->data;
        temp=temp->next;
    }

    second=-1;
    temp=head;

    do{
        if(temp->data<first){
            second=temp->data;
            break;
        }
        temp=temp->next;
    }while(temp!=head);

    do{
        if(temp->data>second && temp->data<first)
            second=temp->data;
        temp=temp->next;
    }while(temp!=head);

    third=-1;
    temp=head;

    do{
        if(temp->data<second){
            third=temp->data;
            break;
        }
        temp=temp->next;
    }while(temp!=head);

    do{
        if(temp->data>third && temp->data<second)
            third=temp->data;
        temp=temp->next;
    }while(temp!=head);

    return third;
}

int LinkedList::findSmallest() {
    if(head==NULL){
        cout<<"Queue is empty!\n";
        return -1;
    }

    int smallest=head->data;
    Node* temp=head->next;

    while(temp!=head){
        if(temp->data<smallest){
            smallest=temp->data;
        }
        temp=temp->next;
    }

    return smallest;
}

int LinkedList::getSum() {
    if(head==NULL) return 0;

    int sum=0;
    Node* temp=head;

    do{
        sum+=temp->data;
        temp=temp->next;
    }while(temp!=head);

    return sum;
}

double LinkedList::getAverage() {
    int totalNodes=countNodes();

    if(totalNodes==0)
        return 0;

    int sum=getSum();

    return (double)sum/totalNodes;
}
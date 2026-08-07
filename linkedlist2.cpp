#include "linkedlist2.h"

LinkedList::LinkedList(){
    head=NULL;
}

void LinkedList::insertAtEnd(int value){
    if(countNodes()==MAX){
        cout<<"Overflow"<<endl;
        return;
    }
    Node* newNode=new Node(value);

    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
}

void LinkedList::insertAtStart(int value){
    if(countNodes()==MAX){
        cout<<"Overflow"<<endl;
        return;
    }
    Node* newNode=new Node(value);
    newNode->next=head;
    head=newNode;
}

void LinkedList::insertAtPosition(int value,int position){
    if(countNodes()==MAX){
        cout<<"Overflow"<<endl;
        return;
    }
    if(position<=1){
        insertAtStart(value);
        return;
    }
    Node* temp=head;
    for(int i=1;i<position-1 && temp!=NULL;i++)
        temp=temp->next;
    if(temp==NULL)
        return;
    Node* newNode=new Node(value);
    newNode->next=temp->next;
    temp->next=newNode;
}

void LinkedList::deleteAtStart(){
    if(head==NULL){
        cout<<"Underflow"<<endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
}

void LinkedList::deleteFromEnd(){
    if(head==NULL){
        cout<<"Underflow"<<endl;
        return;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }
    Node* temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;

    delete temp->next;
    temp->next=NULL;
}

void LinkedList::deleteAtPosition(int position){
    if(head==NULL){
        cout<<"Underflow"<<endl;
        return;
}
    if(position==1){
        deleteAtStart();
        return;
    }
    Node* temp=head;
    for(int i=1;i<position-1 && temp->next!=NULL;i++)
        temp=temp->next;

    if(temp->next==NULL)
        return;
    Node* del=temp->next;
    temp->next=del->next;
    delete del;
}

int LinkedList::peek(){
    if(head==NULL)
        return -1;
    return head->data;
}

bool LinkedList::search(int value){
    Node* temp=head;

    while(temp!=NULL){
        if(temp->data==value)
            return true;
        temp=temp->next;
    }
    return false;
}

int LinkedList::countNodes(){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void LinkedList::reverse(){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

void LinkedList::display(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void LinkedList::concatenate(LinkedList& otherList){
    if(head==NULL){
        head=otherList.head;
        return;
    }

    Node* temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=otherList.head;
}

void LinkedList::split(int position,LinkedList& secondList){
    if(head==NULL)
        return;

    Node* temp=head;

    for(int i=1;i<position && temp!=NULL;i++)
        temp=temp->next;

    if(temp==NULL)
        return;

    secondList.head=temp->next;
    temp->next=NULL;
}

int LinkedList::findLargest(){
    if(head==NULL)
        return -1;

    int largest=head->data;
    Node* temp=head->next;

    while(temp!=NULL){
        if(temp->data>largest)
            largest=temp->data;

        temp=temp->next;
    }

    return largest;
}

int LinkedList::findSmallest(){
    if(head==NULL)
        return -1;

    int smallest=head->data;
    Node* temp=head->next;

    while(temp!=NULL){
        if(temp->data<smallest)
            smallest=temp->data;

        temp=temp->next;
    }

    return smallest;
}

int LinkedList::getSum(){
    int sum=0;
    Node* temp=head;

    while(temp!=NULL){
        sum+=temp->data;
        temp=temp->next;
    }

    return sum;
}

double LinkedList::getAverage(){
    int total=countNodes();

    if(total==0)
        return 0;

    return (double)getSum()/total;
}

int LinkedList::findThirdLargest(){
    if(countNodes()<3)
        return -1;

    int first=-100000,second=-100000,third=-100000;

    Node* temp=head;

    while(temp!=NULL){
        if(temp->data>first){
            third=second;
            second=first;
            first=temp->data;
        }
        else if(temp->data>second){
            third=second;
            second=temp->data;
        }
        else if(temp->data>third){
            third=temp->data;
        }

        temp=temp->next;
    }

    return third;
}
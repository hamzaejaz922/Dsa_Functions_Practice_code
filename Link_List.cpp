#include <iostream>
#include "Link_List.h"
using namespace std;

void func::add_at_end(int data){
    node *q,*temp;
    temp=new node();
    temp->info=data;
    temp->point=NULL;
    if(start==NULL){start=temp;}
    else{
        q=start;
        while(q->point!=NULL) q=q->point;
        q->point=temp;
    }
}

void func::add_at_beg(int data){
    node *temp=new node();
    temp->info=data;
    temp->point=start;
    start=temp;
}

void func::add_after(int data,int pos){
    node *temp,*q;
    int i;
    q=start;
    for(i=0;i<pos-1;i++){
        q=q->point;
        if(q==NULL){cout<<"less than:"<<pos<<endl;return;}
    }
    temp=new node();
    temp->point=q->point;
    temp->info=data;
    q->point=temp;
}

void func::del_from_start(){
    if(start==NULL) return;
    node *temp=start;
    start=start->point;
    delete temp;
}

void func::del_after_position(){
int pos;
cout<<"Enter the position after which you want to delete: ";
cin>>pos;
if(start==NULL){
cout<<"List is empty\n";
return;
}
node *q=start;
int count=1;
while(q!=NULL && count<pos){
q=q->point;
count++;
}
if(q==NULL || q->point==NULL){
cout<<"Invalid position or no node exists after this position\n";
return;
}
node *temp=q->point;
q->point=temp->point;
delete temp;
cout<<"Node deleted after position "<<pos<<endl;
}

void func::del_at_end(){
    node *q;
    if(start==NULL) return;
    if(start->point==NULL){delete start;start=NULL;return;}
    q=start;
    while(q->point->point!=NULL) q=q->point;
    delete q->point;
    q->point=NULL;
}

void func::display(){
    node *q;
    if(start==NULL){cout<<"list is empty"<<endl;return;}
    q=start;
    cout<<"list is\n";
    while(q!=NULL){
        cout<<q->info<<endl;
        q=q->point;
    }
    cout<<endl;
}

void func::count(){
    node *q=start;
    int cnt=0;
    while(q!=NULL){q=q->point;cnt++;}
    cout<<"num of elements are:"<<cnt<<endl;
}

void func::rev(){
    if(start==NULL||start->point==NULL){cout<<"Reverse not possible.\n";return;}
    node *p1,*p2,*p3;
    p1=start;
    p2=p1->point;
    p3=p2->point;
    p1->point=NULL;
    p2->point=p1;
    while(p3!=NULL){
        p1=p2;
        p2=p3;
        p3=p3->point;
        p2->point=p1;
    }
    start=p2;
    cout<<"List reversed successfully.\n";
}

void func::search(int data){
    if(start==NULL){cout<<"List is empty.\n";return;}
    node*ptr=start;
    int pos=1;
    while(ptr!=NULL){
        if(ptr->info==data){cout<<"Element "<<data<<" found at position "<<pos<<endl;return;}
        ptr=ptr->point;pos++;
    }
    cout<<"Element not found.\n";
}

void func::concat(node*str1,node*str2){
    node*temp;node*last=NULL;start=NULL;
    temp=str1;
    while(temp!=NULL){
        node*newnode=new node();
        newnode->info=temp->info;
        newnode->point=NULL;
        if(start==NULL) start=last=newnode;
        else{last->point=newnode;last=newnode;}
        temp=temp->point;
    }
    temp=str2;
    while(temp!=NULL){
        node*newnode=new node();
        newnode->info=temp->info;
        newnode->point=NULL;
        if(start==NULL) start=last=newnode;
        else{last->point=newnode;last=newnode;}
        temp=temp->point;
    }
    cout<<"Concatenated list stored.\n";
}

void func::split(node*&str1,node*&str2,int cnt){
    if(start==NULL){cout<<"List empty\n";return;}
    node*temp=start;node*last1=NULL;node*last2=NULL;
    str1=NULL;str2=NULL;
    int mid=cnt/2,i=0;
    while(temp!=NULL){
        node*newnode=new node();
        newnode->info=temp->info;
        newnode->point=NULL;
        if(i<mid){
            if(str1==NULL) str1=last1=newnode;
            else{last1->point=newnode;last1=newnode;}
        }else{
            if(str2==NULL) str2=last2=newnode;
            else{last2->point=newnode;last2=newnode;}
        }
        temp=temp->point;i++;
    }
    cout<<"Split stored in new lists.\n";
}

void func::maximun(){
    if(start==NULL){cout<<"Empity list"<<endl;return;}
    node*temp=start;int max=start->info;
    while(temp!=NULL){if(temp->info>max)max=temp->info;temp=temp->point;}
    cout<<"Maximum value in the list: "<<max<<endl;
}

void func::minimum(){
    if(start==NULL){cout<<"Empity list"<<endl;return;}
    node*temp=start;int min=start->info;
    while(temp!=NULL){if(temp->info<min)min=temp->info;temp=temp->point;}
    cout<<"Smallest value in the list: "<<min<<endl;
}

void func::total(){
    if(start==NULL){cout<<"Empity list"<<endl;return;}
    node*temp=start;int sum=0,cnt=0;
    while(temp!=NULL){sum+=temp->info;temp=temp->point;cnt++;}
    cout<<"Sum of list: "<<sum<<endl;
    cout<<"Average of list: "<<(double)sum/cnt<<endl;
}

void func::evenodd(node*&str1,node*&str2){
    if(start==NULL){cout<<"List empty\n";return;}
    node*temp=start;node*last1=NULL;node*last2=NULL;
    str1=NULL;str2=NULL;
    while(temp!=NULL){
        node*newnode=new node();
        newnode->info=temp->info;
        newnode->point=NULL;
        if(temp->info%2==0){
            if(str1==NULL) str1=last1=newnode;
            else{last1->point=newnode;last1=newnode;}
        }else{
            if(str2==NULL) str2=last2=newnode;
            else{last2->point=newnode;last2=newnode;}
        }
        temp=temp->point;
    }
    cout<<"Even and Odd stored in new lists.\n";
}

void func::occurrence(int data,node*&str){
    node*temp=start;int count=0;
    while(temp!=NULL){if(temp->info==data)count++;temp=temp->point;}
    str=NULL;
    node*newnode=new node();
    newnode->info=count;
    newnode->point=NULL;
    str=newnode;
    cout<<"Occurrence stored in list10.\n";
}

void return_menu(){
    cout<<"\nPress any key and Enter to return to menu...";
    int x;cin>>x;
}
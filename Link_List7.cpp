#include "Link_List7.h"
#include <cctype>

// Utility to display queue/deque
void func::display_queue(node* front) {
    node* temp = front;
    if (!temp) { cout << "Empty\n"; return; }
    while (temp) { cout << temp->info << " "; temp = temp->point; }
    cout << endl;
}

// Q1: Reverse queue
void func::reverse_queue(node*& front) {
    if (!front) return;
    node* prev = NULL;
    node* curr = front;
    node* next = NULL;
    while (curr) {
        next = curr->point;
        curr->point = prev;
        prev = curr;
        curr = next;
    }
    front = prev;
    cout << "Queue reversed.\n";
}

// Q2: Sort dequeue descending
void func::sort_dequeue_desc(node*& front) {
    if (!front) return;
    node* sorted = NULL;
    node* curr = front;
    while (curr) {
        node* next = curr->point;
        if (!sorted || curr->info > sorted->info) {
            curr->point = sorted;
            sorted = curr;
        } else {
            node* temp = sorted;
            while (temp->point && temp->point->info > curr->info)
                temp = temp->point;
            curr->point = temp->point;
            temp->point = curr;
        }
        curr = next;
    }
    front = sorted;
    cout << "Deque sorted in descending order.\n";
}

// Q3: Circular Deque operations
void func::insert_front(node*& front, int data) {
    node* temp = new node();
    temp->info = data;
    temp->point = front;
    front = temp;
}

void func::insert_rear(node*& front, int data) {
    node* temp = new node();
    temp->info = data;
    temp->point = NULL;
    if (!front) front = temp;
    else {
        node* curr = front;
        while (curr->point) curr = curr->point;
        curr->point = temp;
    }
}

void func::delete_front(node*& front) {
    if (!front) { cout << "Empty\n"; return; }
    node* temp = front;
    front = front->point;
    delete temp;
}

void func::delete_rear(node*& front) {
    if (!front) { cout << "Empty\n"; return; }
    if (!front->point) { delete front; front = NULL; return; }
    node* curr = front;
    while (curr->point->point) curr = curr->point;
    delete curr->point;
    curr->point = NULL;
}

// Q4: Check if two queues are identical
bool func::identical_queues(node* q1, node* q2) {
    node* a = q1;
    node* b = q2;
    while (a && b) {
        if (a->info != b->info) return false;
        a = a->point;
        b = b->point;
    }
    return (a == NULL && b == NULL);
}

// Q5: Palindrome ignoring non-alphanumeric
bool func::is_palindrome_deque(node* front) {
    node* stack = NULL;
    node* temp = front;
    while (temp) {
        if (isalnum(temp->info))
            insert_front(stack, tolower(temp->info));
        temp = temp->point;
    }
    temp = front;
    while (temp && stack) {
        if (isalnum(temp->info) && tolower(temp->info) != stack->info)
            return false;
        if (isalnum(temp->info)) delete_front(stack);
        temp = temp->point;
    }
    return true;
}

// Q6: Call center simulation
void func::call_center_simulation(node* queues[], int qCount) {
    for (int i = 0; i < qCount; i++) {
        cout << "Queue " << i+1 << " elements: ";
        display_queue(queues[i]);
    }
    cout << "Simulating serving in priority order...\n";
    for (int i = 0; i < qCount; i++) {
        while (queues[i]) {
            cout << "Serving customer: " << queues[i]->info << " from queue " << i+1 << endl;
            delete_front(queues[i]);
        }
    }
}
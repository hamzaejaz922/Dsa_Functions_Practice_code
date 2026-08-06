#include "Link_List8.h"

void func::display_queue(node* front) {
    if (!front) { cout << "Empty\n"; return; }
    node* temp = front;
    do {
        cout << temp->info << " ";
        temp = temp->point;
    } while (temp != front);
    cout << endl;
}

void func::reverse_queue(node*& front) {
    if (!front) return;
    node* prev = front;
    node* curr = front->point;
    if (!curr) return;
    do {
        node* next = curr->point;
        curr->point = prev;
        prev = curr;
        curr = next;
    } while (prev != front);
    front->point = prev; 
    front = prev;
    cout << "Queue reversed.\n";
}

void func::sort_dequeue_desc(node*& front) {
    if (!front || front->point == front) return;
    node* sorted = NULL;
    node* curr = front;
    node* first = front;
    do {
        node* next = curr->point;
        curr->point = nullptr;

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
    } while (curr != first);

    node* last = sorted;
    while (last->point) last = last->point;
    last->point = sorted;
    front = sorted;

    cout << "Deque sorted in descending order.\n";
}

void func::insert_front(node*& front, char data) {

    if (count == MAX) {
        cout << "OVERFLOW: Queue is full!\n";
        return;
    }

    node* temp = new node();
    temp->info = data;

    if (!front) {
        front = temp;
        temp->point = temp;
    } else {
        node* last = front;
        while (last->point != front) last = last->point;

        temp->point = front;
        last->point = temp;
        front = temp;
    }

    count++;  
}

void func::insert_rear(node*& front, char data) {

    if (count == MAX) {
        cout << "OVERFLOW: Queue is full!\n";
        return;
    }

    node* temp = new node();
    temp->info = data;

    if (!front) {
        front = temp;
        temp->point = temp;
    } else {
        node* last = front;
        while (last->point != front) last = last->point;

        last->point = temp;
        temp->point = front;
    }

    count++;  
}

void func::delete_front(node*& front) {

    if (!front) {
        cout << "UNDERFLOW: Queue is empty!\n";
        return;
    }

    if (front->point == front) {
        delete front;
        front = NULL;
    } else {
        node* last = front;
        while (last->point != front) last = last->point;

        node* temp = front;
        front = front->point;
        last->point = front;
        delete temp;
    }

    count--;  
}

void func::delete_rear(node*& front) {

    if (!front) {
        cout << "UNDERFLOW: Queue is empty!\n";
        return;
    }

    if (front->point == front) {
        delete front;
        front = NULL;
    } else {
        node* curr = front;
        while (curr->point->point != front) curr = curr->point;

        node* temp = curr->point;
        curr->point = front;
        delete temp;
    }

    count--;  
}

bool func::identical_queues(node* q1, node* q2) {
    if (!q1 && !q2) return true;
    if (!q1 || !q2) return false;

    node* a = q1;
    node* b = q2;

    do {
        if (a->info != b->info) return false;
        a = a->point;
        b = b->point;
    } while (a != q1 && b != q2);

    return (a == q1 && b == q2);
}

bool func::is_palindrome_deque(node* front) {
    if (!front) return true;

    node* left = front;
    node* right = front;

    do right = right->point; while (right->point != front);

    while (left != right && left->point != right) {

        while (!isalnum(left->info)) left = left->point;

        while (!isalnum(right->info)) {
            node* temp = front;
            while (temp->point != right) temp = temp->point;
            right = temp;
        }

        if (tolower(left->info) != tolower(right->info))
            return false;

        left = left->point;

        node* temp = front;
        while (temp->point != right) temp = temp->point;
        right = temp;
    }

    return true;
}

void func::call_center_simulation(node* queues[], int qCount) {

    cout << "Serving queues in priority order:\n";

    for (int i = 0; i < qCount; i++) {
        cout << "Queue " << i+1 << ": ";
        if (!queues[i]) cout << "Empty\n";
        else {
            node* first = queues[i];
            node* temp = first;
            do {
                cout << temp->info << " ";
                temp = temp->point;
            } while (temp != first);
            cout << endl;
        }
    }

    for (int i = 0; i < qCount; i++) {
        while (queues[i]) {
            cout << "Serving customer: "
                 << queues[i]->info
                 << " from queue " << i+1 << endl;
            delete_front(queues[i]);
        }
    }
}
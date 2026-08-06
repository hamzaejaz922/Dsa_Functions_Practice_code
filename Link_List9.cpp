#include <iostream>
#include <stack>
#include <climits>
#include "Link_List9.h"
using namespace std;

node* newNode(int data)
{
    node* temp = new node();
    temp->info   = data;
    temp->left   = NULL;
    temp->right  = NULL;
    temp->rollNo = 0;
    temp->name   = "";
    temp->gpa    = 0.0f;
    return temp;
}

void func::insert(int data)
{
    node* temp = newNode(data);
    if (start == NULL)
    {
        start = temp;
        return;
    }
    node* cur  = start;
    node* prev = NULL;
    while (cur != NULL)
    {
        prev = cur;
        if (data <= cur->info)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (data <= prev->info)
        prev->left  = temp;
    else
        prev->right = temp;
    cout << "Inserted: " << data << endl;
}

node* minNode(node* root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

node* deleteHelper(node* root, int data, bool& deleted)
{
    if (root == NULL)
        return NULL;
    if (data < root->info)
        root->left  = deleteHelper(root->left,  data, deleted);
    else if (data > root->info)
        root->right = deleteHelper(root->right, data, deleted);
    else
    {
        deleted = true;
        if (root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        node* succ  = minNode(root->right);
        root->info  = succ->info;
        root->right = deleteHelper(root->right, succ->info, deleted);
    }
    return root;
}

void func::deleteNode(int data)
{
    bool deleted = false;
    start = deleteHelper(start, data, deleted);
    if (deleted)
        cout << "Deleted: " << data << endl;
    else
        cout << "Value " << data << " not found in BST." << endl;
}

void func::preorder_NR()
{
    if (start == NULL) { cout << "BST is empty." << endl; return; }
    stack<node*> st;
    st.push(start);
    cout << "Preorder (Non-Recursive): ";
    while (!st.empty())
    {
        node* cur = st.top(); st.pop();
        cout << cur->info << " ";
        if (cur->right) st.push(cur->right);
        if (cur->left)  st.push(cur->left);
    }
    cout << endl;
}

void func::inorder_NR()
{
    if (start == NULL) { cout << "BST is empty." << endl; return; }
    stack<node*> st;
    node* cur = start;
    cout << "Inorder (Non-Recursive): ";
    while (cur != NULL || !st.empty())
    {
        while (cur != NULL) { st.push(cur); cur = cur->left; }
        cur = st.top(); st.pop();
        cout << cur->info << " ";
        cur = cur->right;
    }
    cout << endl;
}

void func::postorder_NR()
{
    if (start == NULL) { cout << "BST is empty." << endl; return; }
    stack<node*> st1, st2;
    st1.push(start);
    while (!st1.empty())
    {
        node* cur = st1.top(); st1.pop();
        st2.push(cur);
        if (cur->left)  st1.push(cur->left);
        if (cur->right) st1.push(cur->right);
    }
    cout << "Postorder (Non-Recursive): ";
    while (!st2.empty())
    {
        cout << st2.top()->info << " ";
        st2.pop();
    }
    cout << endl;
}

node* insertReversedHelper(node* root, int data)
{
    if (root == NULL)
        return newNode(data);
    if (data > root->info)
        root->left  = insertReversedHelper(root->left,  data);
    else
        root->right = insertReversedHelper(root->right, data);
    return root;
}

void func::insert_reversed(int data)
{
    start = insertReversedHelper(start, data);
    cout << "Inserted in Reversed BST: " << data << endl;
}

void displayReversedHelper(node* root)
{
    if (root == NULL) return;
    displayReversedHelper(root->left);
    cout << root->info << " ";
    displayReversedHelper(root->right);
}

void func::display_reversed()
{
    if (start == NULL) { cout << "BST is empty." << endl; return; }
    cout << "Reversed BST Inorder (Descending): ";
    displayReversedHelper(start);
    cout << endl;
}

void func::insert_student(int roll, string sname, float sgpa)
{
    node* temp   = newNode(roll);
    temp->rollNo = roll;
    temp->name   = sname;
    temp->gpa    = sgpa;

    if (start == NULL)
    {
        start = temp;
        cout << "Student record inserted." << endl;
        return;
    }
    node* cur  = start;
    node* prev = NULL;
    while (cur != NULL)
    {
        prev = cur;
        if (roll < cur->rollNo)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (roll < prev->rollNo)
        prev->left  = temp;
    else
        prev->right = temp;
    cout << "Student record inserted." << endl;
}

void func::search_student(int roll)
{
    node* cur = start;
    while (cur != NULL)
    {
        if (roll == cur->rollNo)
        {
            cout << "---- Student Record ----" << endl;
            cout << "Roll No : " << cur->rollNo << endl;
            cout << "Name    : " << cur->name   << endl;
            cout << "GPA     : " << cur->gpa    << endl;
            cout << "------------------------" << endl;
            return;
        }
        cur = (roll < cur->rollNo) ? cur->left : cur->right;
    }
    cout << "Record with Roll No " << roll << " not found." << endl;
}

void displayLeavesHelper(node* root)
{
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->info << " ";
        return;
    }
    displayLeavesHelper(root->left);
    displayLeavesHelper(root->right);
}

void func::display_leaves()
{
    if (start == NULL) { cout << "BST is empty." << endl; return; }
    cout << "Leaf Nodes: ";
    displayLeavesHelper(start);
    cout << endl;
}

node* deleteLeavesHelper(node* root)
{
    if (root == NULL) return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    root->left  = deleteLeavesHelper(root->left);
    root->right = deleteLeavesHelper(root->right);
    return root;
}

void func::delete_leaves()
{
    if (start == NULL) { cout << "BST is empty." << endl; return; }
    start = deleteLeavesHelper(start);
    cout << "All leaf nodes deleted." << endl;
}

void func::inorder_successor(int data)
{
    node* succ  = NULL;
    node* cur   = start;
    bool  found = false;
    while (cur != NULL)
    {
        if (data < cur->info)
        {
            succ = cur;
            cur  = cur->left;
        }
        else if (data > cur->info)
        {
            cur = cur->right;
        }
        else
        {
            found = true;
            if (cur->right != NULL)
                succ = minNode(cur->right);
            break;
        }
    }
    if (!found)
        cout << "Value " << data << " not found in BST." << endl;
    else if (succ == NULL)
        cout << "No inorder successor for " << data << "." << endl;
    else
        cout << "Inorder Successor of " << data << " is: " << succ->info << endl;
}

void func::inorder_predecessor(int data)
{
    node* pred  = NULL;
    node* cur   = start;
    bool  found = false;
    while (cur != NULL)
    {
        if (data > cur->info)
        {
            pred = cur;
            cur  = cur->right;
        }
        else if (data < cur->info)
        {
            cur = cur->left;
        }
        else
        {
            found = true;
            if (cur->left != NULL)
            {
                node* tmp = cur->left;
                while (tmp->right != NULL)
                    tmp = tmp->right;
                pred = tmp;
            }
            break;
        }
    }
    if (!found)
        cout << "Value " << data << " not found in BST." << endl;
    else if (pred == NULL)
        cout << "No inorder predecessor for " << data << "." << endl;
    else
        cout << "Inorder Predecessor of " << data << " is: " << pred->info << endl;
}

void displayLevelHelper(node* root, int target, int current)
{
    if (root == NULL) return;
    if (current == target)
    {
        cout << root->info << " ";
        return;
    }
    displayLevelHelper(root->left,  target, current + 1);
    displayLevelHelper(root->right, target, current + 1);
}

void func::display_level(int level)
{
    if (start == NULL) { cout << "BST is empty." << endl; return; }
    cout << "Nodes at Level " << level << ": ";
    displayLevelHelper(start, level, 1);
    cout << endl;
}

void displayLeftHelper(node* root)
{
    if (root == NULL) return;
    if (root->left != NULL)
    {
        cout << root->left->info << " ";
        displayLeftHelper(root->left);
    }
    displayLeftHelper(root->right);
}

void func::display_left_nodes()
{
    if (start == NULL) { cout << "BST is empty." << endl; return; }
    cout << "Left Child Nodes: ";
    displayLeftHelper(start);
    cout << endl;
}

void largestAtLevelHelper(node* root, int target, int current, int& maxVal, bool& found)
{
    if (root == NULL) return;
    if (current == target)
    {
        found = true;
        if (root->info > maxVal)
            maxVal = root->info;
        return;
    }
    largestAtLevelHelper(root->left,  target, current + 1, maxVal, found);
    largestAtLevelHelper(root->right, target, current + 1, maxVal, found);
}

void func::largest_at_level(int level)
{
    if (start == NULL) { cout << "BST is empty." << endl; return; }
    int  maxVal = INT_MIN;
    bool found  = false;
    largestAtLevelHelper(start, level, 1, maxVal, found);
    if (found)
        cout << "Largest value at level " << level << ": " << maxVal << endl;
    else
        cout << "No nodes exist at level " << level << "." << endl;
}

void displayRightHelper(node* root)
{
    if (root == NULL) return;
    if (root->right != NULL)
    {
        cout << root->right->info << " ";
        displayRightHelper(root->right);
    }
    displayRightHelper(root->left);
}

void func::display_right_nodes()
{
    if (start == NULL) { cout << "BST is empty." << endl; return; }
    cout << "Right Child Nodes: ";
    displayRightHelper(start);
    cout << endl;
}

void func::display()
{
    if (start == NULL) { cout << "BST is empty." << endl; return; }
    cout << "BST Inorder: ";
    inorder_NR();
}

void return_menu()
{
    cout << "\nPress any key and Enter to return to menu...";
    int x; cin >> x;
}

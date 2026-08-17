#include <iostream>
#include "tree.h"
using namespace std;

void bst::find(int item, node **par, node **loc) {
    node *ptr, *ptrpar;

    if (root == NULL) {
        *loc = NULL;
        *par = NULL;
        return;
    }

    if (item == root->info) {
        *loc = root;
        *par = NULL;
        return;
    }

    if (item < root->info)
        ptr = root->lchild;
    else
        ptr = root->rchild;

    ptrpar = root;

    while (ptr != NULL) {
        if (item == ptr->info) {
            *loc = ptr;
            *par = ptrpar;
            return;
        }

        ptrpar = ptr;

        if (item < ptr->info)
            ptr = ptr->lchild;
        else
            ptr = ptr->rchild;
    }

    *loc = NULL;
    *par = ptrpar;
}


void bst::insert(int item) {
    node *tmp, *parent, *location;

    find(item, &parent, &location);

    if (location != NULL) {
        cout << "Item already present\n";
        return;
    }

    tmp = new node;
    tmp->info = item;
    tmp->lchild = NULL;
    tmp->rchild = NULL;

    if (parent == NULL)
        root = tmp;
    else if (item < parent->info)
        parent->lchild = tmp;
    else
        parent->rchild = tmp;
}


void bst::case_a(node *par, node *loc) {
    if (par == NULL)
        root = NULL;
    else if (loc == par->lchild)
        par->lchild = NULL;
    else
        par->rchild = NULL;
}


void bst::case_b(node *par, node *loc) {
    node *child;

    if (loc->lchild != NULL)
        child = loc->lchild;
    else
        child = loc->rchild;

    if (par == NULL)
        root = child;
    else if (loc == par->lchild)
        par->lchild = child;
    else
        par->rchild = child;
}


void bst::case_c(node *par, node *loc) {
    node *ptr, *ptrpar, *suc, *parsuc;

    ptrpar = loc;
    ptr = loc->rchild;

    while (ptr->lchild != NULL) {
        ptrpar = ptr;
        ptr = ptr->lchild;
    }

    suc = ptr;
    parsuc = ptrpar;

    if (suc->lchild == NULL && suc->rchild == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);

    if (par == NULL)
        root = suc;
    else if (loc == par->lchild)
        par->lchild = suc;
    else
        par->rchild = suc;

    suc->lchild = loc->lchild;
    suc->rchild = loc->rchild;
}


void bst::del(int item) {
    node *parent, *location;

    if (root == NULL) {
        cout << "Tree empty\n";
        return;
    }

    find(item, &parent, &location);

    if (location == NULL) {
        cout << "Item not present\n";
        return;
    }

    if (location->lchild == NULL && location->rchild == NULL)
        case_a(parent, location);
    else if (location->lchild != NULL && location->rchild == NULL)
        case_b(parent, location);
    else if (location->lchild == NULL && location->rchild != NULL)
        case_b(parent, location);
    else
        case_c(parent, location);

    delete location;
}


void bst::inorder(node *ptr) {
    if (ptr != NULL) {
        inorder(ptr->lchild);
        cout << ptr->info << " ";
        inorder(ptr->rchild);
    }
}

void bst::preorder(node *ptr) {
    if (ptr != NULL) {
        cout << ptr->info << " ";
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void bst::postorder(node *ptr) {
    if (ptr != NULL) {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        cout << ptr->info << " ";
    }
}


void bst::search(node *ptr, int item)
{
    if (ptr == NULL)
    {
        cout << "Item not found\n";
        return;
    }

    if (item == ptr->info)
        cout << "Item found\n";
    else if (item < ptr->info)
        search(ptr->lchild, item);
    else
        search(ptr->rchild, item);
}


void bst::display_level(node *ptr, int level)
{
    if (!ptr || level < 1) return;

    if (level == 1)
    {
        cout << ptr->info << " ";
        return;
    }

    display_level(ptr->lchild, level - 1);
    display_level(ptr->rchild, level - 1);
}


void bst::display_left_nodes(node *ptr)
{
    if (!ptr) return;

    if (ptr->lchild)
        cout << ptr->lchild->info << " ";

    display_left_nodes(ptr->lchild);
    display_left_nodes(ptr->rchild);
}


void bst::display_right_nodes(node *ptr)
{
    if (!ptr) return;

    if (ptr->rchild)
        cout << ptr->rchild->info << " ";

    display_right_nodes(ptr->lchild);
    display_right_nodes(ptr->rchild);
}


void bst::largest_at_level(node *ptr, int level)
{
    if (!ptr || level < 1)
        return;

    int maxVal = 0;

    findMaxAtLevel(ptr, level, maxVal);

    cout << "Largest value at level " << level << " = " << maxVal << endl;
}


void bst::findMaxAtLevel(node *ptr, int level, int &maxVal)
{
    if (!ptr)
        return;

    if (level == 1)
    {
        if (ptr->info > maxVal)
            maxVal = ptr->info;
    }
    else
    {
        findMaxAtLevel(ptr->lchild, level - 1, maxVal);
        findMaxAtLevel(ptr->rchild, level - 1, maxVal);
    }
}

void bst::display_terminal(node *ptr)
{
    if (!ptr) return;

    if (!ptr->lchild && !ptr->rchild)
        cout << ptr->info << " ";

    display_terminal(ptr->lchild);
    display_terminal(ptr->rchild);
}


void bst::delete_terminal(node *ptr)
{
    if (!ptr) return;

    if (!ptr->lchild && !ptr->rchild)
    {
        del(ptr->info);
        return;
    }

    delete_terminal(ptr->lchild);
    delete_terminal(ptr->rchild);
}


void bst::inorder_succ_pred(node *ptr, int item)
{
    node *curr = root, *succ = NULL, *pred = NULL;

    while (curr)
    {
        if (item < curr->info)
        {
            succ = curr;
            curr = curr->lchild;
        }
        else if (item > curr->info)
        {
            pred = curr;
            curr = curr->rchild;
        }
        else
        {
            if (curr->lchild)
            {
                node *tmp = curr->lchild;
                while (tmp->rchild) tmp = tmp->rchild;
                pred = tmp;
            }

            if (curr->rchild)
            {
                node *tmp = curr->rchild;
                while (tmp->lchild) tmp = tmp->lchild;
                succ = tmp;
            }
            break;
        }
    }

    if (pred) cout << "Predecessor: " << pred->info << endl;
    else cout << "No predecessor\n";

    if (succ) cout << "Successor: " << succ->info << endl;
    else cout << "No successor\n";
}


void bst::insert_reverse(int item)
{
    node *temp = new node();
    temp->info = item;
    temp->lchild = temp->rchild = NULL;

    if (root == NULL)
    {
        root = temp;
        return;
    }

    node *curr = root, *par = NULL;

    while (curr)
    {
        par = curr;
        if (item > curr->info)
            curr = curr->lchild;
        else
            curr = curr->rchild;
    }

    if (item > par->info)
        par->lchild = temp;
    else
        par->rchild = temp;
}


void bst::inorder_reverse(node *ptr)
{
    if (ptr)
    {
        inorder_reverse(ptr->lchild);
        cout << ptr->info << " ";
        inorder_reverse(ptr->rchild);
    }
}


void bst::nrpreorder()
{
    node *curr = root;

    while (curr != NULL)
    {
        if (curr->lchild == NULL)
        {
            cout << curr->info << " ";
            curr = curr->rchild;
        }
        else
        {
            node *pre = curr->lchild;

            while (pre->rchild != NULL && pre->rchild != curr)
                pre = pre->rchild;

            if (pre->rchild == NULL)
            {
                cout << curr->info << " ";
                pre->rchild = curr;
                curr = curr->lchild;
            }
            else
            {
                pre->rchild = NULL;
                curr = curr->rchild;
            }
        }
    }
}


void bst::nrinorder()
{
    node *curr = root;

    while (curr != NULL)
    {
        if (curr->lchild == NULL)
        {
            cout << curr->info << " ";
            curr = curr->rchild;
        }
        else
        {
            node *pre = curr->lchild;

            while (pre->rchild != NULL && pre->rchild != curr)
                pre = pre->rchild;

            if (pre->rchild == NULL)
            {
                pre->rchild = curr;
                curr = curr->lchild;
            }
            else
            {
                pre->rchild = NULL;
                cout << curr->info << " ";
                curr = curr->rchild;
            }
        }
    }
}


void bst::nrpostorder()
{
    node *dummy = new node();
    dummy->lchild = root;
    dummy->rchild = NULL;

    node *curr = dummy;

    while (curr != NULL)
    {
        if (curr->lchild == NULL)
        {
            curr = curr->rchild;
        }
        else
        {
            node *pre = curr->lchild;

            while (pre->rchild != NULL && pre->rchild != curr)
                pre = pre->rchild;

            if (pre->rchild == NULL)
            {
                pre->rchild = curr;
                curr = curr->lchild;
            }
            else
            {
                printReverse(curr->lchild, pre);
                pre->rchild = NULL;
                curr = curr->rchild;
            }
        }
    }
}


void bst::printReverse(node *from, node *to)
{
    reversePath(from, to);

    node *temp = to;
    while (true)
    {
        cout << temp->info << " ";
        if (temp == from)
            break;
        temp = temp->rchild;
    }

    reversePath(to, from);
}


void bst::reversePath(node *start, node *end)
{
    if (start == end)
        return;

    node *x = start;
    node *y = start->rchild;
    node *z;

    while (x != end)
    {
        z = y->rchild;
        y->rchild = x;
        x = y;
        y = z;
    }
}
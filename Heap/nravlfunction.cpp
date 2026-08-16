
#include <iostream>
#include <stack>
#include "nravltree.h"

using namespace std;

node* bst::insertAVL(node *pptr, int info, bool &ht_inc)
{
    node *aptr, *bptr;

    if (pptr == NULL)
    {
        pptr = new node;

        pptr->info = info;
        pptr->balance = 0;

        pptr->lchild = NULL;
        pptr->rchild = NULL;

        ht_inc = true;

        return pptr;
    }

    if (info < pptr->info)
    {
        pptr->lchild = insertAVL(pptr->lchild, info, ht_inc);
    }

    else if (info > pptr->info)
    {
        pptr->rchild = insertAVL(pptr->rchild, info, ht_inc);
    }

    return pptr;
}

node* bst::deleteAVL(node *pptr, int info, bool &ht_dec)
{
    if (pptr == NULL)
        return NULL;

    if (info < pptr->info)
    {
        pptr->lchild = deleteAVL(pptr->lchild, info, ht_dec);
    }

    else if (info > pptr->info)
    {
        pptr->rchild = deleteAVL(pptr->rchild, info, ht_dec);
    }

    else
    {
        if (pptr->lchild == NULL)
        {
            node *temp = pptr->rchild;
            delete pptr;
            return temp;
        }

        else if (pptr->rchild == NULL)
        {
            node *temp = pptr->lchild;
            delete pptr;
            return temp;
        }
    }

    return pptr;
}

void bst::inorder(node *ptr)
{
    if (ptr)
    {
        inorder(ptr->lchild);
        cout << ptr->info << " ";
        inorder(ptr->rchild);
    }
}

void bst::preorder(node *ptr)
{
    if (ptr)
    {
        cout << ptr->info << " ";
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void bst::postorder(node *ptr)
{
    if (ptr)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        cout << ptr->info << " ";
    }
}

void bst::search(node *ptr, int item)
{
    while (ptr)
    {
        if (item == ptr->info)
        {
            cout << "Found\n";
            return;
        }

        else if (item < ptr->info)
        {
            ptr = ptr->lchild;
        }

        else
        {
            ptr = ptr->rchild;
        }
    }

    cout << "Not Found\n";
}

void bst::nrpreorder()
{
    if (!root)
        return;

    stack<node*> st;
    st.push(root);

    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();

        cout << temp->info << " ";

        if (temp->rchild)
            st.push(temp->rchild);

        if (temp->lchild)
            st.push(temp->lchild);
    }
}

void bst::nrinorder()
{
    stack<node*> st;
    node *curr = root;

    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->lchild;
        }

        curr = st.top();
        st.pop();

        cout << curr->info << " ";

        curr = curr->rchild;
    }
}

void bst::nrpostorder()
{
    if (!root)
        return;

    stack<node*> s1, s2;

    s1.push(root);

    while (!s1.empty())
    {
        node *temp = s1.top();
        s1.pop();

        s2.push(temp);

        if (temp->lchild)
            s1.push(temp->lchild);

        if (temp->rchild)
            s1.push(temp->rchild);
    }

    while (!s2.empty())
    {
        cout << s2.top()->info << " ";
        s2.pop();
    }
}

student* bst::insert_student(student *pptr,
                             int roll,
                             string name,
                             float marks,
                             bool &ht_inc)
{
    if (pptr == NULL)
    {
        pptr = new student;

        pptr->roll = roll;
        pptr->name = name;
        pptr->marks = marks;

        pptr->lchild = NULL;
        pptr->rchild = NULL;

        return pptr;
    }

    if (roll < pptr->roll)
    {
        pptr->lchild =
        insert_student(pptr->lchild,
                       roll,
                       name,
                       marks,
                       ht_inc);
    }

    else if (roll > pptr->roll)
    {
        pptr->rchild =
        insert_student(pptr->rchild,
                       roll,
                       name,
                       marks,
                       ht_inc);
    }

    return pptr;
}

void bst::search_student(int roll)
{
    student *curr = sroot;

    while (curr)
    {
        if (roll == curr->roll)
        {
            cout << "Roll: " << curr->roll << endl;
            cout << "Name: " << curr->name << endl;
            cout << "Marks: " << curr->marks << endl;

            return;
        }

        else if (roll < curr->roll)
        {
            curr = curr->lchild;
        }

        else
        {
            curr = curr->rchild;
        }
    }

    cout << "Student not found\n";
}

// ======================================================
// NEW FUNCTIONS
// ======================================================

void bst::node_type_nonrecursive()
{
    if (!root)
        return;

    stack<node*> st;
    st.push(root);

    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();

        cout << temp->info << " : ";

        if (!temp->lchild && !temp->rchild)
            cout << "Leaf Node";

        else if ((temp->lchild && !temp->rchild) ||
                 (!temp->lchild && temp->rchild))
            cout << "One Child Node";

        else
            cout << "Two Children Node";

        cout << endl;

        if (temp->rchild)
            st.push(temp->rchild);

        if (temp->lchild)
            st.push(temp->lchild);
    }
}

void bst::root_right_left()
{
    if (!root)
        return;

    stack<node*> st;
    st.push(root);

    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();

        cout << temp->info << " ";

        if (temp->lchild)
            st.push(temp->lchild);

        if (temp->rchild)
            st.push(temp->rchild);
    }
}

void bst::right_root_left()
{
    stack<node*> st;
    node *curr = root;

    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->rchild;
        }

        curr = st.top();
        st.pop();

        cout << curr->info << " ";

        curr = curr->lchild;
    }
}

void bst::children_sum()
{
    if (!root)
        return;

    stack<node*> s1, s2;

    s1.push(root);

    while (!s1.empty())
    {
        node *temp = s1.top();
        s1.pop();

        s2.push(temp);

        if (temp->lchild)
            s1.push(temp->lchild);

        if (temp->rchild)
            s1.push(temp->rchild);
    }

    while (!s2.empty())
    {
        node *temp = s2.top();
        s2.pop();

        int left = 0;
        int right = 0;

        if (temp->lchild)
            left = temp->lchild->info;

        if (temp->rchild)
            right = temp->rchild->info;

        if (temp->lchild || temp->rchild)
        {
            temp->info = left + right;
        }
    }

    cout << "Updated Tree: ";
    inorder(root);
    cout << endl;
}

int bst::height(node *ptr)
{
    if (!ptr)
        return 0;

    int lh = height(ptr->lchild);
    int rh = height(ptr->rchild);

    if (lh > rh)
        return lh + 1;

    return rh + 1;
}

void bst::balance_factor(int item)
{
    node *curr = root;

    while (curr)
    {
        if (item == curr->info)
        {
            int lh = height(curr->lchild);
            int rh = height(curr->rchild);

            cout << "Balance Factor = "
                 << lh - rh << endl;

            return;
        }

        else if (item < curr->info)
        {
            curr = curr->lchild;
        }

        else
        {
            curr = curr->rchild;
        }
    }

    cout << "Node not found\n";
}
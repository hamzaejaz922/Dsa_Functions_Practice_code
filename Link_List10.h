#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, int value);
    void displayLevel(Node* root, int level);
    void displayLeftNodes(Node* root);
    void displayRightNodes(Node* root);
    void largestAtLevel(Node* root, int level, int &maxVal);

public:
    BST();

    void insert(int value);
    void showLevel(int level);
    void showLeftNodes();
    void showRightNodes();
    void showLargestAtLevel(int level);
};

#endif
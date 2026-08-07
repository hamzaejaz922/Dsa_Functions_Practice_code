#include "Link_List10.h"

BST::BST() {
    root = NULL;
}

// Insert node
Node* BST::insert(Node* root, int value) {
    if (root == NULL) {
        Node* temp = new Node();
        temp->data = value;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void BST::insert(int value) {
    root = insert(root, value);
}

// Q7: Display nodes at given level
void BST::displayLevel(Node* root, int level) {
    if (root == NULL)
        return;

    if (level == 0)
        cout << root->data << " ";
    else {
        displayLevel(root->left, level - 1);
        displayLevel(root->right, level - 1);
    }
}

void BST::showLevel(int level) {
    displayLevel(root, level);
    cout << endl;
}

// Q8: Display left nodes
void BST::displayLeftNodes(Node* root) {
    if (root == NULL)
        return;

    if (root->left != NULL)
        cout << root->left->data << " ";

    displayLeftNodes(root->left);
    displayLeftNodes(root->right);
}

void BST::showLeftNodes() {
    displayLeftNodes(root);
    cout << endl;
}

// Q10: Display right nodes
void BST::displayRightNodes(Node* root) {
    if (root == NULL)
        return;

    if (root->right != NULL)
        cout << root->right->data << " ";

    displayRightNodes(root->left);
    displayRightNodes(root->right);
}

void BST::showRightNodes() {
    displayRightNodes(root);
    cout << endl;
}

// Q9: Largest value at given level
void BST::largestAtLevel(Node* root, int level, int &maxVal) {
    if (root == NULL)
        return;

    if (level == 0) {
        if (root->data > maxVal)
            maxVal = root->data;
    } else {
        largestAtLevel(root->left, level - 1, maxVal);
        largestAtLevel(root->right, level - 1, maxVal);
    }
}

void BST::showLargestAtLevel(int level) {
    int maxVal = -99999;
    largestAtLevel(root, level, maxVal);

    if (maxVal == -99999)
        cout << "Level not found\n";
    else
        cout << "Largest value: " << maxVal << endl;
}
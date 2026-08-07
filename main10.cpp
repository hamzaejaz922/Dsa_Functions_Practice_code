#include "Link_List10.h"

int main() {
    BST tree;

    // Insert values
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    int level;

    // Q7
    cout << "Enter level to display: ";
    cin >> level;
    cout << "Nodes at level: ";
    tree.showLevel(level);

    // Q8
    cout << "Left nodes: ";
    tree.showLeftNodes();

    // Q9
    cout << "Enter level to find largest value: ";
    cin >> level;
    tree.showLargestAtLevel(level);

    // Q10
    cout << "Right nodes: ";
    tree.showRightNodes();

    return 0;
}
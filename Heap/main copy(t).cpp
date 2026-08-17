#include <iostream>
#include "tree.h"
using namespace std;

int main()
{
    int choice, num, level;

    bst t;

    while (true)
    {
        cout << "\n===== BST MENU =====";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Inorder Traversal";
        cout << "\n4. Preorder Traversal";
        cout << "\n5. Postorder Traversal";
        cout << "\n6. Search";
        cout << "\n7. Display Left Nodes";
        cout << "\n8. Display Right Nodes";
        cout << "\n9. Largest at Level";
        cout << "\n10. Display Terminal Nodes";
        cout << "\n11. Delete Terminal Nodes";
        cout << "\n12. Inorder Successor & Predecessor";
        cout << "\n13. Reverse Insert";
        cout << "\n14. Reverse Inorder Traversal";
        cout << "\n15. Non-Recursive Preorder";
        cout << "\n16. Non-Recursive Inorder";
        cout << "\n17. Non-Recursive Postorder";
        cout << "\n18. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number: ";
            cin >> num;
            t.insert(num);
            break;

        case 2:
            cout << "Enter number: ";
            cin >> num;
            t.del(num);
            break;

        case 3:
            cout << "Inorder: ";
            t.inorder(t.root);
            cout << endl;
            break;

        case 4:
            cout << "Preorder: ";
            t.preorder(t.root);
            cout << endl;
            break;

        case 5:
            cout << "Postorder: ";
            t.postorder(t.root);
            cout << endl;
            break;

        case 6:
            cout << "Enter number to search: ";
            cin >> num;
            t.search(t.root, num);
            break;

        case 7:
            cout << "Left Nodes: ";
            t.display_left_nodes(t.root);
            cout << endl;
            break;

        case 8:
            cout << "Right Nodes: ";
            t.display_right_nodes(t.root);
            cout << endl;
            break;

        case 9:
            cout << "Enter level: ";
            cin >> level;
            t.largest_at_level(t.root, level);
            break;

        case 10:
            cout << "Terminal Nodes: ";
            t.display_terminal(t.root);
            cout << endl;
            break;

        case 11:
            t.delete_terminal(t.root);
            cout << "Terminal nodes deleted\n";
            break;

        case 12:
            cout << "Enter number: ";
            cin >> num;
            t.inorder_succ_pred(t.root, num);
            break;

        case 13:
            cout << "Enter number: ";
            cin >> num;
            t.insert_reverse(num);
            break;

        case 14:
            cout << "Reverse Inorder: ";
            t.inorder_reverse(t.root);
            cout << endl;
            break;

        case 15:
            cout << "Non-Recursive Preorder: ";
            t.nrpreorder();
            cout << endl;
            break;

        case 16:
            cout << "Non-Recursive Inorder: ";
            t.nrinorder();
            cout << endl;
            break;

        case 17:
            cout << "Non-Recursive Postorder: ";
            t.nrpostorder();
            cout << endl;
            break;

        case 18:
            exit(0);

        default:
            cout << "Invalid choice\n";
        }
    }
}

#include <iostream>
#include "nravltree.h"
using namespace std;

int main()
{
    int choice, num, level;
    int roll;
    string name;
    float marks;

    bst t;
    bst f;

    bool ht_inc = false;
    bool ht_dec = false;

    while (true)
    {
        cout << "\n===== AVL/BST MENU =====";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Inorder";
        cout << "\n4. Preorder";
        cout << "\n5. Postorder";
        cout << "\n6. Search";
        cout << "\n7. Left Nodes";
        cout << "\n8. Right Nodes";
        cout << "\n9. Largest at Level";
        cout << "\n10. Terminal Nodes";
        cout << "\n11. Delete Terminal Nodes";
        cout << "\n12. Succ & Pred";
        cout << "\n13. Reverse Insert";
        cout << "\n14. Reverse Inorder";
        cout << "\n15. NR Preorder";
        cout << "\n16. NR Inorder";
        cout << "\n17. NR Postorder";
        cout << "\n18. Insert Student";
        cout << "\n19. Search Student";
        cout << "\n20. Node Type";
        cout << "\n21. Root Right Left";
        cout << "\n22. Right Root Left";
        cout << "\n23. Sum of Children";
        cout << "\n24. Balance Factor";
        cout << "\n25. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number: ";
            cin >> num;
            ht_inc = false;
            t.root = t.insertAVL(t.root, num, ht_inc);
            break;

        case 2:
            cout << "Enter number: ";
            cin >> num;
            ht_dec = false;
            t.root = t.deleteAVL(t.root, num, ht_dec);
            break;

        case 3:
            t.inorder(t.root);
            cout << endl;
            break;

        case 4:
            t.preorder(t.root);
            cout << endl;
            break;

        case 5:
            t.postorder(t.root);
            cout << endl;
            break;

        case 6:
            cout << "Enter number: ";
            cin >> num;
            t.search(t.root, num);
            break;

        case 18:
            cout << "Roll: ";
            cin >> roll;
            cin.ignore();

            cout << "Name: ";
            getline(cin, name);

            cout << "Marks: ";
            cin >> marks;

            ht_inc = false;
            f.sroot = f.insert_student(f.sroot, roll, name, marks, ht_inc);
            break;

        case 19:
            cout << "Roll: ";
            cin >> roll;
            f.search_student(roll);
            break;

        case 20:
            t.node_type_nonrecursive();
            break;

        case 21:
            t.root_right_left();
            cout << endl;
            break;

        case 22:
            t.right_root_left();
            cout << endl;
            break;

        case 23:
            t.children_sum();
            break;

        case 24:
            cout << "Enter node value: ";
            cin >> num;
            t.balance_factor(num);
            break;

        case 25:
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}